/*******************************************************************************
   Filename: arrays.c

     Author: David C. Drake (https://davidcdrake.com)

Description: Contains five functions that use and/or modify arrays, including
             "reverse_array", "add_arrays", "scalar_multiply", "dot_product",
             and "cross_product".
*******************************************************************************/

/*******************************************************************************
   Function: reverse_array

Description: Reverses the order of elements in an array.

     Inputs: a    - An array of integers (to be reversed).
             size - An integer corresponding to the number of elements in "a".

    Outputs: None (but array "a" is modified).
*******************************************************************************/
void reverse_array(int a[], int size) {
  int index1 = 0,
      index2 = size - 1,
      value1,
      value2;

  if (size < 2) {
    return;
  }

  while (index1 < index2) {
    value1 = a[index1];
    value2 = a[index2];
    a[index1++] = value2;
    a[index2--] = value1;
  }
}

/*******************************************************************************
   Function: add_arrays

Description: Adds the elements of two arrays and puts the sum of each pair of
             elements into a third array. All arrays should be of equal size.

     Inputs: a    - An array of integers (not to be modified).
             b    - An array of integers (not to be modified).
             c    - An array of integers (to contain the sums of elements from
                    "a" and "b").
             size - An integer corresponding to the number of elements in each
                    array.

    Outputs: None (but array "c" is modified).
*******************************************************************************/
void add_arrays(const int a[], const int b[], int c[], int size) {
  int i;

  for (i = 0; i < size; i++) {
    c[i] = a[i] + b[i];
  }
}

/*******************************************************************************
   Function: scalar_multiply

Description: Multiplies each element of an array by a given value.

     Inputs: a          - The array of integers to be modified.
             size       - The number of elements in "a".
             multiplier - The integer to be multiplied to each element in "a".

    Outputs: None (but array "a" is modified).
*******************************************************************************/
void scalar_multiply(int a[], int size, int multiplier) {
  int i;

  for (i = 0; i < size; i++) {
    a[i] *= multiplier;
  }
}

/*******************************************************************************
   Function: dot_product

Description: Returns the scalar (integer) dot product of two vectors (arrays of
             integers) of equal size. The dot product is computed by summing
             the product of each pair of elements:
                (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]) + ...

     Inputs: a    - An array of integers (not to be modified).
             b    - An array of integers (not to be modified).
             size - An integer corresponding to the number of elements in each
                    array.

    Outputs: The scalar (integer) dot product of the two arrays.
*******************************************************************************/
int dot_product(const int a[], const int b[], int size) {
  int i, sumOfProducts = 0;

  for (i = 0; i < size; i++) {
    sumOfProducts += a[i] * b[i];
  }

  return sumOfProducts;
}

/*******************************************************************************
   Function: cross_product

Description: Takes two vectors (arrays of integers), calculates their cross
             product, and stores the cross product in another vector (array).

     Inputs: a - An array of integers (not to be modified).
             b - An array of integers (not to be modified).
             c - An array of integers (to contain the cross product of "a" and
                 "b").

    Outputs: None (but array "c" is modified).
*******************************************************************************/
void cross_product(const int a[], const int b[], int c[]) {
  c[0] = a[1] * b[2] - a[2] * b[1];
  c[1] = a[2] * b[0] - a[0] * b[2];
  c[2] = a[0] * b[1] - a[1] * b[0];
}
