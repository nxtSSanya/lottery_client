#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QRegExp>
#include <QStringList>

extern QString config_file_path;

class ConfigReader{
public:
    ConfigReader(const QString& file_name);
    QString getServerAddress();
    QString error();
private:

    QString m_server_url = "127.0.0.1:8080";
    QString m_error = "8080";
};

#endif // CONFIGREADER_H
