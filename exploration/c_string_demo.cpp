

// c string demo


#include <iostream>
#include <string>
#include <string.h>

using namespace std;


int main()
{
	
	/*the size of the array needs to be at least 1 larger than 
	the length of the string, since the '\0' will be stored
	at the end of the c style string
	*/
	char array1[6] = "hello";

	/*Or you don't need to specify the size of the array when you 
	know it will be an array at the very beginning, then the size of 
	the array will be the actual length of the string + 1 char for '\0'.
	*Note: You have to give it a size if you are reading a string from user
	*/  
	char array2[] = "It's snowing";

	/*The following line won't work since the array is too small to store all
	characters
	*/
	// char array3[5] = "It's snowing";
	
	/*You can have an array that has bigger size than the number of characters
	you want to store
	*/
	char array4[256] = "It's snowing";

	/*Printing out the length of each array using strlen() function
	Note: it will print out the size of the string, not size of the array
	*/
	cout << strlen(array1) << endl;
	cout << strlen(array2) << endl;
	cout << strlen(array4) << endl;


	/*Using strcyp() to assign one c-style string to another, the following line 
	is saying to assign array1 to array2
	Note: you cannot do array2 = array1 since array2 is type char[13], and array1 is
	type char[6]
	*/
	strcpy(array2, array1);
	cout << array1 << endl;
	cout << array2 << endl;

	/*Using strcmp() to compare if two c-style strings are the same*/
	if (strcmp(array1, array2))
		cout << "They are not the same c style strings" << endl;
	else
		cout << "They are the same" << endl;



	return 0;
}
