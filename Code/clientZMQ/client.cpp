#include "client.h"
#include "ui_client.h"


// Ferre?>Calculator>CalcVal>opperator>secondVal
Client::Client(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Client),
      calcVal(0.0),
      difTrigger(false),
      multTrigger(false),
      addTrigger(false),
      subTrigger(false)
{
    nzmqt::ZMQContext *context = nzmqt::createDefaultContext(parent);
    nzmqt::ZMQSocket *pusher = context->createSocket( nzmqt::ZMQSocket::TYP_PUSH, context );
    nzmqt::ZMQSocket *subscriber = context->createSocket( nzmqt::ZMQSocket::TYP_SUB, context );
    subscriber->subscribeTo("Ferre!");

    pusher->connectTo( "tcp://benternet.pxl-ea-ict.be:24041" );
    subscriber->connectTo( "tcp://benternet.pxl-ea-ict.be:24042" );


    if( !pusher->isConnected() || !subscriber->isConnected() )
    {
        std::cout << "NOT CONNECTED" << std::endl;
    }

    context->start();

    ui->setupUi(this);
    ui->Display->setText(QString::number(calcVal));
    ui->GetDisplay->setText(QString(GetVal));
    ui->KeyDisplay->setText(QString(Key));
    ui->KeyIdDisplay->setText(QString(KeyId));

    QPushButton *numButtons[10];
    for(int i = 0; i < 10; ++i){
        QString butName = "button" + QString::number(i);
        numButtons[i] = Client::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
    connect(ui->buttonAdd, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->buttonDiv, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->buttonMult  , SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->buttonMin, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->buttonEqual, SIGNAL(released()), this, SLOT(EqualButtonPressed()));
    connect(ui->SetKey, SIGNAL(released()),this,SLOT(SetButtonKey()));
    connect(ui->GetKey, SIGNAL(released()),this,SLOT(GetButtonKey()));

}

Client::~Client()
{
    delete ui;
}

void Client::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button ->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()== 0 || displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g',16));

    }
}
void Client::MathButtonPressed(){
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    difTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    if(QString::compare(butVal, "/",Qt::CaseInsensitive)==0){
        difTrigger = true;
        ui->Display->setText("");
    } else if(QString::compare(butVal, "*",Qt::CaseInsensitive)==0){
        multTrigger = true;
        ui->Display->setText("");
    } else if(QString::compare(butVal, "+",Qt::CaseInsensitive)==0){
        addTrigger = true;
        ui->Display->setText("");
    } else if(QString::compare(butVal, "-",Qt::CaseInsensitive)==0){
        subTrigger = true;
        ui->Display->setText("");
    }

}
void Client::EqualButtonPressed(){
    QString displayVal = ui->Display->text();
    double result = displayVal.toDouble();
    QString command;

    if(difTrigger || multTrigger || addTrigger || subTrigger){

        if (difTrigger)
        {
            command = QString("Ferre?>Calculator>%1>division>%2").arg(calcVal,result);
        }
        else if (multTrigger)
        {
            command = QString("Ferre?>Calculator>%1>multiply>%2").arg(calcVal,result);
        }
        else if (addTrigger)
        {
            command = QString("Ferre?>Calculator>%1>add>%2").arg(calcVal,result);
        }
        else if (subTrigger)
        {
            command = QString("Ferre?>Calculator>%1>substract>%2").arg(calcVal,result);
        }

        // Send command to the server
        nzmqt::ZMQMessage message = nzmqt::ZMQMessage( command.toUtf8());
        pusher->sendMessage(message);

        QObject::connect(subscriber, &nzmqt::ZMQSocket::messageReceived, this, &Client::handleResponseC);

        // Reset triggers
        difTrigger = false;
        multTrigger = false;
        addTrigger = false;
        subTrigger = false;

     }
}
void Client::handleResponseC(const QList<QByteArray> &messages)
{
    if (!messages.isEmpty())
    {
        QString response = QString::fromUtf8(messages[0]);
        QStringList responseParts = response.split('>');
        if (responseParts.size() == 3 && responseParts[0] == "Ferre!")
        {
            double serverResult = responseParts[2].toDouble();
            ui->Display->setText(QString::number(serverResult, 'g', 16));
        }
        else
        {
            ui->Display->setText("Error");
        }
    }
    else
    {
        ui->Display->setText("No response");
    }
}

void Client::SetButtonKey(){
    QString displayKey = ui->KeyDisplay->text();
    QString displayKeyID = ui->KeyIdDisplay->text();
    QString command;
    command = QString("Ferre?>KeyStore>SET>%1>%2").arg(displayKeyID, displayKey);
    // Send command to the server
    nzmqt::ZMQMessage message = nzmqt::ZMQMessage( command.toUtf8());
    pusher->sendMessage(message);

}
void Client::GetButtonKey(){
    QString displayKeyID = ui->KeyIdDisplay->text();
    QString command;
    command = QString("Ferre?>KeyStore>GET>%1").arg(displayKeyID);
    // Send command to the server
    nzmqt::ZMQMessage message = nzmqt::ZMQMessage( command.toUtf8());
    pusher->sendMessage(message);
    QObject::connect(subscriber, &nzmqt::ZMQSocket::messageReceived, this, &Client::handleResponseS);

}
void Client::handleResponseS(const QList<QByteArray> &messages)
{
    if (!messages.isEmpty())
    {
        QString response = QString::fromUtf8(messages[0]);
        QStringList responseParts = response.split('>');
        if (responseParts.size() == 4 && responseParts[0] == "Ferre!")
        {
            double serverResult = responseParts[3].toDouble();
            ui->Display->setText(QString::number(serverResult, 'g', 16));
        }
        else
        {
            ui->Display->setText("Error");
        }
    }
    else
    {
        ui->Display->setText("No response");
    }
}
