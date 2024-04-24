#include <iostream>
#include <nzmqt/nzmqt.hpp>
#include <nzmqt/impl.hpp>
#include <QCoreApplication>
#include <QString>
#include <QTimer>
#include <QThread>
#include <QDateTime>
#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to evaluate arithmetic expressions
double evaluateExpression(const string &expression) {
    istringstream iss(expression);
    double result;
    iss >> result;
    char op;
    while (iss >> op) {
        double operand;
        iss >> operand;
        switch (op) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            case '/':
                if (operand == 0)
                    throw invalid_argument("Division by zero");
                result /= operand;
                break;
            default:
                throw invalid_argument("Invalid operator");
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    cout << "Prep!" << endl;

    try {
        nzmqt::ZMQContext *context = nzmqt::createDefaultContext(&a);
        nzmqt::ZMQSocket *pusher = context->createSocket(nzmqt::ZMQSocket::TYP_PUSH, context);
        nzmqt::ZMQSocket *subscriber = context->createSocket(nzmqt::ZMQSocket::TYP_SUB, context);

        // Set subscription topic
        subscriber->subscribeTo("Calculation");

        QObject::connect(subscriber, &nzmqt::ZMQSocket::messageReceived, [&](const QList<QByteArray> &messages) {
            if (messages.size() < 1) {
                cout << "Received empty message !" << endl;
            } else if (messages.size() == 1) {
                string expression = messages.constFirst().toStdString();
                try {
                    double result = evaluateExpression(expression);
                    ostringstream ss;
                    ss << fixed << setprecision(2) << result;
                    cout << "Result: " << ss.str() << endl;
                    // Send back the result
                    nzmqt::ZMQMessage message(ss.str().c_str());
                    pusher->sendMessage(message);
                    cout << "Result sent!" << endl;
                } catch (const exception &e) {
                    cerr << "Error: " << e.what() << endl;
                }
            } else {
                cout << "Received " << messages.size() << " parts" << endl;
                int part = 1;
                for (const QByteArray &message : messages) {
                    cout << "Part " << part << " (" << message.size() << ") : " << message.toStdString() << endl;
                    part++;
                }
            }
        });

        QThread *thread = QThread::create([pusher] {
            QTextStream s(stdin);
            while (1) {
                QString input = s.readLine();
                nzmqt::ZMQMessage message = nzmqt::ZMQMessage(input.toUtf8());
                pusher->sendMessage(message);
                cout << "Message sent!" << endl;
            }
        });

        pusher->connectTo("tcp://benternet.pxl-ea-ict.be:24041");
        subscriber->connectTo("tcp://benternet.pxl-ea-ict.be:24042");

        if (!pusher->isConnected() || !subscriber->isConnected()) {
            cerr << "NOT CONNECTED !!!" << endl;
        }

        context->start();
        thread->start();
    } catch (nzmqt::ZMQException &ex) {
        cerr << "Caught an exception: " << ex.what() << endl;
    }

    cout << "Start!" << endl;
    return a.exec();
   }
