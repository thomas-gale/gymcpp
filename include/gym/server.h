#ifndef __GYM_SERVER_H__
#define __GYM_SERVER_H__

#include <string>

namespace gym {

class Server {
  public:
    Server(const std::string& host, int port);
    ~Server();

    // Blocking function serve forever till interrupted
    void run();

    private:
      std::string host_;
      int port_;
};
} // namespace gym

#endif // __GYM_SERVER_H__