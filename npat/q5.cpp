#include <iostream>

using namespace std;

int maxConsecutive(int *a, int n, int m) {
  int sum = 0;
  for(int i = 0; i < m; i++) {
    sum += a[i];
  }
  int max = sum;
  for(int i = m; i < n; i++) {
      
  }
  return max;
}