#include "gym/server.h"

#include <iostream>

namespace gym {

Server::Server() {
    // Initialise ZMQ server
}

Server::~Server() {
    // Cleanup ZMQ server
}

void Server::serve() {
    // Blocking function serve forever till interrupted
    // While true ....
}

void Server::helloWorld() { std::cout << "Server hello world!\n"; }
} // namespace gym