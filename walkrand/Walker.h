
#ifndef WALKER_H
#define WALKER_H

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

class Walker {
        
	public: 
               Walker(); // constructor
               ~Walker();	
	        double getDispl();
                void calcRange();
                void calcDispl();
                void step(double xstep, double ystep);
		void setOrigin(double xorig, double yorig);
                int getNSteps();
                double getRange();
		void   myPrint();
	private:  
		std::vector <double> xpos, ypos;
		double displ;
		double xtot;
	 	double ytot;
		double range; 
		

}; //end of class definition; note the semicolon after the curly bracket



#endif

