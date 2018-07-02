#include "asioclient.h"

AsioClient::AsioClient():
    work(new boost::asio::io_service::work(ioservice))
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
