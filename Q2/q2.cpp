#include <iostream>
#include <chrono>
#include "libArr.h"
#include "libVec.h"

template <class T>
void runTime ( int (T::*) (int), int);

int main ()
{
  int n {1};
  for (int i {}; i < 7 ; i++)
    {
      std::cout << "for n = " << n << "\nArray : ";
      runTime (& libArr::counter ,n);
      std::cout << "Vector : ";
      runTime (& libVec::counter ,n);
      n *= 10;
    }
}

template <class T>
void runTime (int (T::*f)(int ), int n)
{
  T a;
  int b {};
  auto started = std::chrono::high_resolution_clock::now();
  b = (a.*f)(n);
  auto done = std::chrono::high_resolution_clock::now();
  std::cout << "\t Summation = " << b << "\tduration = " << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count() << std::endl; 
}
