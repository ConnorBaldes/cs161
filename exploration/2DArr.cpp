#include <iomanip>
#include <string.h>
#include <iostream>

using std::endl;
using std::cout;
using std::setw;
using std::cin;

// Creates a 2D array on heap
int ** allocateArr(int rows, int cols);

// Fills array with Multiplication Table
void multTable(int ** arr, int rows, int cols);

// Prints out any 2D array of integers
void printArr(int ** arr, int rows, int cols);

// Frees a 2D array from the heap
void freeArr(int ** arr, int rows);


int main(){
	// Create rows
	int rows, cols;

	// Get input from user about array size
	cout << "How many rows: "; cin >> rows;
	cout << "How many cols: "; cin >> cols;
	
	// Allocate our array
	int ** array = allocateArr(rows, cols);
	
	// Generate the multiplcation table.
	// 	Because the array is on the heap, this
	// 	function will directly modify it
	multTable(array, rows, cols);
	
	// Prints the array
	printArr(array, rows, cols);
	
	// Frees the array from the heap
	freeArr(array, rows);
	
	return 0;
}

/*************************************************************
 *	Allocate Arr
 *		Purpose: Allocates an array on the heap
 *		Params: rows -> integer representing the number
 *							of rows for the array
 *				cols -> Integer representing the number
 *							of columns for the array
 *		Returns: The address of the start of a 2D array of
 *					integers
 *		Pre-Conditions: N/A
 *		Post-Conditions: There will be an array of size
 *							rows * cols on the heap
 ************************************************************/

int ** allocateArr(int rows, int cols){
	// Create an array of int *, store in int **
	int ** arr = new int * [rows];

	// For the number of rosws
	for(int i = 0; i < rows; i++){
		// Set the value of the int * at location arr[i] to an
		// 	array of integers with size cols
		arr[i] = new int [cols];
	}

	// Return the address of the start of the 2D array
	return arr;
}


/*************************************************************
 *	Mult(iplication) Table
 *		Purpose: Fills a 2D array with values representing a
 *					multiplication table
 *		Params: Arr  -> A 2D integer array. If on the heap,
 *							it must be allocated
 *				rows -> integer representing the number
 *							of rows the array has
 *				cols -> Integer representing the number
 *							of columns the array has
 *		Returns: None
 *		Pre-Conditions: If the array that is provided is on
 *							the heap, it must be allocated.
 *							Arrays from the stack are fine,
 *							but rows/cols must be accurate
 *		Post-Conditions: There values stored in the array will
 *							be modified to represent a
 *							multiplication table
 ************************************************************/
void multTable(int ** arr, int rows, int cols){
	// For all the rows
	for(int i = 0; i < rows; i++){
		// For all the columns
		for(int j = 0; j < cols; j++){

			// Set the current location to the value of
			// 		(i + 1) * (j + 1)
			arr[i][j] = (i + 1) * (j + 1);
		}
	}
}


/*************************************************************
 *	print Arr
 *		Purpose: Prints a 2D integer array in a clean format
 *		Params: Arr  -> A 2D integer array. If on the heap,
 *							it must be allocated
 *				rows -> integer representing the number
 *							of rows the array has
 *				cols -> Integer representing the number
 *							of columns the array has
 *		Returns: None
 *		Pre-Conditions: If the array that is provided is on
 *							the heap, it must be allocated.
 *							Arrays from the stack are fine,
 *							but rows/cols must be accurate
 *		Post-Conditions: No values will be changed
 ************************************************************/
void printArr(int ** arr, int rows, int cols){
	// For all the rows
	for(int i = 0; i < rows; i++){
		// For all the cols
		for(int j = 0; j < cols; j++){
			// Set the width of the current value to 4
			//  (show all numbers <1000 cleanly
			//  
			//  Then print the value
			cout << setw(4) << arr[i][j];
		}
		// Print a new line
		cout << endl;
	}
}

/*************************************************************
 *	free Arr
 *		Purpose: Frees an aray from the heap
 *		Params: Arr  -> A 2D integer array. If on the heap,
 *							it must be allocated
 *				rows -> integer representing the number
 *							of rows the array has
 *		Returns: None
 *		Pre-Conditions: If the array that is provided is on
 *							the heap, it must be allocated.
 *							Arrays from the stack CANNOT be
 *							sent to this function
 *		Post-Conditions: The heap will no longer have the
 *							array on it
 ************************************************************/
void freeArr(int ** arr, int rows){
	// For all the rows	
	for(int i = 0; i < rows; i++){
		// Remove array of ints from the heap for this row
		delete	[] arr[i];
	}
	
	// Remove the array of int *'s from the heap
	delete [] arr;
}



