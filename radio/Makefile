

TARGET=radio
CXX=g++


$(TARGET): decay.o
	$(CXX) -I /usr/local/root_v5.34.11/include/root -L/usr/local/root_v5.34.11/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic decay.o -o $(TARGET)

decay.o: decay.cc
	$(CXX) -I /usr/local/root_v5.34.11/include/root -c decay.cc -o decay.o

