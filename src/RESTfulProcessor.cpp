#include "RESTfulProcessor.hpp"

#include "qhttpserver.h"

using namespace details;

#define TokenCheck                                                                                                                                                       \
    do                                                                                                                                                                   \
    {                                                                                                                                                                    \
        if (request.headers().value("Qv2ray-Remote-Token") != token && request.query().queryItemValue("token") != token)                                                 \
            return makeResponce(Result::INVALID_TOKEN);                                                                                                                  \
    } while (0)

RESTfulProcessor::RESTfulProcessor()
{
    m_manager = Qv2rayPlugin::PluginInstance->ConnectionManager();
}

RESTfulProcessor::~RESTfulProcessor()
{
}

void RESTfulProcessor::Initialize(QHttpServer *s, Qv2rayPlugin::connections::IConnectionManager *manager)
{
    this->m_server = s;
    this->m_manager = manager;
    s->route("/", []() { return makeResponce(Result::OK, "See https://github.com/moodyhunter/Qv2ray-RemoteManagement"); });

    s->route("/me/address", [this](const QHttpServerRequest &request) {
        TokenCheck;
        return makeResponce(Result::OK, request.remoteAddress().toString());
    });

    s->route("/plugin", [this](const QHttpServerRequest &request) {
        TokenCheck;
        return makeResponce(Result::OK, "Qv2ray Remote Management Plugin");
    });

    s->route("/groups", [this](const QHttpServerRequest &request) {
        TokenCheck;
        return makeResponce(Result::OK, JsonStructHelper::Serialize(m_manager->AllGroups()));
    });

    s->route("/connections", [this](const QHttpServerRequest &request) {
        TokenCheck;
        return makeResponce(Result::OK, JsonStructHelper::Serialize(m_manager->GetConnections()));
    });

    s->route("/connections/<arg>", [this](const QString &gid, const QHttpServerRequest &request) {
        TokenCheck;
        return makeResponce(Result::OK, JsonStructHelper::Serialize(m_manager->GetConnections(GroupId(gid))));
    });
}
