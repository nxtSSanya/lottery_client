#include <QCoreApplication>
#include <QtNetwork>
#include <iostream>
#include <string>

#include "JsonParser.h"
#include "HttpServerController.h"
#include "Config.h"
#include "ClientView.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ClientView view;
    while(1) {
        std::string qq;
        int method = 2;
        std::cin >> qq >> method;
        QString ticket_id = QString::fromStdString(qq);
        view.make_request(method, ticket_id);

    }
    return a.exec();
}
