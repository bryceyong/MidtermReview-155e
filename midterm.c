
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printIntArray(const int *arr, int n) {
  //TODO:implement this
}

void printDoubleArray(const double *arr, int n) {
  //TODO:implement this
}

double * scale(const double *arr, int n, double factor) {

  //TODO:implement this
}

int getMinMax(const int *arr, int n, int *minValue, int *maxValue) {

  //TODO:implement this
}

int closestValues(const double *arr, int n, int *indexA, int *indexB) {

  //TODO:implement this
}

int main(int argc, char **argv) {

  double doubleInput[] = {2.71, -5.3, 0, 123.45, -0.2};
  int intInput[] = {10, -5, 3, 21, 4, 0, 10};
  int n = 5;

  //testing printIntArray
  printIntArray(intInput, n);

  //testing printDoubleArray
  printDoubleArray(doubleInput, n);

  //testing scaled
  double *scaleResult = scale(doubleInput, n, 0.5);
  printDoubleArray(scaleResult, n);

  //testing getMinMax
  int min, max;
  getMinMax(intInput, n, &min, &max);
  printf("minimum: %d, ", min);
  printf("maximum: %d \n", max);


  //testing closestValues
  int indexA, indexB;
  closestValues(doubleInput, n, &indexA, &indexB);
  printf("Closest indices: %d, %d\n", indexA, indexB);


  return 0;
}
