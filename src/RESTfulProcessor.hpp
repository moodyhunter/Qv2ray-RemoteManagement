#pragma once

#include "plugin-interface/QvPluginInterface.hpp"
#include "plugin-interface/connections/ConnectionsBase.hpp"
#include "qhttpserver.h"

class RESTfulProcessor
{
  public:
    RESTfulProcessor();
    virtual ~RESTfulProcessor();
    void SetServer(QHttpServer *router);

  private:
    QHttpServer *m_server;
    Qv2rayPlugin::connections::IConnectionManager *m_manager;
};
