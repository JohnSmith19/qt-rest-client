#ifndef ASIOCLIENT_H
#define ASIOCLIENT_H
#include <boost/asio.hpp>

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

private:
    boost::asio::io_service ioservice;
    std::shared_ptr<boost::asio::io_service::work> work;
    std::thread worker;
};

#endif // ASIOCLIENT_H
