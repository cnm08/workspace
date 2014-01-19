

TARGET=squareroot
CXX=g++


#$(TARGET): $(TARGET).o
#squareroot: squareroot.o

$(TARGET): MyFunc.h sqrt.o MyFunc.o
	$(CXX) sqrt.o MyFunc.o -o $(TARGET)

sqrt.o: MyFunc.h MyFunc.cc sqrt.cc
	$(CXX) -c sqrt.cc -o sqrt.o

MyFunc.o: MyFunc.h MyFunc.cc
	$(CXX) -c MyFunc.cc -o MyFunc.o
