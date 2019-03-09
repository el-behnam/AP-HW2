#include "libVec.h"
#include <iostream>
#include <vector>

int libVec::counter(int N)
{
  std::vector <int> vec {};
  int sum {};
  for (int i {}; i < N; i++)
    vec.push_back(i+1);
  for (int i {}; i < N; i++)
    sum += vec[i];
  return sum;
}
