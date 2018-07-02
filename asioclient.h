#ifndef ASIOCLIENT_H
#define ASIOCLIENT_H
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <QObject>
#include <QString>
#include <memory>
#include <thread>


class AsioClient
{
public:
    AsioClient();
    virtual ~AsioClient();
    // http://127.0.0.1/data/
    void Get(const QString& url, const QString& path);

    void handle_resolve(const boost::system::error_code& err,
                        boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
private:
    boost::asio::io_service ioservice;
    std::shared_ptr<boost::asio::io_service::work> work;
    std::thread worker;

    std::string server, path;
    boost::asio::ip::tcp::resolver resolver;
};

#endif // ASIOCLIENT_H
