#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// dynamically allocating array in a function
int* readArray(int size){
  int* p = (int*)malloc(size*sizeof(int));
  for(int i = 0; i<size; i++){
    //scanf("%d", &p[i]);
    p[i] = rand()%100;
  }
  return p;
}

int findMax(int arr[], int len){
  int i, max = arr[0];
  for(i = 0; i<len; i++){
    if(arr[i]>max)
      max = arr[i];
  }
  return max;
}

// how to call it from a function
int main(void) {
  int size;
  int *myarr;
  // scans from user input how many numbers to allocate for the dynamic array
  printf("How many numbers?");
  scanf("%d", &size);
  // call function readArray with the users size
  myarr = readArray(size);

  printf("Printing the array from main function: ");
  for(int i = 0; i<size; i++)
    printf("%d ", myarr[i]);

  printf("\n The max number in the array is %d", findMax(myarr, size));
  // now you can use numbers like an array of size
  free(myarr);
}