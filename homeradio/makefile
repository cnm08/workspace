TARGET=radiohmwk
CXX=g++

$(TARGET): hmwk.o
	$(CXX)  -I /usr/local/root_v5.34.11/include/root -L/usr/local/root_v5.34.11/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic hmwk.o -o $(TARGET)

hmwk.o:radiohmwk.cc
	$(CXX) -I  /usr/local/root_v5.34.11/include/root -c radiohmwk.cc -o hmwk.o
