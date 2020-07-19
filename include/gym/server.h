#ifndef __GYM_SERVER_H__
#define __GYM_SERVER_H__

namespace gym {

class Server {
  public:
    Server();
    ~Server();

    // Blocking function serve forever till interrupted
    void serve();

    // Test
    void helloWorld();
};
} // namespace gym

#endif // __GYM_SERVER_H__