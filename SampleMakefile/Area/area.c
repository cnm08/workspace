


#include <stdio.h>

#define pi 3.141592653

int main()
{


  double r = 0.;
  double A = 0.;

  printf("Enter the radius of the circle: ");
  scanf("%lf", &r);

  A = r*r*pi;

  printf("radius r = %f, area A = %f\n", r, A);

  return 0;
}
