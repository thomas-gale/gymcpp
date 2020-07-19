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
        auto* actionSpace = new gymcpp::Space();
        actionSpace->set_type(gymcpp::Space_SpaceType_DISCRETE);
        response->set_allocated_action_space(actionSpace);

        auto* observationSpace = new gymcpp::Space();
        observationSpace->set_type(gymcpp::Space_SpaceType_DISCRETE);
        response->set_allocated_observation_space(observationSpace);

        return grpc::Status::OK;
    }

    grpc::Status Reset(grpc::ServerContext* context,
                       const gymcpp::ResetRequest* request,
                       gymcpp::ResetResponse* response) override {
        // Reset environment
        auto* initialState = new gymcpp::State();
        initialState->set_observation(0, 42.0);
        initialState->set_reward(0.0);
        initialState->set_done(false);
        initialState->set_info("Test reset message");

        response->set_allocated_initial_state(initialState);

        return grpc::Status::OK;
    }

    grpc::Status Step(grpc::ServerContext* context,
                      const gymcpp::StepRequest* request,
                      gymcpp::StepResponse* response) override {
        // Step in environment
        auto* currentState = new gymcpp::State();
        currentState->set_observation(0, 64.0);
        currentState->set_reward(1.0);
        currentState->set_done(true);
        currentState->set_info("Test set message");

        response->set_allocated_current_state(currentState);

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
    // clients. In this case it corr>esponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << ss.str() << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

} // namespace gym