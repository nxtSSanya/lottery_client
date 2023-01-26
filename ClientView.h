#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include "HttpServerController.h"
#include "JsonParser.h"
#include <iostream>

class ClientView
{
public:
    ClientView();
    void make_request(int method, const QString& ticket_id);
};

#endif // CLIENTVIEW_H
