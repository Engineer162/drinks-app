#include <zmq.hpp>
#include <iostream>
#include <string>

int main()
{
    // Initialize ZeroMQ context
    zmq::context_t context(1);

    // Create a SUB (subscriber) socket
    zmq::socket_t socket(context, zmq::socket_type::pull); // Use PULL to match PUSH
    socket.bind("tcp://0.0.0.0:5566"); // Listens on all available network interfaces

    std::cout << "Listening for messages on port 5566...\n";

    while (true)
    {
        zmq::message_t message;

        // Receive message
        socket.recv(message, zmq::recv_flags::none);

        // Convert message to string and display it
        std::string received_msg(static_cast<char*>(message.data()), message.size());
        std::cout << "Received: " << received_msg << std::endl;
    }

    return 0;
}
