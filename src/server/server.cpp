#include "gym/server.h"

#include <iostream>
#include <sstream>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "gym.grpc.pb.h"

namespace gym {

class GymImpl final : public gymcpp::Gym::Service {
    grpc::Status
    EnvironmentInfo(grpc::ServerContext* context,
                    const gymcpp::EnvironmentRequest* request,
                    gymcpp::EnvironmentResponse* response) override {
        // Get information about environment

        return grpc::Status::OK;
    }

    grpc::Status Reset(grpc::ServerContext* context,
                       const gymcpp::ResetRequest* request,
                       gymcpp::ResetResponse* response) override {
        // Reset environment

        return grpc::Status::OK;
    }

    grpc::Status Step(grpc::ServerContext* context,
                      const gymcpp::StepRequest* request,
                      gymcpp::StepResponse* response) override {
        // Step in environment

        return grpc::Status::OK;
    }
};

Server::Server(const std::string& host, int port) : host_(host), port_(port) {
    // Init gRPC server?
}

Server::~Server() {
    // Cleanup gRPC server
}

void Server::run() {
    std::stringstream ss; 
    ss << host_ << ":" << port_;

    GymImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(ss.str(), grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << ss.str() << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

} // namespace gym