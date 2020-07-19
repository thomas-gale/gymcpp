#include "gym/server.h"
#include "gtest/gtest.h"

namespace testgym {
TEST(Server, CreateServer) {
    // Act
    gym::Server testServer;
}

TEST(Server, Serve) {
    // Arrange
    gym::Server testServer;

    // Act
    testServer.serve();
}

TEST(Server, HelloWorld) {
    // Arrange
    gym::Server testServer;

    // Act
    testServer.helloWorld();
}
} // namespace testgym