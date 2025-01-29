
/*******************************
 *Program Filename: ASSIGNMENT_FIVE.cpp
 *
 * Author: Connor Baldes
 *
 * Date: 3-3-2019
 *
 * Description: Prints out a pattern of "*" by recursively calling a function
 *
 * Input: int space number of iterations
 *
 * Output: pattern printed to screen
 *
 * ******************************/




#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <cctype>

using namespace std;

/************************************************
 *  
 * Function: check_input_int()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void check_input_int(string message, int &int_input) {

	string input;
	bool bad_input;
	do{

		bad_input = false;

		cout << message;

		cin >> input;

		cin.ignore();	

		for( int i = 0; i < input.size(); i++) {

			if( !(input.at(i) >= '0' && input.at(i) <= '9')) {

				cout << "You must input a postive integer" << endl;

				bad_input = true;
				break;
			}
		}
	}while(bad_input);

	int_input = atoi(input.c_str());

}

/************************************************
 *  
 * Function: recursive_pattern
 *    
 * Description: calls itself to creat a patern of "*"
 *         
 * Parameters: int size, int space
 *    
 * Pre-Conditions: none
 *             
 * Post-Conditions: none
 *                
*********************************************/



int recursive_pattern( int size, int space) {


	if(space == 0) {
		return 0;
	}
	
	recursive_pattern(size, space/2);

	for(int i = 0; i < size; i++) {

		cout << " ";

	}

	for(int i = 0; i < space; i++) {

		cout << "*";

	}
	cout << endl;

	recursive_pattern(size + (space/2), space/2);

	return 0;
}

int main () {

	int space;
	int go_again;

	do{
		check_input_int("Enter a number: ", space);
	
		recursive_pattern(0,space);

		cout << endl;

		check_input_int("If you would like to go again enter 1 if not enter 2: ", go_again);

	}while(go_again == 1);

	return 0;
}
