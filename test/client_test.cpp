#include "gym/client.h"

#include "gtest/gtest.h"

namespace testgym {
TEST(Client, CreateClient) {
    // Act
    gym::Client testClient(grpc::CreateChannel(
        "localhost:4242", grpc::InsecureChannelCredentials()));
}

TEST(Client, TestRequests) {
    // Arrange
    gym::Client testClient(grpc::CreateChannel(
        "localhost:4242", grpc::InsecureChannelCredentials()));

    // Act
    testClient.testRequests();
}
} // namespace testgym