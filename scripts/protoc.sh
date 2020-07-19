#/bin/bash
# Run from repo root
set -e

mkdir -p build/protobuf
protoc --proto_path=lib/gymcpp-protobuf \
       --cpp_out=build/protobuf \
       --grpc_out=build/protobuf \
       --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
       lib/gymcpp-protobuf/*.proto
