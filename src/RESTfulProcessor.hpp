#pragma once

#include "plugin-interface/QvPluginInterface.hpp"
#include "plugin-interface/connections/ConnectionsBase.hpp"
#include "qhttpserver.h"

namespace details
{
    Q_NAMESPACE
    enum class Result
    {
        OK,
        INVALID_TOKEN
    };
    Q_ENUM_NS(Result)
} // namespace details

class RESTfulProcessor
{
  public:
    RESTfulProcessor();
    virtual ~RESTfulProcessor();
    void Initialize(QHttpServer *server, Qv2rayPlugin::connections::IConnectionManager *manager);

  private:
    static QJsonObject makeResponce(details::Result r, QJsonValue v = {})
    {
        const auto object = QJsonObject{ { "Message", QMetaEnum::fromType<details::Result>().valueToKey((int) r) }, { "Code", (int) r }, { "Responce", v } };
        return object;
    }

  private:
    QHttpServer *m_server;
    Qv2rayPlugin::connections::IConnectionManager *m_manager;
    QString token = "114514";
};

Q_DECLARE_METATYPE(QRegularExpressionMatch)
