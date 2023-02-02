#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include "HttpServerController.h"
#include "JsonParser.h"
#include <iostream>

class ClientView
{
public:
    ClientView();
    void makeRequest(int method, const QString& ticket_id);
    void getTicketList();
};

#endif // CLIENTVIEW_H
