# External and third party libraries.
set(3P_DIR ${CMAKE_SOURCE_DIR}/lib CACHE STRING "")

# We are relying that the ./scripts/protoc.sh has already run successfuly.
set(PROTO_SOURCE ${CMAKE_SOURCE_DIR}/build/protobuf CACHE STRING "")

# Lightweight messaging kernel - https://github.com/zeromq/libzmq
set(ZMQ_DIR ${3P_DIR}/libzmq CACHE STRING "")
option(ZMQ_BUILD_TESTS "" OFF)
add_subdirectory(libzmq)

# C++ adapted wrapper around libzmq
set(ZMQCPP_DIR ${3P_DIR}/zmqcpp CACHE STRING "")
add_subdirectory(zmqcpp)
