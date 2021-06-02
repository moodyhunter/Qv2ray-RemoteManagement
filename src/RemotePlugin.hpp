#pragma once

#include "QvPluginInterface.hpp"
#include "RESTfulProcessor.hpp"
#include "qhttpserver.h"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

class RemoteManagementPlugin
    : public QObject
    , Qv2rayInterface
{
    Q_INTERFACES(Qv2rayPlugin::Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT

  public:
    const QvPluginMetadata GetMetadata() const override
    {
        return { "Remote Management",                                                              //
                 "Moody",                                                                          //
                 "Qv2ray remote management using RESTful API and QtRemoteObjects over websocket.", //
                 "qv2ray-remote",                                                                  //
                 "https://github.com/moodyhunter/Qv2ray-RemoteManagement",                         //
                 {} };
    }
    ~RemoteManagementPlugin(){};
    bool InitializePlugin() override;
    void SettingsUpdated() override{};
    QHttpServer *HttpServer()
    {
        return server;
    }

  private:
    QHttpServer *server;
    RESTfulProcessor processor;

  signals:
    void PluginLog(QString) const override;
    void PluginErrorMessageBox(QString, QString) const override;
};
