#include <iostream>
#include <cmath>

#include "TRandom3.h"




double func(double array[], int size) // declaring the function
{
  double tot = 0;

  for (int u = 0; u < size; u++) {
    tot += array[u];
  }
  double totsquared = pow(tot, 2);

  return totsquared;
}


int main() {
  const int dim=10;  // number of dimensions of integrand
  int Nsamples = 0;

  TRandom3* myrnd = new TRandom3();

  double funArray[dim];

  const int powMax = 13;
    
  // prevent the array from being garbage by initializing it
  for (int k = 0; k < dim; k++) {
    //std::cout << "Initializing array element " << k << std::endl;
    funArray[k] = 0.;
  }
  
  /* let's DO IT - Big Ol' Loop */
  for (int index = 0; index < powMax; index++) {
    Nsamples = pow(2, index+1);
    double eval = 0;  // variable representing the total for expressing the integral as a sum
    for (int i = 0; i < Nsamples; i++)
    {
      for (int p = 0; p < dim; p++) {
        // throw random numbers
        funArray[p] = myrnd->Rndm(); 
      }
      eval += func(funArray, dim);    
    }

    // take the average
    double integral = eval/Nsamples;
    std::cout << "The integral for " << Nsamples << " samples = " << integral << std::endl;
  }
  // free dynamically allocated memory to prevent a memory leak
  delete myrnd;

  return 0;
}

