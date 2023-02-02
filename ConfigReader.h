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
    bool isValid();
private:
    QString m_server_addr = "";
    QString m_server_port = "";
    QString m_server_url = "";
};

#endif // CONFIGREADER_H
