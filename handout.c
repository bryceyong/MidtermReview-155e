/** Bryce Yong
* Midterms
* Question 1
* A header file with functions involving arrays
* 23 October 2019
*/

/**
 * This function prints the given integer array of
 * size n to the standard output.
 */
void printIntArray(const int *arr, int n);

/**
 * This function prints the given integer array of
 * size n to the standard output.
 */
void printDoubleArray(const double *arr, int n);

/**
 * This function returns a new array that contains the
 * elements of the given array (of size n) that are scaled
 * by the given factor.  That is, each element in the new
 * array is the element in the old array multiplied by
 * factor.
 */
double * scale(const double *arr, int n, double factor);

/**
 * This function takes an integer array of size n and
 * finds the minimum and maximum elements elements in it.
 * The index of each is stored in the two pass-by-reference
 * variables.
 *
 * For any error conditions, a non-zero error code is
 * returned.
 */
int getMinMax(const int *arr, int n, int *minValue, int *maxValue);


 /**
 * This function finds the two closests values
 * in the given array (which is of size n) and places
 * the indices of the two values in the two pass-by-reference
 * variables.
 *
 * An error code is return in the event of any bad input
 * while zero is returned for no error.
 */
int closestValues(const double *arr, int n, int *indexA, int *indexB);
