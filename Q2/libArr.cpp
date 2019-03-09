#include "libArr.h"
#include <iostream>

int libArr::counter(int N)
{
  int arr[N]{};
  int sum {};
  for (int i {}; i < N; i++)
    arr[i] = i+1;
  for (int i {}; i < N; i++)
    sum += arr[i];
  return sum;
}
