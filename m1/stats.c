/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <This Program is designed to analyze the data set presented to us. >
 *@Extended Description< Sort the data, then find mean, median of the data set. Find the minimum and maximum value in the data set>
 *
 * @author < Anoorag Sunkari>
 * @date <05/02/2020>
 *
 */
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
print_statistics(test,SIZE);
return 0;
}

/* Add other Implementation File Code Here */
//Function created to print all the statistics.
void print_statistics(unsigned char *array,unsigned int length){
  printf("\nArray: \n");
  print_array(array, length);
  printf("\nSorted Array:\n");
  sort_array(array, length);
  printf("\nMedian: %d\n", find_median(array, length));
  printf("Mean: %d\n", find_mean(array, length));
  printf("Max: %d\n", find_max(array, length));
  printf("Min: %d\n", find_min(array, length));
}


//Using Quick sort to arrange the elements of the array in descending order
void sort_array(unsigned char *array, unsigned int length){
  unsigned char temp;
  for(int i= length; i>=0;i--){
    for(int j=i; j>=0;j--){
      if(array[j]<array[i]){
        temp=array[j];
        array[j]=array[i];
        array[i]=temp;
      }
    }
  }
  print_array(array, length);
}


void print_array(unsigned char *array, unsigned int length){
   for(length = 0; length < SIZE; length++)
      printf("%d ", array[length]);
}

unsigned char find_median(unsigned char array[], unsigned int length){
  unsigned int median=0;
  // if number of elements are even
  if(length%2 == 0)
    median = (array[(length-1)/2] + array[length/2])/2.0;
  // if number of elements are odd
  else
    median = array[length/2];
    
  return median;
}

unsigned char find_mean(unsigned char *array, unsigned int length){
  unsigned int sum=0;
  for(int i=0;i<length; i++){
    sum+=array[i];
  }
  return(sum/length);
}

unsigned char find_max(unsigned char *array, unsigned int length){
  int max=array[0];
  for( int i=1;i<length; i++){
    if(array[i]>max){
      max=array[i];
    }
  }
  return (unsigned char)max;
}

unsigned char find_min(unsigned char *array, unsigned int length){
  int min=array[0];
  for( int i=1;i<length; i++){
    if(array[i]<min){
      min=array[i];
    }
  }
  return (unsigned char)min;
}