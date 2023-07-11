: Clean up
rm output -rf
mkdir output

: Compile
g++ main.cpp cmds.cpp -Wno-write-strings -o output/main.o
