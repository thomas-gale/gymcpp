#/bin/bash
# Run from repo root
set -e

mkdir -p build/protobuf
protoc --proto_path=lib/gymcpp-protobuf --cpp_out=build/protobuf lib/gymcpp-protobuf/*.proto
