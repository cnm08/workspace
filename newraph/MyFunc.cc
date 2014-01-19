

#include "MyFunc.h"



double MySquareRoot(double square)
{
  double lower, upper, root, sign;
  lower = 0.1;
  upper = 10.1;
  //double c = square;
  double result1 = 0;
  double result2 = 0;

  for (int i = 0; i < 60; i++) {
    root = (upper + lower)/2.0;
    result1 = square - lower*lower;
    result2 = square - root*root;

    sign = result1*result2;
    if (sign < 0) {
      upper = root;
    } else {
      lower = root;
    }

  } //end for

  return root;
} // end function
