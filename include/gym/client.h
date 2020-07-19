#ifndef __GYM_CLIENT_H__
#define __GYM_CLIENT_H__

#include <memory>
#include <string>

#include "environment_request.pb.h"
#include "environment_response.pb.h"

namespace gym {

class Client {
  public:
    Client(const std::string& url);

    void sendEnvRequest(const gymcpp::EnvironmentRequest& request);
    std::unique_ptr<gymcpp::EnvironmentResponse> getEnvResponse();

    void helloWorld();

  private:
    std::string url_;
};

} // namespace gym

#endif // __GYM_CLIENT_H__