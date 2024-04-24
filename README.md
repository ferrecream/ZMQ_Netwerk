# ZeroMQ Client-Broker Communication System
This repository contains code for a client-broker communication system using ZeroMQ.
## Overview
The system consists of a client and a broker that communicate via ZeroMQ sockets. The client sends messages to the broker, and the broker processes these messages and sends back the results or other messages to the client.
## Prerequisites

- C++ compiler
- ZeroMQ library
- 
## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/ferrecream/ZMQ_Netwerk.git

2. Install the required dependencies.
3. Build the project using your preferred build system.

## Communication Flow
1. Initialization
   - The program initializes a ZeroMQ context.
   - It creates two sockets: one for pushing messages (pusher) and one for subscribing to messages (subscriber).
   - The subscriber socket subscribes to messages with the topic "Calculation".
3. Message Processing
- When a message is received on the subscriber socket:
   - If the message contains a single expression:
      - The expression is evaluated using the evaluateExpression function.
      - The result is sent back using the pusher socket.
   - If the message contains multiple parts:
      - Each part of the message is displayed.
3. User Input
   - A separate thread is created to handle user input.
   - When a line of input is received from the user:
      - The input is sent as a message using the pusher socket.
6. Connection
   - The pusher and subscriber sockets connect to the specified server addresses.
   - If the connection fails, an error message is displayed.
