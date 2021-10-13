
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printIntArray(const int *arr, int n) {
  for(int i=0; i<n; i++){
    printf("%d\n", arr[i]);
  }
}

void printDoubleArray(const double *arr, int n) {
  for(int i=0; i<n; i++){
    printf("%lf\n", arr[i]);
  }
}

double * scale(const double *arr, int n, double factor) {

  double * scaleArray = (double *)malloc(sizeof(double) * n);
  for(int i=0; i<n; i++){
    scaleArray[i] = arr[i] * factor;
  }
  return scaleArray;
}

int getMinMax(const int *arr, int n, int *minValue, int *maxValue) {

  if(arr == NULL || n < 0 || minValue == NULL || maxValue == NULL){
    return 1;
  }

  int min = arr[0];
  int max = arr[0];

  for(int i=0; i<n; i++){
    if(arr[i] < min){
      min = arr[i];
    }
    if(arr[i] > max){
      max = arr[i];
    }
  }
  *minValue = min;
  *maxValue = max;

  return 0;
}

int closestValues(const double *arr, int n, int *indexA, int *indexB) {

  if(arr == NULL || n < 0 || indexA == NULL || indexB == NULL){
    return 1;
  }


  int diff = fabs(arr[0] -arr [1]);
  int a = 0;
  int b = 1;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i != j){
        if((fabs(arr[i] - arr[j])) < diff){
        diff = fabs(arr[i]- arr[j]);
        printf("%f\n", arr[i]);
        printf("%f\n", arr[j]);
        a = i;
        b = j;
        }
      }
    }
  }
  *indexA = a;
  *indexB = b;
  return 0;
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