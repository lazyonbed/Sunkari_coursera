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
 * @file <stats.h> 
 * @brief <Header file for function declartion >
 *
 * <Add Extended Description Here>
 *
 * @author <Anoorag Sunkari>
 * @date <05/02/2020 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief A function that prints the statistics of an array including minimum, 
 * maximum, mean, and median.
 *
 *array The array containing the dataset of unsigned chars
 *length The length of the array
 *
 * @return NULL
 */
void print_statistics(unsigned char array[], unsigned int length);




/** 
 * @brief Given an array of data and a length, prints the array to the screen
 *
 *An array of unsigned chars
 *length The length of the array
 *
 *@return NULL
 */
void print_array(unsigned char array[], unsigned int length);




/** 
 * @brief Given an array of data and a length, returns the median value
 *
 * array An array of unsigned chars
 * length The length of the array
 *
 * @return median The median of the array
 */
unsigned char find_median(unsigned char array[], unsigned int length);




/** 
 * @brief Given an array of data and a length, returns the min value
 *
 * array An array of unsigned chars
 * length The length of the array
 *
 * @return median The min of the array
 */
unsigned char find_min(unsigned char array[], unsigned int length);



/** 
 * @brief Given an array of data and a length, returns the max value
 *
 * array An array of unsigned chars
 * length The length of the array
 *
 * @return median The max of the array
 */
unsigned char find_max(unsigned char array[], unsigned int length);




/** 
 * @brief Given an array of data and a length, returns the mean value
 *
 * array An array of unsigned chars
 * length The length of the array
 *
 * @return median The mean of the array
 */
unsigned char find_mean(unsigned char array[], unsigned int length);




/** 
 * @brief Sorts the array in descending order
 * using quick sort.
 * array An array of unsigned chars
 * length The length of the array
 */
void sort_array(unsigned char array[], unsigned int length);

#endif /* __STATS_H__ */