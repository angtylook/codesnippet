protoc -I item --cpp_out=./cpp --python_out=./py --go_out=./go base/item.proto
protoc -I item --cpp_out=./cpp --python_out=./py --go_out=./go pubc/login.proto
protoc -I item --cpp_out=./cpp --python_out=./py --go_out=./go storage/data.proto