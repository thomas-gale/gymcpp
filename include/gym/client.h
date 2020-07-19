#ifndef __GYM_CLIENT_H__
#define __GYM_CLIENT_H__

#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "environment_request.pb.h"
#include "environment_response.pb.h"
#include "gym.grpc.pb.h"

namespace gym {

class Client {
  public:
    Client(std::shared_ptr<grpc::Channel> channel);

    void testRequests();

  private:
    std::unique_ptr<gymcpp::Gym::Stub> stub_;
};

} // namespace gym

#endif // __GYM_CLIENT_H__