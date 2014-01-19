

#include <iostream>

#include "TRandom3.h"


int main()
{
  
  double N, lambda, Nleft;
  N = 10.e3;
  lambda = 0.3;
  Nleft = N;


  TRandom3 myrand(504);

  if (N < 0) std::cout << "You idiot, even I know that N has to be positive" << std::endl;
  do {
    for (int i = 0; i < N; i++) {
      double local =  myrand.Rndm(i);
      //std::cout << "Local = " << local << std::endl;

      if (local <= lambda) {
        Nleft--;
	
      }

    }  // end for 
     std::cout << "N = " << N << " Decay Rate = " << lambda*(N-Nleft) << std::endl;
    N = Nleft;
  } while(N > 0); // end while

  return 0;
} // end main
