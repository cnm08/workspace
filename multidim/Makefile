
integral: integral.o
	g++ -o integral integral.o -L/usr/local/root_v5.34.11/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic

integral.o: integral.cxx
	g++ -c integral.cxx -I/usr/local/root_v5.34.11/root/include
