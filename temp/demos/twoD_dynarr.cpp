

// two d dynamic array


#include <iostream>

using namespace std;

int main()
{
	/*create a 2D dynamic array, the double pointer is on the stack, 
	but where it is pointing to is on the heap. 
	To initialize the pointer, let it point to NULL
	*/
	int **dynarr = NULL; 
	
	//let user enter number of rows and columns
	int row = 0, col = 0;
	cout << "How many rows? "; 
	cin >> row;
	cout << "How many cols? ";
	cin >> col;

	//allocate memory for the 2D dynamic array
	dynarr = new int* [row]; //first need to create heap memory for row pointers
	for (int i = 0; i < row; i++) //for each row pointer, create heap memory for columns
		dynarr[i] = new int [col];


	//Notice they don't have contiguous memory locations
	cout << "Address of dynarr row pointer: \t" << dynarr << endl; 
	cout << "Address of dynarr: \t\t" << &dynarr << endl;		//address of pointer location

	//this will be the same as the dynarr, since dynarr stores the address of the first row pointer
	cout << "Address of dynarr[0]: \t\t" << &(dynarr[0]) << endl; 

	cout << "Address of dynarr[1]: \t\t" << &(dynarr[1]) << endl; //address of the next row location
	cout << "Address of dynarr[1][0]: \t" << &(dynarr[1][0]) << endl; //address of where next row is pointing to

	cout << "Address of dynarr[0][0]: \t" << &(dynarr[0][0]) << endl;


	/*Free heap memory at the end of the program
	Without doing this, you will have a memory leak
	Note: the last thing in creation is the first in deletion, 
	which means that you need to delete the arrays that row pointers are pointers first,
	and then delete the array of row pointers
	*/
	for (int i = 0; i < row; i++)
		delete [] dynarr[i];	// for each row pointer, delete the array where the pointer is pointing to
	delete [] dynarr; 			// delete the array that the double pointer is pointing to

	
	return 0;
}
