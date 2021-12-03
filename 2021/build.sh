cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make

cd ./src/day$1
./day$1 < input
