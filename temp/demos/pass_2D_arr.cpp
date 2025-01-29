

//passing 2d arrays


#include <iostream>

using namespace std;

//function prototypes
/*Static 2D array functions*/
void static_init(int a[][3], int row, int col);
void static_print(int a[][3], int row, int col);

/*Dynamic 2D array functions*/
int** dyn_creation1(int row, int col);
void dyn_creation2(int*** a, int row, int col);
void dyn_creation3(int** &a, int row, int col);
void dyn_init(int** a, int row, int col);
void dyn_print(int** a, int row, int col);
void dyn_delete(int **a, int row);


int main()
{
	/*****************Static 2D array**********/
	/*Note: You don't want to create a static array in another function,
	because when you leave that function, everything is popped off stack
	*/
	cout << "\nSTATIC 2D array" << endl;
	int static_arr [2][3];			//Create a 2D static array on the stack
	static_init(static_arr, 2, 3);	//Initialize the array
	static_print(static_arr, 2, 3); //Print the array


	/*****************Dynamic 2D array**********/
	cout << "\nDYNAMIC 2D array" << endl;
	int **dyn_arr = NULL;

	/*Different ways to create a 2D array
	Uncomment each to test out :)
	Note: only call creation function once to avoid memory leaks
	*/
	dyn_arr = dyn_creation1(2, 3);	//allocate the memory for the array
	//dyn_creation2(&dyn_arr, 2, 3);
	//dyn_creation3(dyn_arr, 2, 3);

	dyn_init(dyn_arr, 2, 3);		//Initialize the array
	dyn_print(dyn_arr, 2, 3);		//Print the array
	dyn_delete(dyn_arr, 2);			//Delete the array (free the heap memory)

	return 0;
}

/**************************************
 * Function: static_init
 * Description: Initialize the 2D static array with rows * cols
 * Parameters:
 *      int a[][3]  - array to be initialized, you can specify
 					  both rows and cols, but only cols (strides) matters
 		int row 	- number of rows of the array
 *      int col 	- number of cols of the array
 * Returns: nothing
 * Pre-Conditions:  The static array of the given size
 * Post-Conditions: A static array is filled with all 0s
**************************************/
void static_init(int a[][3], int row, int col)
{
	for (int i = 0; i < row; i++)     	//rows will be outer loop
		for (int j = 0; j < col; j++)	//columns will be inner loop
			a[i][j] = 0;				//assign 0 to element at row i col j
}


/**************************************
 * Function: static_print
 * Description: print out each element of the 2D static array with rows * cols
 * Parameters:
 *      int a[][3]  - array to be printed, you can specify
 					  both rows and cols, but only cols (strides) matters
 		int row 	- number of rows of the array
 *      int col 	- number of cols of the array
 * Returns: nothing
 * Pre-Conditions:  The static array of the given size
 * Post-Conditions: The array will be printed, no modifications made to the array
**************************************/
void static_print(int a[][3], int row, int col)
{
	for (int i = 0; i < row; i++)		//rows will be outer loop
	{
		for (int j = 0; j < col; j++)	//columns will be inner loop
			cout << a[i][j] << " ";		//print out the content at row i col j

		cout << endl;
	}
}

/**************************************
 * Function: dyn_creation1
 * Description: allocate memory for a 2D dynamic array by the given size, and return the 
 				memory address (pointer) of the 2D array
 * Parameters:
 		int row 	- number of rows of the array
 *      int col 	- number of cols of the array
 * Returns: pointers to the 2D dynamic array
 * Pre-Conditions:  none
 * Post-Conditions: The 2D dynamic array is created, and its memory address is returned 
**************************************/
int** dyn_creation1(int row, int col)
{
	int **a;						//create a temporary double pointer on the stack
	a = new int*[row];				//allocate heap memory for row pointers
	for(int i = 0; i < row; i++)	//for each row pointer, allocate heap memory for columns
		a[i] = new int[col];

	return a;						//return the memory address of a, which is now pointing to 
									//a 2D dynamic array
}

/**************************************
 * Function: dyn_creation2
 * Description: given a pointer to a 2D array, allocate memory for it by the given size
 * Parameters:
 		int ***a 	- pointer to a 2D array		
 		int row 	- number of rows of the array
 	    int col 	- number of cols of the array
 * Returns: none
 * Pre-Conditions:  none
 * Post-Conditions: The 2D dynamic array is created, the pointer passed in now points
 					to the array
**************************************/
void dyn_creation2(int*** a, int row, int col)
{
	/*why we need triple pointer here?
	  Since "a" holds the memory address of the double pointer passed in,
	  which means a is pointing to a double pointer, therefore, "a" is a
	  triple pointer.
	*/ 

	*a = new int*[row];				//dereference a once to allocate memory for row pointers
	for(int i = 0; i < row; i++)	//for each row pointer, allocate memory for columns
		(*a)[i] = new int[col];		//the () is necessary, otherwise it will dereference a[i]
									// instead of "a"
}

/**************************************
 * Function: dyn_creation2
 * Description: take a pointer to a 2D array as reference, allocate memory for it by the given size
 * Parameters:
 		int **&a 	- reference to a pointer to a 2D array		
 		int row 	- number of rows of the array
 	    int col 	- number of cols of the array
 * Returns: none
 * Pre-Conditions:  none
 * Post-Conditions: The 2D dynamic array is created, the pointer passed in now points
 					to the array
**************************************/
void dyn_creation3(int** &a, int row, int col)
{
	/*why we do not need triple stars here?
	 We take the double pointer passed in as a reference, which means that 
	 "a" is same as the pointer passed in, so it is also a double pointer.
	 If we change "a" here, the double pointer passed in will be changed too.
	 */
	a = new int*[row];				//allocate heap memory for row pointers
	for(int i = 0; i < row; i++)	//for each row pointer, allocate heap memory for columns
		a[i] = new int[col];

}

/**************************************
 * Function: dyn_init
 * Description: Initialize the 2D dynamic array with rows * cols
 * Parameters:
 *      int **a 	- the pointer to the 2D array 
 		int row 	- number of rows of the array
 *      int col 	- number of cols of the array
 * Returns: nothing
 * Pre-Conditions:  The array is allocated
 * Post-Conditions: A dynamic array is filled with all 0s
**************************************/
void dyn_init(int** a, int row, int col)
{
	for (int i = 0; i < row; i++)     //rows will be outer loop
		for (int j = 0; j < col; j++)	//columns will be inner loop
			a[i][j] = 0;
}

/**************************************
 * Function: dyn_print
 * Description: print out each element of the 2D dynamic array with rows * cols
 * Parameters:
 *      int **a 	- the pointer to the 2D array 
 		int row 	- number of rows of the array
 *      int col 	- number of cols of the array
 * Returns: nothing
 * Pre-Conditions:  The array is allocated
 * Post-Conditions: A 2D dynamic array is printed, no modifications made to the array
**************************************/
void dyn_print(int** a, int row, int col)
{
	for (int i = 0; i < row; i++)		//loop through rows
	{
		for (int j = 0; j < col; j++)	//loop through cols
			cout << a[i][j] << " ";		//print out value at row i col j

		cout << endl;
	}
}

/**************************************
 * Function: dyn_delete
 * Description: delete the heap memory allocated by 2D array 
 * Parameters:
 *      int **a 	- the pointer to the 2D array 
 		int row 	- number of rows of the array
 * Returns: nothing
 * Pre-Conditions:  The array is allocated
 * Post-Conditions: The array passed in is fully deleted
**************************************/
void dyn_delete(int **a, int row)
{
	for (int i = 0; i < row; i++)
		delete [] a[i];	// for each row pointer, delete the array where the pointer is pointing to
	delete [] a; 			// delete the array that the double pointer is pointing to
}
