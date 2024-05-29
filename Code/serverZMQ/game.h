#ifndef GAME_H
#define GAME_H

#include <QCoreApplication>
#include <QObject>
#include <nzmqt/nzmqt.hpp>
#include <nzmqt/impl.hpp>


#include <QList>

class game : public QObject
{
public:
    game(QCoreApplication *a);
    void startHeartbeat();
    void sendHeartbeat();

public slots:
    void Service(const QList<QByteArray>& messages);
private:
    unsigned int Solution;
    void help();
    void StringManipulation();
    void exit();
    void handleSetCommand(const QString &msg);
    void handleGetCommand(const QString &msg);
    void calculatorHandle(const QString &msg);
    void handleTaskSubmit(const QString &msg);
    void handleTaskStatus(const QString &msg);
    void handleTaskComplete(const QString &msg);
    nzmqt::ZMQSocket *pusher;
    nzmqt::ZMQSocket *subscriber;
    QMap<QString, QString> kvStore;
    QMap<QString, QString> taskStore;
};

#endif // GAME_H
