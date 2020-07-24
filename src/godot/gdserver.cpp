/* summator.cpp */

#include "gym/godot/gdserver.h"

void Server::add(int p_value) {
    count += p_value;
}

void Server::reset() {
    count = 0;
}

int Server::get_total() const {
    return count;
}

void Server::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add", "value"), &Server::add);
    ClassDB::bind_method(D_METHOD("reset"), &Server::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &Server::get_total);
}

Server::Server() {
    count = 0;
}