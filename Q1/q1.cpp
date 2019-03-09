#include"map.h"
#include<iostream>
#include <ctime>

int main()
{
  int n{},a{};
  std::cout << "Please enter number of regions : ";
  std::cin >> n;
  std::cout <<"Please enter part 1 or 2 or 3 : " ;
  std::cin>> a;
  std::srand(time(0));
  map g{n};
  g.showMap();
  if (a == 1)
    g.findRoute1();
  if (a == 2)
    g.findRoute2();
  if (a == 3)
    g.findRoute3();
  g.showRoute();
  return 0;
}
