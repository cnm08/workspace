#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#define drand48 1.0/RAND_MAX*rand
#define srand48 srand
#define lambda 0.01
#define max 100000
#define time_max 100000
#define seed 68111

int main()
{ 
  int atom, time, number, nloop;
  double decay;
  FILE *output;

  std::string myoption = "w"; //let's write it
  std::string ofname = "decay100000.dat";
  output=fopen(ofname.c_str(),myoption.c_str());
  number=nloop=max;
  srand48(seed);

  for(time=0; time<=time_max; time++)
  {
    for(atom=1; atom<=number; atom++)
    {
      decay=drand48();
      if(decay<lambda) nloop--;
    }
    number=nloop;
    fprintf(output, "%d\t%f\n", time, (double)number);
  }
  std::cout << "data stored in " << ofname << std::endl;
  fclose(output);

  return 0;
}
