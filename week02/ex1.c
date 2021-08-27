#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  int _integer = INT_MAX;
  double _double = DBL_MAX;
  float _float = FLT_MAX;
  printf("Size of int: %lu, Size of double: %lu, Size of float: %lu\n Max "
         "value of integer: %d,\n max value of double: %lf,\n max value of float: %f",
         sizeof(int), sizeof(double), sizeof(float), _integer, _double, _float);
  return 0;
}
