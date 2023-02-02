#include "JsonParser.h"
#include "HttpServerController.h"
#include "ConfigReader.h"
#include <iostream>

QString list_tickets_url;
QString find_ticket_url;
QString pay_for_ticket_url;
QString sell_ticket_url;

bool isServerOnline = true;

QJsonDocument getListOfTickets();
QJsonDocument findTicket(const QString &ticket_id);
QJsonDocument sellTicket(const QString &ticket_id);
QJsonDocument payForTicket(const QString &ticket_id);

HttpServerController::HttpServerController()
{
    ConfigReader reader(config_file_path);
    QString server_address = reader.getServerAddress();
    list_tickets_url = "http://" + server_address + "/tickets";
    find_ticket_url = "http://" + server_address + "/tickets/";
    pay_for_ticket_url = "http://" + server_address + "/tickets/pay/";
    sell_ticket_url = "http://" + server_address + "/tickets/sell/";
}

QJsonDocument HttpServerController::processRequest(const QString &ticket_id, ClientConfig::Method method)
{
    JsonParser json_parser;
    if(method == ClientConfig::Method::LIST_TICKETS) {
        auto server_reply = getListOfTickets();

        return server_reply;
    }
    else if(method == ClientConfig::Method::FIND_TICKET) {
        auto server_reply = findTicket(ticket_id);

        return server_reply;
    }
    else if(method == ClientConfig::Method::SELL_TICKET) {
        auto server_reply = sellTicket(ticket_id);

        return server_reply;
    }
    else if(method == ClientConfig::Method::PAY_TICKET) {
        auto server_reply = payForTicket(ticket_id);

        return server_reply;
    }
    else return QJsonDocument();
}

QJsonDocument getListOfTickets() {
    QNetworkAccessManager nam;
    QString current_addr = list_tickets_url;
    QUrl list_tickets_url_local = QUrl(current_addr);

    QNetworkRequest request(list_tickets_url_local);

    QNetworkReply *reply = nam.get(request);

    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    if(reply->error() != reply->NoError) {
        isServerOnline = false;
    }
    QJsonDocument json = QJsonDocument::fromJson(response_data);

    reply->deleteLater();

    return json;
}

QJsonDocument findTicket(const QString& ticket_id) {
    QNetworkAccessManager nam;
    QString current_addr = find_ticket_url + ticket_id;
    QUrl list_tickets_url_local = QUrl(current_addr);

    QNetworkRequest request(list_tickets_url_local);

    QNetworkReply *reply = nam.get(request);

    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    if(reply->error() != reply->NoError) {
        isServerOnline = false;
    }
    QJsonDocument json = QJsonDocument::fromJson(response_data);

    reply->deleteLater();

    return json;
}

QJsonDocument sellTicket(const QString& ticket_id) {
    QNetworkAccessManager nam;
    QString current_addr = sell_ticket_url + ticket_id;
    QUrl list_tickets_url_local = QUrl(current_addr);

    QNetworkRequest request(list_tickets_url_local);

    QNetworkReply *reply = nam.get(request);

    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    if(reply->error() != reply->NoError) {
        isServerOnline = false;
    }
    QJsonDocument json = QJsonDocument::fromJson(response_data);

    reply->deleteLater();

    return json;
}

QJsonDocument payForTicket(const QString& ticket_id) {
    QNetworkAccessManager nam;
    QString current_addr = pay_for_ticket_url + ticket_id;
    QUrl list_tickets_url_local = QUrl(current_addr);

    QNetworkRequest request(list_tickets_url_local);

    QNetworkReply *reply = nam.get(request);

    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    if(reply->error() != reply->NoError) {
        isServerOnline = false;
    }
    QJsonDocument json = QJsonDocument::fromJson(response_data);

    reply->deleteLater();

    return json;
}
