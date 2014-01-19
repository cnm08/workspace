

#include "Walker.h"


// constructor of walker class
Walker::Walker()
{
	std::cout << "In Constructor for Walker" << std::endl;
	// initialize member variables of the class
	displ = 0;
	xtot  = 0;
	ytot  = 0;
	range = 0; 

}

//destructor
Walker::~Walker()
{
	std::cout << "In Destructor for Walker" << std::endl;
}


void Walker::setOrigin(double xorig, double yorig)
{
	std::cout << "Setting Origin" << std::endl;
	xpos.push_back(xorig);
	ypos.push_back(yorig);

}


void Walker::step(double xstep, double ystep)
{

   xpos.push_back(xpos.back() + xstep);
   ypos.push_back(ypos.back() + ystep);

   xtot += std::fabs(xstep);
   ytot += std::fabs(ystep);

}

void Walker::calcDispl()
{
	if( (!xpos.empty()) && (!ypos.empty()) ) {
		double xdist = (xpos.back() - xpos.front());
		double ydist = (ypos.back() - ypos.front());

		displ = std::sqrt(std::pow(xdist, 2)+ std::pow(ydist, 2)); 
	} else {
		std::cout << "x position or y position vector is empty " << std::endl;
	
	}

}

// call calcRange after all steps have been taken
void Walker::calcRange()
{
	range = std::sqrt(std::pow(xtot, 2)+std::pow(ytot, 2)); 

}

double Walker::getRange()
{
	return range;
}

int Walker::getNSteps()
{
	if ( (!xpos.empty()) && (!ypos.empty()) ) {
		if (xpos.size() == ypos.size() ) {
			return xpos.size() - 1;
                }
        } else {
		std::cout << "ERROR position arrays are empty" << std::endl;
	}
}

void Walker::myPrint()
{
	if (xpos.size() != ypos.size()) {
		std::cout << "ERROR wrong Walker uses 1 foot more than the other" << std::endl;
		return;
	}
	for (int i = 0; i < xpos.size(); i++) {
		std::cout << std::setw(10) << xpos.at(i) << std::setw(10) << ypos.at(i) << std::endl;

	}


}

