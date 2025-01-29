#include <string.h>
#include <iostream>

using std::endl;
using std::cout;

using std::cin;

// Null terminator macro
// 	Not used
#define NULL_TERM '\0'

// Get a dynamic Char array that is exactly
// 	the size of the string it holds ( + null terminator)
char * getStrOfExactSize();
char * getStrOfExactSize1();

// Checks if 2 cstrings are equivalent
// "ABC" == "ABC"
// "ABc" != "ABC"
bool areEqual(char *, char *);
bool areEqual1(char *, char *);

int main(){

	// Get a C string of the exact size
	// 	use manual function
	cout << "Enter 1st string: ";
	char * s1 = getStrOfExactSize();
	
	// Get a C string of the exact size
	// 	use strcpy
	cout << "Enter 2nd string: ";
	char * s2 = getStrOfExactSize1();

	// Print the strings back
	cout << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << endl;
	
	// strstr example
	// 	returns a c-string of the remaining chars
	// 	after the first index of s2
	//
	// 	if s2 is not found, returns NULL
	char * result = strstr(s1, s2);
	cout << "found: " << result << endl;
	cout << "In :" << s1 << endl;
	
	cout << endl;

	// Compare 2 strings manual version
	if(areEqual(s1, s2)){
		cout << "s1 == s2" << endl;
	}else{
		cout << "s1 != s2" << endl;
	}
	
	// Compare 2 strings strcmp version
	if(areEqual(s1, s2)){
		cout << "s1 == s2" << endl;
	}else{
		cout << "s1 != s2" << endl;
	}
	
	// Get rid of the strings on the heap
	delete [] s1;
	delete [] s2;

}





/*************************************************************
 * Are Equal
 * 	Purpose: Checks if 2 strings are equivalent using strcmp
 * 	params : 2 c-strings (left, and right), can be on heap or
 * 				stack
 *	Returns: Boolean, true if they are equal
 *					  flase if they are not equal
 *	Preconditions: left and right are both c-strings, can be 
 *					  on heap or stack. If on heap, pointer
 *					  must point to a valid c-string
 *
 *	Post-Conditions: None, nothing modified
 *************************************************************/
bool areEqual(char * left, char * right){
	
	// If strings are not the same length
	// 	return false
	if(strlen(left) != strlen(right))
		return false;

	// Check char by char for a case where
	// 	they do not match
	for(int i = 0; i < strlen(left); i++){
		if(left[i] != right[i])
			return false;
	}

	// If we got this far, they must be equal
	return true;	
}

/*************************************************************
 * Are Equal 1
 * 	Purpose: Checks if 2 strings are equivalent using strcmp
 * 	params : 2 c-strings (left, and right), can be on heap or
 * 				stack
 *	Returns: Boolean, true if they are equal
 *					  flase if they are not equal
 *	Preconditions: left and right are both c-strings, can be 
 *					  on heap or stack. If on heap, pointer
 *					  must point to a valid c-string
 *	Post-Conditions: None, nothing modified
 *************************************************************/
bool areEqual1(char * left, char * right){
	// Let the string.h lib do all the work :)
	return strcmp(left, right) == 0;
	
}

/*************************************************************
 * Get Str of Exact Size
 * 	Purpose: Gets a char array of the exact size of the string
 * 				that it holds. Done manualy
 * 	params : None
 *	Returns: Address of the start of a char array on the heap
 *	Preconditions: None
 *
 *	Post-Conditions: A char array will be on the heap
 *************************************************************/
char * getStrOfExactSize(){

	// Create temporary buffer on the stack
	// 	buffer just hold the string briefly until we have 
	// 	a new home
	char buf[256];
	
	// Get the string from the user
	cin.getline(buf, 256);
	
	// Get the size of the cstring
	// 	add 1 to account for the null terminator
	int size = strlen(buf) + 1;
	char * str = new char[size];

	// Directly copy all characters
	for(int i = 0; i < size; i++){
		str[i] = buf[i];
	}

	// Return the address of the start of the C-String
	return str;
}


/*************************************************************
 * Get Str of Exact Size 1
 * 	Purpose: Gets a char array of the exact size of the string
 * 				that it holds. Uses strcpy
 * 	params : None
 *	Returns: Address of the start of a char array on the heap
 *	Preconditions: None
 *
 *	Post-Conditions: A char array will be on the heap
 *************************************************************/
char * getStrOfExactSize1(){
	// Create temporary buffer on the stack
	// 	buffer just hold the string briefly until we have 
	// 	a new home
	char buf[256];
	
	// Get the string from the user
	cin.getline(buf, 256);
	
	// Get the size of the cstring
	// 	add 1 to account for the null terminator
	int size = strlen(buf) + 1;
	char * str = new char[size];

	// Let string.h do the copy for us
	strcpy(str, buf);

	// Return the address of the sart of the C-String
	return str;
}
