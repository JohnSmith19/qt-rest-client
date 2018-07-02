#include "asioclient.h"
#include <QDebug>

AsioClient::AsioClient():
    work(new boost::asio::io_service::work(ioservice)),
    resolver(ioservice),
    socket(ioservice)
{
    worker = std::thread([&](){
        ioservice.run();
    });
}

AsioClient::~AsioClient()
{
    ioservice.stop();
    worker.join();
    work.reset();
}

void AsioClient::Get(const QString &url, const QString &p)
{
    server = url.toStdString();
    path = p.toStdString();
    // 1. url -> end point resolve
    boost::asio::ip::tcp::resolver::query query(server, "http");
    resolver.async_resolve(query, boost::bind(
                               &AsioClient::handle_resolve,
                               this, boost::asio::placeholders::error,
                               boost::asio::placeholders::iterator));
    // 2. connect
    // 3. send
    // 4. recv

}

void AsioClient::handle_resolve(const boost::system::error_code &err,
                                boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
{
    if(!err) {
       boost::asio::ip::tcp::endpoint ep = *endpoint_iterator;

       qDebug() << ep.address().to_string().c_str() << endl;

       socket.async_connect(*endpoint_iterator, boost::bind(&AsioClient::handle_connect, this,
                                                             boost::asio::placeholders::error,
                                                             endpoint_iterator));
    }
}

void AsioClient::handle_connect(const boost::system::error_code &err,
                                boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
{
    if(!err) { // success
        std::ostream os(&requestbuf);

        // make http request header
        os << "GET " << path << " HTTP/1.0\r\n";
        os << "Host: " << server << "\r\n";
        os << "Accept: */*\r\n";
        os << "Connection: close\r\n\r\n";

        // write
        boost::asio::async_write(socket, requestbuf, boost::bind(&AsioClient::handle_write, this,
                                                                 boost::asio::placeholders::error));
    } else { // fail
        qDebug() << err.message().c_str() << endl;
    }
}

void AsioClient::handle_write(const boost::system::error_code &err)
{
    // recv
    if(!err) {
        boost::asio::async_read_until(socket, responsebuf, "\r\n",
                                      boost::bind(&AsioClient::handle_read_line, this, boost::asio::placeholders::error));
    } else {
        qDebug() << "hadle_write error: " << err.message().c_str() << endl;
    }
}

void AsioClient::handle_read_line(const boost::system::error_code &err)
{
    if(!err) {
        std::istream is(&responsebuf);

        std::string http_versoin;
        unsigned int status_code;
        std::string message;

        is >> http_versoin;
        is >> status_code;
        std::getline(is, message);

        // 1. error http_version HTTP/
        // 2. status_code != 200
        if(status_code != 200) {
            return;
        }
    } else {

    }
}
