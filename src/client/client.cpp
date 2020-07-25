#include "gym/client.h"

#include <chrono>
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

    // Test deadline
    //std::chrono::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(1000);
    //context.set_deadline(deadline);

    // Act
    grpc::Status status =
        stub_->EnvironmentInfo(&context, envRequest, &envResponse);

    if (!status.ok()) {
        std::cout << "Error on TestRequest - EnvironmentInfo, code: "
                  << status.error_code() << ": " << status.error_message()
                  << std::endl;
    }
}

} // namespace gym