#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QRegExp>
#include <QStringList>

class ConfigReader{
public:
    ConfigReader();
    QString getServerAddress();
private:
    QString m_server_url = "127.0.0.1:8080";
};

#endif // CONFIGREADER_H
