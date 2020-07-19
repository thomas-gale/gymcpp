#include "gym/client.h"
#include "gtest/gtest.h"

namespace testgym {
TEST(Client, CreateClient) {
    // Act
    gym::Client testClient("localhost:1234");
}
} // namespace testgym