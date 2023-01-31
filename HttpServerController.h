#ifndef HTTPSERVERCONTROLLER_H
#define HTTPSERVERCONTROLLER_H

#include <QtNetwork>
#include "Config.h"

class HttpServerController
{
public:
    HttpServerController();
    QJsonDocument processRequest(const QString& ticket_id, ClientConfig::Method method);
private:
    QString m_server_url;
};

#endif // HTTPSERVERCONTROLLER_H
