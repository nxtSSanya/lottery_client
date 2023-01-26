#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <vector>
#include <Config.h>

class JsonParser
{
public:
    JsonParser();

    std::vector<QString> parseArray(const QJsonDocument& input);
    ClientConfig::find_ticket_info parseTicketInfo(const QJsonDocument& input);
    ClientConfig::sell_ticket_info parseSellTicket(const QJsonDocument& input);
    ClientConfig::pay_ticket_info parsePayTicket(const QJsonDocument& input);

private:
};

#endif // JSONPARSER_H
