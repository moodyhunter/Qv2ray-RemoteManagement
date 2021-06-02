#include "RESTfulProcessor.hpp"

#include "qhttpserver.h"

RESTfulProcessor::RESTfulProcessor()
{
    m_manager = Qv2rayPlugin::PluginInstance->ConnectionManager();
}

RESTfulProcessor::~RESTfulProcessor()
{
}

void RESTfulProcessor::SetServer(QHttpServer *s)
{
    this->m_server = s;
    s->route("/", []() { return "Hello world"; });
}
