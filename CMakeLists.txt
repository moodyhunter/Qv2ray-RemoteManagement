project(RemoteManagement)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Network WebSockets RemoteObjects REQUIRED)


set(HTTP_SERVER_SOURCES
    3rdparty/http-parser/http_parser.c
    3rdparty/http-parser/http_parser.h
    src/qthttpserver/qabstracthttpserver.cpp
    src/qthttpserver/qabstracthttpserver.h
    src/qthttpserver/qabstracthttpserver_p.h
    src/qthttpserver/qhttpserver.cpp
    src/qthttpserver/qhttpserver.h
    src/qthttpserver/qhttpserver_p.h
    src/qthttpserver/qhttpserverliterals.cpp
    src/qthttpserver/qhttpserverliterals_p.h
    src/qthttpserver/qhttpserverrequest.cpp
    src/qthttpserver/qhttpserverrequest.h
    src/qthttpserver/qhttpserverrequest_p.h
    src/qthttpserver/qhttpserverresponder.cpp
    src/qthttpserver/qhttpserverresponder.h
    src/qthttpserver/qhttpserverresponder_p.h
    src/qthttpserver/qhttpserverresponse.cpp
    src/qthttpserver/qhttpserverresponse.h
    src/qthttpserver/qhttpserverresponse_p.h
    src/qthttpserver/qhttpserverrouter.cpp
    src/qthttpserver/qhttpserverrouter.h
    src/qthttpserver/qhttpserverrouter_p.h
    src/qthttpserver/qhttpserverrouterrule.cpp
    src/qthttpserver/qhttpserverrouterrule.h
    src/qthttpserver/qhttpserverrouterrule_p.h
    src/qthttpserver/qhttpserverrouterviewtraits.h
    src/qthttpserver/qhttpserverviewtraits.h
    src/qthttpserver/qhttpserverviewtraits_impl.h
    src/qthttpserver/qthttpserverglobal.h
    src/qthttpserver/qsslserver.cpp
    src/qthttpserver/qsslserver.h
    src/qthttpserver/qsslserver_p.h
    src/qthttpserver/qtsslserverglobal.h)

include(plugin-interface/QvPluginInterface.cmake)

qt6_add_library(RemoteManagementPlugin
    src/RemotePlugin.hpp
    src/RemotePlugin.cpp
    src/RESTfulProcessor.cpp
    src/RESTfulProcessor.hpp
    ${HTTP_SERVER_SOURCES})

qv2ray_configure_plugin(RemoteManagementPlugin)

target_include_directories(RemoteManagementPlugin PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/3rdparty/
    ${CMAKE_CURRENT_LIST_DIR}/src/QHttpServer)

target_link_libraries(RemoteManagementPlugin  Qt::Core Qt::CorePrivate Qt::Network Qt::NetworkPrivate Qt::WebSockets)
target_include_directories(RemoteManagementPlugin PRIVATE src/qthttpserver)
