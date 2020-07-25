#include "gym/server.h"
#include "gtest/gtest.h"

namespace testgym {
TEST(Server, CreateServer) {
    // Act
    gym::Server testServer("0.0.0.0", 4242);
}

TEST(Server, Run) {
    // Arrange
    gym::Server testServer("0.0.0.0", 4242);

    // Act
    testServer.run();
}

} // namespace testgym