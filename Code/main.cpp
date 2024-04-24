#include <iostream>
#include <string>
#include <zmq.hpp>
#include <QString>

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

int main(int argc, char* argv[])
{
    try
    {
        zmq::context_t context(1);

        zmq::socket_t ventilator(context, ZMQ_PUSH);
        ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

        // Incoming messages come in here
        zmq::socket_t subscriber(context, ZMQ_SUB);
        subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");
        subscriber.setsockopt(ZMQ_SUBSCRIBE, "Calculator>", 11);

        while (true) {
            zmq::message_t msg;
            subscriber.recv(&msg);

            std::string received_msg = std::string(static_cast<char*>(msg.data()), msg.size());
            std::cout << "Received: [" << received_msg << "]" << std::endl;

            // Parse the message to extract operands and operator
            std::string delimiter = ">";
            size_t pos = 0;
            std::string token;
            std::string operands[2];
            int index = 0;

            while ((pos = received_msg.find(delimiter)) != std::string::npos) {
                token = received_msg.substr(0, pos);
                received_msg.erase(0, pos + delimiter.length());
                operands[index++] = token;
            }

            // Extracted operands and operator
            double operand1 = std::stod(operands[1]);
            double operand2 = std::stod(received_msg);
            std::string operation = operands[0];

            // Perform arithmetic operation
            double result;
            if (operation == "add") {
                result = operand1 + operand2;
            } else if (operation == "subtract") {
                result = operand1 - operand2;
            } else if (operation == "multiply") {
                result = operand1 * operand2;
            } else if (operation == "divide") {
                if (operand2 != 0) {
                    result = operand1 / operand2;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    continue;
                }
            } else {
                std::cerr << "Error: Invalid operation!" << std::endl;
                continue;
            }

            // Send the result back
            std::string result_msg = "Result>" + std::to_string(result);
            ventilator.send(result_msg.c_str(), result_msg.length());
        }
    }
    catch (zmq::error_t& ex)
    {
        std::cerr << "Caught an exception : " << ex.what();
    }

    return 0;
}
