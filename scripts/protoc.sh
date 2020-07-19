#/bin/bash
# Run from repo root
set -e

mkdir -p build/protobuf
protoc --proto_path=protobuf --cpp_out=build/protobuf protobuf/*.proto
