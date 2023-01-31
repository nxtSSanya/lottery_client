#include "ConfigReader.h"
#include <iostream>

ConfigReader::ConfigReader()
{
    QFile inputFile("config.yaml");
    QRegExp regex(": ");
    inputFile.open(QIODevice::ReadOnly);
    std::vector<QString> values_from_file;

    QTextStream stream(&inputFile);

    for (QString line = stream.readLine(); !line.isNull(); line = stream.readLine()) {
        QStringList splitted = line.split(regex);
        values_from_file.push_back(splitted.last());
    };

    inputFile.close();

    m_server_url = values_from_file[0] + ":" + values_from_file[1];
}

QString ConfigReader::getServerAddress()
{
    return m_server_url;
}
