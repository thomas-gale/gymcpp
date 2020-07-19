#include "gym/client.h"

#include <iostream>

namespace gym {

Client::Client(const std::string& url) : url_(url) {}

void Client::sendEnvRequest(const gymcpp::EnvironmentRequest& request) {
    // Send ZMQ request.
}

std::unique_ptr<gymcpp::EnvironmentResponse> Client::getEnvResponse() {
    // Get the latest response
    return nullptr;
}

void Client::helloWorld() { std::cout << "Client hello world!\n"; }

} // namespace gym