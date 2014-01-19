

#include <iostream>
#include <iomanip>
#include <cmath>

#include "TRandom3.h"

#include "Walker.h"


int main()
{

	Walker mywalker;
        mywalker.setOrigin(0.0, 0.0);

	//set up random number generator
	TRandom3 myrand(42);

	// determine number of steps
	int nsteps = 10000;

	// loop over n steps
	for ( int steps =0; steps < nsteps; steps++){
		// throw two random numbers, assign to delx and dely	
		double delx=(myrand.Rndm() -0.5)*2*std::sqrt(2.0);
		double dely=(myrand.Rndm() -0.5)*2*std::sqrt(2.0);
		mywalker.step(delx, dely); 
		
		
	}
	std::cout << std::setw(13) << "   x    " << std::setw(13) << "  y   " << std::endl;
	mywalker.myPrint();
	// step through with random walker

	return 0; 


}
