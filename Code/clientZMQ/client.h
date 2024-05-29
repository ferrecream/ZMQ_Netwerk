#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QObject>
#include <nzmqt/nzmqt.hpp>
#include <nzmqt/impl.hpp>
#include <iostream>
#include <QString>
#include <QTimer>
#include <QThread>
#include <QDateTime>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private:
    nzmqt::ZMQSocket *pusher;
    nzmqt::ZMQSocket *subscriber;
    Ui::Client *ui;
    double calcVal = 0.0;
    QChar GetVal;
    QChar Key;
    QChar KeyId;
    bool difTrigger = false;
    bool multTrigger = false;
    bool addTrigger = false;
    bool subTrigger = false;
private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void handleResponseC(const QList<QByteArray> &messages);
    void handleResponseS(const QList<QByteArray> &messages);
    void SetButtonKey();
    void GetButtonKey();
};
#endif // CLIENT_H
