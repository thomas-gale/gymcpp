add_library(gymcpp_client
    ${HEADER_LIST}
    ${PROTOBUF_HEADER_LIST}
    ${PROTOBUF_SRC_LIST}
    client.cpp)

target_include_directories(gymcpp_client
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(gymcpp_client 
    PUBLIC
    ${Protobuf_LIBRARIES}
    stdc++fs)