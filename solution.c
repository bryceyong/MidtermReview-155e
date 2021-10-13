#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printIntArray(const int *arr, int n) {

  printf("[");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n", arr[n-1]);

}

void printDoubleArray(const double *arr, int n) {
  printf("[");
  for(int i=0; i<n-1; i++) {
    printf("%.2f, ", arr[i]);
  }
  printf("%.2f]\n", arr[n-1]);
}

double * scale(const double *arr, int n, double factor) {
  if(arr == NULL || n<=0){
    return NULL;
  }
  double * result = (double *)malloc((n + 1) * sizeof(double)); // allocating memory for result
  int i = 0;
  for(i=0; i<n; i++){
    result[i] = (arr[i] * factor);
  }
  return result;
}

int getMinMax(const int *arr, int n, int *minValue, int *maxValue) {
  if(arr == NULL || minValue == NULL || maxValue == NULL || n<=0){ //error checking
    return 1;
  }
  int min = arr[0];
  int max = arr[0];
  int i = 0;
  for(i=0; i<n; i ++){
    if(arr[i] <= min){ //for min
      min = arr[i];
    }
    *minValue = min;
    if(arr[i] >= max){ // for max
      max = arr[i];
    }
    *maxValue = max;
  }
  return 0;
}

int closestValues(const double *arr, int n, int *indexA, int *indexB) {
  if(arr == NULL || indexA == NULL || indexB == NULL || n <=0 ){ //error checking
    return 1;
  }

  //initialize values
  int a = 0;
  int b = 1;
  int diff = fabs(arr[a] - arr[b]);
  int closestDiff = diff;

  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i != j){
            diff = fabs(arr[i] - arr[j]);
            if(diff < closestDiff){
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

  double doubleInput[] = {2.71, -5.3, 0, -0.2, 123.45};
  int intInput[] = {10, -5, 3, 4, 21, 0, 45};
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