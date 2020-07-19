#include "gym/server.h"

#include <iostream>

#include "zmq.hpp"

namespace gym {

Server::Server() {
    // Initialise ZMQ server
}

Server::~Server() {
    // Cleanup ZMQ server
}

void Server::serve() {
    // Blocking function serve forever till interrupted

    // Create zmq context with single thread.
    zmq::context_t context(1);

    // Create responder
    zmq::socket_t responder(context, ZMQ_REP);
    responder.connect("tcp://localhost:5560");

    while(true) {
        //  Wait for next request from client
        std::string string = responder.recv();
        
        std::cout << "Received request: " << string << std::endl;
        
        // Do some 'work'
        sleep (1);
        
        //  Send reply back to client
        s_send (responder, "World");
    }

}

void Server::helloWorld() { std::cout << "Server hello world!\n"; }
} // namespace gym