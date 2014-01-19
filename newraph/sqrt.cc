

#include <iostream>

#include "MyFunc.h"

int main()
{
  double square; 
  std::cout << "Enter a number between 0 and 100: ";
  std::cin >> square;

  double squareroot = MySquareRoot(square);

  std::cout << "The square root of your number is: " << squareroot << std::endl; 


  return 0;
}





