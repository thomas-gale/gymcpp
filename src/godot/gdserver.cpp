/* gdserver.cpp */

#include "gym/godot/gdserver.h"

Server::Server() {}

void Server::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init", "host", "port"), &Server::init);
    ClassDB::bind_method(D_METHOD("run"), &Server::run);
}

void Server::init(const String& host, int port) {
    print_line(vformat("Initialising GymServer on %s:%S...", host, port));
    std::wstring whost(host.c_str());
    std::string shost(whost.begin(), whost.end());
    server_ = std::make_unique<gym::Server>(shost, port);
}

void Server::run() {
    print_line("Running Server...");
    // Start the internal server
    server_->run();
}
