randomwalk : randomwalk.o Walker.o
	g++ -o randomwalk randomwalk.o Walker.o -L/usr/local/root_v5.34.11/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic

randomwalk.o: randomwalk.cxx Walker.h
	g++ -c randomwalk.cxx  -I/usr/local/root_v5.34.11/root/include

Walker.o: Walker.cxx Walker.h
	g++ -c   Walker.cxx

