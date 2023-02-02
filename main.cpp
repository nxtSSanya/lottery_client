#include <QCoreApplication>
#include <QtNetwork>
#include <iostream>
#include <string>

#include "JsonParser.h"
#include "HttpServerController.h"
#include "Config.h"
#include "ClientView.h"
#include "ConfigReader.h"
#include "InputChecker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ClientView view;

    std::string input_file_path;
    std::string std_ticket_id;
    std::string std_method;

    std::cout << "Enter the path to the config file: ";
    std::cin >> input_file_path;
    config_file_path = QString::fromStdString(input_file_path);
    ConfigReader reader(config_file_path);
    assert(reader.isValid() == true);

    while(1) {
        std:: cout << "Available methods:\n0 - list all tickets\n1 - get ticket info\n2 - pay for ticket \n3 - sell ticket\n";
        std:: cout << "Method: ";
        std:: cin >> std_method;
        int method = InputChecker::stringMethodToInt(QString::fromStdString(std_method));

        if(method == -1) {
            std::cout << "Incorrect method\n";
            break;
        }
        else if(method == 0) {
            std:: cout << "------------\n";
            view.getTicketList();
            std:: cout << "------------\n";
        }
        else {
            std:: cout << "Ticket id: ";
            std:: cin >> std_ticket_id;
            QString ticket_id = QString::fromStdString(std_ticket_id);
            if(InputChecker::checkForCorrectId(ticket_id)) {
                std:: cout << "------------\n";
                view.makeRequest(method, ticket_id);
                std:: cout << "------------\n";
            }
            else {
                std::cout << "Wrong input data format\n";
                break;
            }
        }
    }
    return a.exec();
}
