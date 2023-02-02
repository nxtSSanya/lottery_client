#include "JsonParser.h"
#include <iostream>

bool checkForEmptyFieldsTicketInfo(const QJsonObject& json_object);
bool checkForEmptyFieldsSellTicket(const QJsonObject& json_object);
bool checkForEmptyFieldsPayTicket(const QJsonObject& json_object) ;

JsonParser::JsonParser()
{

}

std::vector<QString> JsonParser::parseArray(const QJsonDocument &input)
{
    std::vector<QString> tickets_arr;
    QJsonArray arr = input.array();
    if(arr.isEmpty()) {
        std:: cout << "Incorrect response from server\n";
    }

    for(int i = 0; i < arr.size(); ++i) {
        QJsonObject json = arr.at(i).toObject();
        tickets_arr.push_back(json.value("ticket_id").toString());
    }
    return tickets_arr;
}

ClientConfig::find_ticket_info JsonParser::parseTicketInfo(const QJsonDocument &input)
{
    ClientConfig::find_ticket_info ticket_info_struct;
    QJsonObject json_object = input.object();
    if(checkForEmptyFieldsTicketInfo(json_object)) {
        ticket_info_struct.code = json_object["code"].toString();
        ticket_info_struct.message = json_object["message"].toString();
        ticket_info_struct.ticket_id = json_object["ticket_id"].toString();
        ticket_info_struct.ticket_status = json_object["ticket_status"].toString();
    }
    else {
        ticket_info_struct.message = "Error while parsing, empty fields found\n";
        ticket_info_struct.code = "502";
    }

    return ticket_info_struct;
}

ClientConfig::sell_ticket_info JsonParser::parseSellTicket(const QJsonDocument &input)
{
    ClientConfig::sell_ticket_info sell_ticket_struct;
    QJsonObject json_object = input.object();
    if(checkForEmptyFieldsSellTicket(json_object)) {
        sell_ticket_struct.code = json_object["code"].toString();
        sell_ticket_struct.message = json_object["message"].toString();
        sell_ticket_struct.ticket_id = json_object["ticket_id"].toString();
        sell_ticket_struct.status = json_object["status"].toString();
    }
    else {
        sell_ticket_struct.message = "Error while parsing, empty fields found\n";
        sell_ticket_struct.code = "502";
    }
    return sell_ticket_struct;
}

ClientConfig::pay_ticket_info JsonParser::parsePayTicket(const QJsonDocument &input)
{
    ClientConfig::pay_ticket_info pay_ticket_struct;
    QJsonObject json_object = input.object();

    if(checkForEmptyFieldsPayTicket(json_object)) {
        pay_ticket_struct.code = json_object["code"].toString();
        pay_ticket_struct.message = json_object["message"].toString();
        pay_ticket_struct.ticket_id = json_object["ticket_id"].toString();
        pay_ticket_struct.status = json_object["status"].toString();
        pay_ticket_struct.win_sum = json_object["win_sum"].toString();
    }
    else {
        pay_ticket_struct.message = "Error while parsing, empty fields found\n";
        pay_ticket_struct.code = "502";
    }
    return pay_ticket_struct;
}

bool checkForEmptyFieldsTicketInfo(const QJsonObject& json_object)
{
    if(json_object["ticket_id"].isUndefined() || json_object["ticket_status"].isUndefined()) {
        if(json_object["code"].isUndefined() || json_object["message"].isUndefined()) {
            return false;
        }
    }
    if(json_object["ticket_id"].toString().isEmpty() || json_object["ticket_status"].toString().isEmpty()) {
        if(json_object["code"].toString().isEmpty() || json_object["message"].toString().isEmpty()) {
            return false;
        }
    }
    return true;
}

bool checkForEmptyFieldsSellTicket(const QJsonObject& json_object)
{
    if(json_object["ticket_id"].isUndefined() || json_object["status"].isUndefined()) {
        if(json_object["code"].isUndefined() || json_object["message"].isUndefined()) {
            return false;
        }
    }
    if(json_object["ticket_id"].toString().isEmpty() || json_object["status"].toString().isEmpty()) {
        if(json_object["code"].toString().isEmpty() || json_object["message"].toString().isEmpty()) {
            return false;
        }
    }
    return true;
}

bool checkForEmptyFieldsPayTicket(const QJsonObject& json_object)
{
    if(json_object["ticket_id"].isUndefined() || json_object["status"].isUndefined() || json_object["win_sum"].isUndefined()) {
        if(json_object["code"].isUndefined() || json_object["message"].isUndefined()) {
            return false;
        }
    }
    if(json_object["ticket_id"].toString().isEmpty() || json_object["status"].toString().isEmpty() || json_object["win_sum"].isUndefined()) {
        if(json_object["code"].toString().isEmpty() || json_object["message"].toString().isEmpty()) {
            return false;
        }
    }
    return true;
}
