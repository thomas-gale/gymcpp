#include "gym/server.h"
#include "gtest/gtest.h"

namespace testgym {
TEST(Server, CreateServer) {
    // Act
    gym::Server testServer("localhost", 50051);
}

TEST(Server, Run) {
    // Arrange
    gym::Server testServer("localhost", 50051);

    // Act
    testServer.run();
}

} // namespace testgym