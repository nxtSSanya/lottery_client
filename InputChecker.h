#ifndef INPUTCHECKER_H
#define INPUTCHECKER_H

#include <QString>
#include <QRegExp>

#include "Config.h"

namespace InputChecker {
    inline bool checkForCorrectId(const QString& ticket_id)
    {
        QRegExp ticket_id_regex("\\d{8}");
        if(ticket_id_regex.exactMatch(ticket_id)) {
            return true;
        }
        return false;
    }
    inline int stringMethodToInt(const QString& method)
    {
        if(method.toInt() > static_cast<int>(ClientConfig::Method::METHODS_NUM) - 1) {
            return -1;
        }
        for(auto&i: method) {
            if(!i.isDigit()) {
                return -1;
            }
        }
        return method.toInt();
    }
}

#endif // INPUTCHECKER_H
