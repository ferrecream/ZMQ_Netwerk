#include "game.h"
#include <iostream>
#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QMap>
#include <QTimer>
#include <QDateTime>
#include <QDateTime>

game::game(QCoreApplication *a)
{
    startHeartbeat();
    try
    {
        nzmqt::ZMQContext *context = nzmqt::createDefaultContext(a);
        pusher = context->createSocket(nzmqt::ZMQSocket::TYP_PUSH, context);
        subscriber = context->createSocket(nzmqt::ZMQSocket::TYP_SUB, context);
        QObject::connect(subscriber, &nzmqt::ZMQSocket::messageReceived, this, &game::Service);

        pusher->connectTo("tcp://benternet.pxl-ea-ict.be:24041");
        subscriber->connectTo("tcp://benternet.pxl-ea-ict.be:24042");
        subscriber->subscribeTo("Ferre?>");

        if (!pusher->isConnected() || !subscriber->isConnected())
        {
            std::cerr << "NOT CONNECTED !!!" << std::endl;
        }

        context->start();
    }
    catch (nzmqt::ZMQException &ex)
    {
        std::cerr << "Caught an exception : " << ex.what();
    }
    std::cout << "Server online" << std::endl;
}

void game::Service(const QList<QByteArray> &messages)
{
    if (messages.size() < 1)
    {
        std::cout << "Received empty message !" << std::endl;
    }
    else
    {
        for (QByteArray msgByteArray : messages)
        {
            QString msg = QString::fromUtf8(msgByteArray);
            std::cout << "Received: " << msg.toStdString() << std::endl;

            if (msg.contains("Ferre?>help"))
            {
                help();
            }
            else if (msg.contains("Ferre?>KeyStore>SET"))
            {
                handleSetCommand(msg);
            }
            else if (msg.contains("Ferre?>KeyStore>GET"))
            {
                handleGetCommand(msg);
            }
            else if (msg.contains("Ferre?>Calculator"))
            {
                calculatorHandle(msg);
            }
            else if (msg.contains("Ferre?>Task>SUBMIT"))
            {
                handleTaskSubmit(msg);
            }
            else if (msg.contains("Ferre?>Task>STATUS"))
            {
                handleTaskStatus(msg);
            }
            else if (msg.contains("Ferre?>Task>COMPLETE"))
            {
                handleTaskComplete(msg);
            }
            else
            {
                QString error = "Ferre!>Unknown Command";
                nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
                pusher->sendMessage(errorMessage);
            }

        }
    }
}

void game::help()
{
    QString helpDesk = "hello Mr. loser who else needs help\n"
                       "so for the calculator : Ferre?>Calculator>Number1>Opperator(*,/,-,+)>Number2\n"
                       "so for the keyVault you can set a Key : Ferre?>KeyStore>SET>KeyName(free to chose)>key(could be random hex file)\n"
                       "retrieving the key : Ferre?>KeyStore>GET>KeyName(you named the key) -----> it will print you key"
            ;

    nzmqt::ZMQMessage HelpMessage = nzmqt::ZMQMessage(helpDesk.toUtf8());
    pusher->sendMessage(HelpMessage);
}

void game::handleSetCommand(const QString &msg)
{
    QList<QString> messageSplit = msg.split('>');
    if (messageSplit.size() == 5)
    {
        QString key = messageSplit[3];
        QString value = messageSplit[4];
        kvStore[key] = value;

        QString response = QString("Ferre!>KeyStore>SET>Success");
        nzmqt::ZMQMessage responseMessage = nzmqt::ZMQMessage(response.toUtf8());
        pusher->sendMessage(responseMessage);
    }
    else
    {
        QString error = "Ferre!>KeyStore>SET>Error: Invalid message format";
        nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
        pusher->sendMessage(errorMessage);

    }
}

void game::handleGetCommand(const QString &msg)
{
    QList<QString> messageSplit = msg.split('>');
    if (messageSplit.size() == 4)
    {
        QString key = messageSplit[3];
        if (kvStore.contains(key))
        {
            QString value = kvStore[key];
            QString response = QString("Ferre!>KeyStore>GET>%1>%2").arg(key, value);
            nzmqt::ZMQMessage responseMessage = nzmqt::ZMQMessage(response.toUtf8());
            pusher->sendMessage(responseMessage);
        }
        else
        {
            QString error = QString("Ferre!>KeyStore>GET>Error: Key '%1' not found").arg(key);
            nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
            pusher->sendMessage(errorMessage);
        }
    }
    else
    {
        QString error = "Ferre!>KeyStore>GET>Error: Invalid message format";
        nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
        pusher->sendMessage(errorMessage);
    }
}


void game::calculatorHandle(const QString &msg)
{
    QList<QString> messageSplit = msg.split('>');
    if (messageSplit.size() == 5)
    {
        bool firstNumOk, secondNumOk;
        unsigned int FirstNumber = messageSplit[2].toInt(&firstNumOk);
        QString Opp = messageSplit[3];
        unsigned int SecondNumber = messageSplit[4].toInt(&secondNumOk);

        if (!firstNumOk || !secondNumOk)
        {
            QString error = "Error: Invalid number format";
            nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
            pusher->sendMessage(errorMessage);
            return;
        }

        if (Opp == "add")
        {
            Solution = FirstNumber + SecondNumber;
        }
        else if (Opp == "subtract")
        {
            Solution = FirstNumber - SecondNumber;
        }
        else if (Opp == "multiply")
        {
            Solution = FirstNumber * SecondNumber;
        }
        else if (Opp == "division")
        {
            if (SecondNumber == 0)
            {
                QString error = "Error: Division by zero";
                nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
                pusher->sendMessage(errorMessage);
                return;
            }
            Solution = FirstNumber / SecondNumber;
        }
        else
        {
            QString error = "Error: Invalid operator";
            nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
            pusher->sendMessage(errorMessage);
            return;
        }

        QString response = QString("Ferre!>Calculator>%1").arg(Solution);
        nzmqt::ZMQMessage responseMessage = nzmqt::ZMQMessage(response.toUtf8());
        pusher->sendMessage(responseMessage);
    }
    else
    {
        QString error = "Error: Invalid message format in CalculatorHandle";
        nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
        pusher->sendMessage(errorMessage);
    }
}


void game::startHeartbeat()
{
    QTimer *heartbeatTimer = new QTimer(this);
    connect(heartbeatTimer, &QTimer::timeout, this, &game::sendHeartbeat);
    heartbeatTimer->start(120000); // Send heartbeat every 10 seconds
}

void game::sendHeartbeat()
{
    QString heartbeat = QString("Heartbeat!>timestamp:%1").arg(QDateTime::currentDateTime().toString(Qt::ISODate));
    nzmqt::ZMQMessage heartbeatMessage = nzmqt::ZMQMessage(heartbeat.toUtf8());
    pusher->sendMessage(heartbeatMessage);
}

void game::handleTaskSubmit(const QString &msg)
{
    QList<QString> messageSplit = msg.split('>');
    if (messageSplit.size() == 5)
    {
        QString taskID = messageSplit[3];
        QString taskDetails = messageSplit[4];
        taskStore[taskID] = taskDetails;

        QString response = QString("Ferre!>Task>SUBMIT>Success");
        nzmqt::ZMQMessage responseMessage = nzmqt::ZMQMessage(response.toUtf8());
        pusher->sendMessage(responseMessage);


    }
    else
    {
        QString error = "Ferre!>Task>SUBMIT>Error: Invalid message format";
        nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
        pusher->sendMessage(errorMessage);


    }
}

void game::handleTaskStatus(const QString &msg)
{
    QList<QString> messageSplit = msg.split('>');
    if (messageSplit.size() == 4)
    {
        QString taskID = messageSplit[3];
        if (taskStore.contains(taskID))
        {
            QString taskDetails = taskStore[taskID];
            QString response = QString("Ferre!>Task>STATUS>%1>%2").arg(taskID, taskDetails);
            nzmqt::ZMQMessage responseMessage = nzmqt::ZMQMessage(response.toUtf8());
            pusher->sendMessage(responseMessage);


        }
        else
        {
            QString error = QString("Ferre!>Task>STATUS>Error: Task '%1' not found").arg(taskID);
            nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
            pusher->sendMessage(errorMessage);


        }
    }
    else
    {
        QString error = "Ferre!>Task>STATUS>Error: Invalid message format";
        nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
        pusher->sendMessage(errorMessage);


    }
}

void game::handleTaskComplete(const QString &msg)
{
    QList<QString> messageSplit = msg.split('>');
    if (messageSplit.size() == 5)
    {
        QString taskID = messageSplit[3];
        QString result = messageSplit[4];
        if (taskStore.contains(taskID))
        {
            taskStore.remove(taskID);
            QString response = QString("Ferre!>Task>COMPLETE>Success>%1").arg(result);
            nzmqt::ZMQMessage responseMessage = nzmqt::ZMQMessage(response.toUtf8());
            pusher->sendMessage(responseMessage);

        }
        else
        {
            QString error = QString("Ferre!>Task>COMPLETE>Error: Task '%1' not found").arg(taskID);
            nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
            pusher->sendMessage(errorMessage);

        }
    }
    else
    {
        QString error = "Ferre!>Task>COMPLETE>Error: Invalid message format";
        nzmqt::ZMQMessage errorMessage = nzmqt::ZMQMessage(error.toUtf8());
        pusher->sendMessage(errorMessage);

    }
}
