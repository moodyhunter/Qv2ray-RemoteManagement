#include "RemotePlugin.hpp"

bool RemoteManagementPlugin::InitializePlugin()
{
    const auto port = m_Settings["listenPort"].toInt(8089);
    const auto address = m_Settings["listenAddress"].toString("127.0.0.1");
    server = new QHttpServer(this);
    server->listen(QHostAddress(address), port);
    processor.Initialize(server, ConnectionManager());
    return true;
}
