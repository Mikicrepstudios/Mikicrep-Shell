: Clean up
rm output -rf
mkdir output

: Compile
g++ main.cpp -o output/main.o
