#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#include "TRandom3.h"




double func(double array[], int size)// declaring the function
{
  double tot = 0;

  for (int u = 0; u < size; u++) {
    tot += array[u];
  }
  double totsquared = pow(tot, 2);

  return totsquared;
}


int main() {

  std::ofstream stevenoob; 
  stevenoob.open("standarddev.txt"); 
  const int dim=10;  // number of dimensions of integrand
  int Nsamples = 0;

  TRandom3* myrnd = new TRandom3();

  const int mySeed = 10;
  myrnd->SetSeed(mySeed);

  double funArray[dim];
  double variance = 0;
  const int powMax = 15;
    
  // prevent the array from being garbage by initializing it
  for (int k = 0; k < dim; k++) {
    //std::cout << "Initializing array element " << k << std::endl;
    funArray[k] = 0.;
  }

  
  
  
  const int Ntrials = 32;
  
  double integralsum=0; 
  std::cout << "number of samples " <<" average integral " << "standard Deviation" << std::endl;
  /* let's DO IT - Big Ol' Loop */
  for (int index = 0; index < powMax; index++) { // Changing the sample size 
      integralsum=0; 

      // declare empty array of size Ntrials
      //syntax to declare array of doubles with size Ntrials

      double integralarray[Ntrials]; // integralarray holds the values of the integrals that are evaluate 
      double sumsq[Ntrials];

      //
      for (int s = 0; s< Ntrials; s++) {
         integralarray[s]=0.;
         sumsq[s]=0.;
      }
      
      for (int nt = 0; nt < Ntrials; nt++) { // doing Ntrials 
          // conducting 16 trials   
          Nsamples = pow(2, index+1);
          


         double eval = 0;  // variable representing the total for expressing the integral as a sum
         for (int i = 0; i < Nsamples; i++) {
               for (int p = 0; p < dim; p++) {
                   // throw random numbers
                   
                   funArray[p] = myrnd->Rndm(); 
               }
               eval += func(funArray, dim);
          }

          // take the average
          double integral = eval/Nsamples;
          
          //std::cout << "The integral for " << Nsamples << " samples = " << integral << std::endl;
          integralsum += integral;
          // assign integralarray[nt] to array for use with standard deviation
          integralarray[nt]= integral; // this stores the integral over the number of trials for each sample size
      } // done evaluating integral Ntrials times
      double averageint = integralsum/Ntrials;
      
      // now perform another loop over the integralarray and assign sumsq[j] = (integralarray[j] - averageint)^2
      
      
       
      for (int sntc = 0; sntc < Ntrials; sntc++) { // doing Ntrials 
          sumsq[sntc]= std::pow( (integralarray[sntc]-averageint), 2);   
      }
      // now that you have the average....
      // make a dummy counter for the sum of the squares (call it sumsq)
      // loop over the array with the Ntrials integral values
      // calculate (x - avgint)^2 [where x is the ith integral array element)
      // sum the elements
      // divide by Ntrials and take the square root to get the standard deviation
      double bigSum = 0.;
      for (int varctr = 0; varctr < Ntrials; varctr++) { // doing Ntrials
         bigSum += sumsq[varctr];  // this is sum_i..Ntrials { ((integral[i] - avgintegral[i])^2 }
      }
 
       double variance = bigSum/Ntrials;
       double stdDev   = std::sqrt(variance);

      //loop over array or vector with integrals stored
      
      std::cout << std::setw(25) << std::left << Nsamples << std::setw(15) << std::setprecision(8) << averageint <<  std::setw(15) << std::setprecision(6) << stdDev <<std::endl;
      stevenoob << std::setw(25) << std::left << Nsamples << std::setw(15) << std::setprecision(8) << averageint <<  std::setw(15) << std::setprecision(6) << stdDev <<std::endl;
 
  }


  // x will be real value - averageint   
  // Tgraph *graph1 = new TGraph(x,y);
  // graph1 -> Draw("CP"); 
  // free dynamically allocated memory to prevent a memory leak
  delete myrnd;
  stevenoob.close(); 

  return 0;
}

