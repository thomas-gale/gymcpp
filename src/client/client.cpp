#include "gym/client.h"

#include <iostream>

namespace gym {

Client::Client(std::shared_ptr<grpc::Channel> channel)
    : stub_(gymcpp::Gym::NewStub(channel)) {}

void Client::testRequests() {
    // Send gRPC request
    gymcpp::EnvironmentRequest envRequest;

    // Response
    gymcpp::EnvironmentResponse envResponse;

    grpc::ClientContext context;
    grpc::Status status =
        stub_->EnvironmentInfo(&context, envRequest, &envResponse);

    if (!status.ok()) {
        std::cout << "Error on TestRequests\n";
    }
}

} // namespace gym