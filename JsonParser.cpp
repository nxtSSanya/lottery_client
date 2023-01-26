#include "JsonParser.h"

JsonParser::JsonParser()
{

}

std::vector<QString> JsonParser::parseArray(const QJsonDocument &input)
{
    std::vector<QString> tickets_arr;
    QJsonArray arr = input.array();

    for(int i = 0; i < arr.size(); ++i) {
        QJsonObject json = arr.at(i).toObject();
        tickets_arr.push_back(json.value("ticket_id").toString());
    }
    return tickets_arr;
}

ClientConfig::find_ticket_info JsonParser::parseTicketInfo(const QJsonDocument &input)
{
    ClientConfig::find_ticket_info ticket_info_struct;
    QJsonObject jsonObject = input.object();

    ticket_info_struct.code = jsonObject["code"].toString();
    ticket_info_struct.message = jsonObject["message"].toString();
    ticket_info_struct.ticket_id = jsonObject["ticket_id"].toString();
    ticket_info_struct.ticket_status = jsonObject["ticket_status"].toString();

    return ticket_info_struct;
}

ClientConfig::sell_ticket_info JsonParser::parseSellTicket(const QJsonDocument &input)
{
    ClientConfig::sell_ticket_info sell_ticket_struct;
    QJsonObject jsonObject = input.object();

    sell_ticket_struct.code = jsonObject["code"].toString();
    sell_ticket_struct.message = jsonObject["message"].toString();
    sell_ticket_struct.ticket_id = jsonObject["ticket_id"].toString();
    sell_ticket_struct.status = jsonObject["status"].toString();

    return sell_ticket_struct;
}

ClientConfig::pay_ticket_info JsonParser::parsePayTicket(const QJsonDocument &input)
{
    ClientConfig::pay_ticket_info pay_ticket_struct;
    QJsonObject jsonObject = input.object();

    pay_ticket_struct.code = jsonObject["code"].toString();
    pay_ticket_struct.message = jsonObject["message"].toString();
    pay_ticket_struct.ticket_id = jsonObject["ticket_id"].toString();
    pay_ticket_struct.status = jsonObject["status"].toString();
    pay_ticket_struct.win_sum = jsonObject["win_sum"].toString();

    return pay_ticket_struct;
}
