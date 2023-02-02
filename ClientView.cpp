#include "ClientView.h"

void printTicketsList(const std::vector<QString>& list);
void printTicketInfo(const ClientConfig::find_ticket_info& ticket_info);
void printSellInfo(const ClientConfig::sell_ticket_info& ticket_info);
void printPayInfo(const ClientConfig::pay_ticket_info& ticket_info);

ClientView::ClientView()
{

}

void ClientView::makeRequest(int method, const QString& ticket_id)
{
    HttpServerController server_c;
    JsonParser jp;
    if(method == 1){
        auto ticket_info = jp.parseTicketInfo(server_c.processRequest(ticket_id, ClientConfig::Method::FIND_TICKET));
        printTicketInfo(ticket_info);
    }
    else if(method == 2){
        auto pay_ticket_info = jp.parsePayTicket(server_c.processRequest(ticket_id, ClientConfig::Method::PAY_TICKET));
        printPayInfo(pay_ticket_info);
    }
    else if(method == 3){
        auto sell_ticket_info = jp.parseSellTicket(server_c.processRequest(ticket_id, ClientConfig::Method::SELL_TICKET));
        printSellInfo(sell_ticket_info);
    }
    else {
        std::cout << "Wrong method\n";
        return;
    }

}

void ClientView::getTicketList()
{
    HttpServerController server_c;
    JsonParser jp;
    auto tickets_list = jp.parseArray(server_c.processRequest("", ClientConfig::Method::LIST_TICKETS));
    printTicketsList(tickets_list);
}

void printTicketsList(const std::vector<QString>& list) {
    if(!isServerOnline) {
        std::cout << "Server is not online!\n";
        return;
    }
    else {
        std::cout << "Method: printTicketsList\n";
        for(const auto& ticket: list){
            std::cout << "ticket id: " << ticket.toStdString() << "\n";
        }
    }
}

void printTicketInfo(const ClientConfig::find_ticket_info& ticket_info) {
    if(!isServerOnline) {
        std::cout << "Server is not online!\n";
        return;
    }
    else {
        std::cout << "Method: printTicketInfo\n";
        if(!ticket_info.ticket_id.isEmpty() && !ticket_info.ticket_status.isEmpty()){
            std::cout << "Ticket id: " << ticket_info.ticket_id.toStdString() <<"\n";
            std::cout << "Status: " << ticket_info.ticket_status.toStdString() <<"\n";
        }
        else {
            std::cout << "Error code: "<< ticket_info.code.toStdString() <<"\n";
            std::cout << "Message: "<< ticket_info.message.toStdString() <<"\n";
        }
    }
}

void printSellInfo(const ClientConfig::sell_ticket_info& ticket_info) {
    if(!isServerOnline) {
        std::cout << "Server is not online!\n";
        return;
    }
    else {
        std::cout << "Method: printSellInfo\n";
        if(!ticket_info.ticket_id.isEmpty() && !ticket_info.status.isEmpty()){
            std::cout << "Ticket id: " << ticket_info.ticket_id.toStdString() <<"\n";
            std::cout << "Status: " << ticket_info.status.toStdString() <<"\n";
        }
        else {
            std::cout << "Error code: "<< ticket_info.code.toStdString() <<"\n";
            std::cout << "Message: "<< ticket_info.message.toStdString() <<"\n";
        }
    }
}

void printPayInfo(const ClientConfig::pay_ticket_info& ticket_info) {
    if(!isServerOnline) {
        std::cout << "Server is not online!\n";
        return;
    }
    else {
        std::cout << "Method: printPayInfo\n";
        if(!ticket_info.ticket_id.isEmpty() && !ticket_info.status.isEmpty()){
            std::cout << "Ticket id: " << ticket_info.ticket_id.toStdString() <<"\n";
            std::cout << "Status: " << ticket_info.status.toStdString() <<"\n";
            std::cout << "Win size: " << ticket_info.win_sum.toStdString() << "\n";
        }
        else {
            std::cout << "Error code: "<< ticket_info.code.toStdString() <<"\n";
            std::cout << "Message: "<< ticket_info.message.toStdString() <<"\n";
        }
    }
}
