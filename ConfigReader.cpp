#include "ConfigReader.h"
#include <iostream>
#include <QDebug>

QString config_file_path;

ConfigReader::ConfigReader(const QString& file_name)
{
    const QString address_config_field_name = "server_ip_address";
    const QString port_config_field_name = "server_port";
    std::vector<QString> config_values;

    QFile input_file(file_name);
    QRegExp regex(": ");

    if(input_file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&input_file);

        for (QString line = stream.readLine(); !line.isNull(); line = stream.readLine()) {
            QStringList splitted = line.split(regex);

            if(splitted.first() == address_config_field_name) {
                m_server_addr = splitted.at(1);
            }
            if(splitted.first() == port_config_field_name) {
                m_server_port = splitted.at(1);
            }
        };
        input_file.close();

        m_server_url = m_server_addr + ":" + m_server_port;
    }
    else {
        std::cout << "Cannot open the file, check your path and try again.\n";
    }
}

QString ConfigReader::getServerAddress()
{
    return m_server_url;
}

bool ConfigReader::isValid()
{
    if(m_server_url.isEmpty()) {
        return false;
    }
    return true;
}
