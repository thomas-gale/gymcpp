# Library headers
file(GLOB HEADER_LIST ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# Locate protobuffer library (Built and located in /usr/lib/... during Docker environemnt setup)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf version: ${Protobuf_VERSION}")

# Locate gRPC library (Built and located in /usr/lib/... during Docker environemnt setup)
#include(Findgrpc)
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC version: ${gRPC_VERSION}")

# Protobuf generated headers and source
message(STATUS "Using auto-generated protobuf source files in: ${PROTO_SOURCE}")
file(GLOB PROTOBUF_HEADER_LIST ${PROTO_SOURCE}/*.h)
file(GLOB PROTOBUF_SRC_LIST ${PROTO_SOURCE}/*.cc)

# Add server and client
add_subdirectory(server)
add_subdirectory(client)
