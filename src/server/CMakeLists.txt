add_library(gymcpp_server
    ${HEADER_LIST}
    ${PROTOBUF_HEADER_LIST}
    ${PROTOBUF_SRC_LIST}
    server.cpp)

target_include_directories(gymcpp_server
    PUBLIC 
    ${PROTO_SOURCE}
    ${PROJECT_SOURCE_DIR}/include)
    #PRIVATE
    #${gRPC_LIBRARIES})

target_link_libraries(gymcpp_server 
    PUBLIC
    ${Protobuf_LIBRARIES}
    PRIVATE
    stdc++fs
    gRPC::grpc++
    grpc++_reflection)