#include "map.h"
#include <iostream>
#include <vector>
#include <algorithm>

map::map (int N)
{
  std::cout << "I am born =))) " << std::endl;
  n = N;
  height = new int* [n];
  for(int i{}; i < n; i++)
    height[i] = new int[n]{};
  for (int i{}; i < n; i++)
    for (int j{}; j < n; j++)
      height[i][j] = rand() % 100;
  
  route = new int* [n];
  for(int i{}; i < n; i++)
    route[i] = new int[n]{};
}

void map::showMap ()
{
  for (int i{}; i < n; i++)
    {
      for (int j{}; j < n; j++)
	std::cout << height [i][j] << "\t";
      std::cout << std::endl;
    }
}

void map::showRoute ()
{
  std::cout << "Route : \n";
  for (int i{}; i < n; i++)
    {
      for (int j{}; j < n; j++)
	if (route [i][j] == 1)
	  std::cout <<  "+" << "\t";
	else
	  std::cout << "-" << "\t";
      std::cout << std::endl;
    }
}

void map::findRoute1()
{
  distance=0;
  int r{}, c{};
  for (int i{}; i < n; i++)
    for (int j{}; j < n; j++)
      route[i][j] = 0;
  
  route[0][0]=1;
  while (r < n-1 && c < n-1)
    {
      route[r][c] = 1;
      if (std::abs(height[r][c]-height [r+1][c]) < std::abs(height[r][c]-height[r][c+1]))
	{
	  distance += std::abs(height[r][c]-height[r+1][c]);
	  r++;
	}
      else
	{
	  distance += std::abs(height[r][c]-height [r][c+1]);
	  c++;
	}
    }
  if (r == n-1)
    for (int i{c}; i < n-1; i++)
      {
	route[r][i] = 1;
	distance += std::abs(height[r][c]-height [r][c+1]);
      }
  else
    for (int i{r}; i < n-1; i++)
      {
	route [i][c] = 1;	
	distance += std::abs(height[r][c]-height [r+1][c]);
      }
  route [n-1][n-1] = 1;
  std::cout << "Distance : " << distance << std::endl;
}

void map::findRoute2()
{
  distance=0;
  int r{}, c{};
  for (int i{}; i < n; i++)
    for (int j{}; j < n; j++)
      route[i][j] = 0;
  route[0][0]=1;
  while (r < n-1 && c < n-1)
    {
      route[r][c] = 1;
      if (std::abs(height[r][c]-height [r+1][c]) < std::abs(height[r][c]-height[r][c+1]))
	{
	  if (std::abs(height[r][c]-height [r+1][c]) < std::abs(height[r][c]-height[r+1][c+1]))
	    {
	      distance += std::abs(height[r][c]-height[r+1][c]);
	      r++;
	    }
	  else
	    {
	      distance += std::abs(height[r][c]-height[r+1][c+1]);
	      r++;
	      c++;
	    }
		
	}
      else
	{
	      
	  if (std::abs(height[r][c]-height [r][c+1]) < std::abs(height[r][c]-height[r+1][c+1]))
	    {
	      distance += std::abs(height[r][c]-height[r][c+1]);
	      c++;
	    }
	  else
	    {
	      distance += std::abs(height[r][c]-height[r+1][c+1]);
	      r++;
	      c++;
	    }
	}
    }
  if (r == n-1)
    while(c < n-1)
      {
	route[r][c] = 1;
	distance += std::abs(height[r][c]-height [r][c+1]);
	c++;
      }
  if (c == n-1)
    while(r < n-1)
      {
	route [r][c] = 1;	
	distance += std::abs(height[r][c]-height [r+1][c]);
	r++;
      }
  route [r][c] = 1; 
  std::cout << "Distance : " << distance << std::endl;
}


void map::findRoute3()
{
  int min{2 * n * 100};
  int now{};
  int r{} , c{};
  std:: vector <int> arrows {};
  for (int i{}; i < n-1; i++)
    {
      arrows.push_back(1);
      arrows.push_back(2);
    }
  do
    {
      r = 0;
      c = 0;
      now = 0;
      for(size_t i{0}; i < arrows.size() ; i++)
	{
	  if (arrows[i] == 1 )
	    {
	      now += std::abs(height[r][c]-height[r][c+1]);
	      c++;
	    }
	  else if(arrows[i] == 2)
	    {
	      now += std::abs(height[r][c]-height[r+1][c]);
	      r++;
	    }
	}
	  if (now < min )
	    {
	      min = now;
	      for (int i{}; i < n; i++)
		for(int j{}; j<n; j++)
		  route[i][j] =0;
	      r = 0;
	      c = 0;
	      for(size_t i{0}; i < arrows.size() ; i++)
		{
		  route[r][c] = 1;
		  if (arrows[i] == 1 )
		    c++;
		  else
		    r++;

		}
	      route[r][c] = 1;
	    }
    }while (std::next_permutation(arrows.begin(),arrows.end()));
  distance = min;
  std::cout << "Distance : " << distance << std::endl;      
}


map::~map ()
{
  std::cout << "I am dying..."<<std::endl;
  delete [] height;
  height = nullptr;
  delete [] route;
  route = nullptr;
}
