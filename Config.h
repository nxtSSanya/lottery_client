#ifndef CONFIG_H
#define CONFIG_H
#include <QtNetwork>

namespace ClientConfig {
    enum class Method {
        LIST_TICKETS = 0,
        FIND_TICKET = 1,
        PAY_TICKET = 2,
        SELL_TICKET = 3
    };

    struct find_ticket_info {
        QString ticket_id;
        QString ticket_status;
        QString code;
        QString message;
    };

    struct pay_ticket_info {
        QString status;
        QString win_sum;
        QString ticket_id;
        QString code;
        QString message;
    };

    struct sell_ticket_info {
        QString status;
        QString ticket_id;
        QString code;
        QString message;
    };

    const char* const invalid_method = "Invalid method found";
}

#endif // CONFIG_H
