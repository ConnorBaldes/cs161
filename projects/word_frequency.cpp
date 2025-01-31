/*******************************
 *Program Filename: ASSIGNMENT_FIVE_PART_ONE.cpp
 *
 * Author: Connor Baldes
 *
 * Date: 3-2-2019
 *
 * Description: Checks for the frequecy of words of a user input string
 *
 * Input: string sentence/paragraph, amount of words to check for, words to check for
 *
 * Output: Total frequecy of input words
 *
 * ******************************/


#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>

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

			if( !(input.at(i) >= '1' && input.at(i) <= '9')) {

				cout << "You must input a postive integer" << endl;

				bad_input = true;
				break;
			}
		}
	}while(bad_input);

	int_input = atoi(input.c_str());

}


/**************************************
 * Function: get_words
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
void get_words(char** &a, int &row) {

	/* Taking double pointer and passing it in as a reference, which means that "a" is the same as the pointer passed in
	 * so it is also a double pointer. If a is changed the double pointer will be changed as well. 
	*/ 
	

	check_input_int("How many words would you like to check: ", row);
 	cin.clear();
	

	a = new char*[row];				//allocate memory for row pointers

	for(int i = 0; i < row; i++){	//for each row pointer, allocate memory for columns
		a[i] = new char[50];		
	}					
							
	for (int i = 0; i < row; i++) {

		cout << "Word " << i+1 << ": ";
		cin.getline(a[i], 50);

	}
	
}


/************************************************
 *  
 * Function: get_sentence
 *    
 * Description: Prompts the user to enter a sentence or paragraph less than 256 characters which it reads into a temporary array then a perminent array is created of 
 * 			the size of the sentence plus one and returned as a pointer to that array.
 *         
 * Parameters: none
 *    
 * Pre-Conditions: none
 *             
 * Post-Conditions: pointer to a 1d character array is created and returned.
 *                
*********************************************/

char *get_sentence() {


	char buf[256];

	cout << "Enter a sentence or paragrah that no greater than 256 character: " << "\n" << endl;

	cin.getline(buf,256);


	int size= strlen(buf) + 1;

	char *array = new char[size];


	for(int i = 0; i < size; i++) {

		array[i] = buf[i];

	}

	return array;
	//delete [] array;
}

/************************************************
 *  
 * Function: split_sentence
 *    
 * Description: An emppty 2d array and a 1d array of characters is brought in the 1d array is split into its individual words using the strtok function and
 * 		each one of those words is placed in a spot in the 2d array so each word can be read seperately. 
 *         
 * Parameters: - empty 2d array 
 * 	       - 1d array of characters(sentence)
 *    
 * Pre-Conditions: - 2d array is created and does not hold values
 * 		   - 1d array is created and holds an array of characters
 *             
 * Post-Conditions: 2d arraay now has  positions that holds each individual word in the 1d sentence
 *                
*********************************************/


void split_sentence(char ** &a, char *sentence_array) {


	a = new char*[101];				
							//allocate memory for row pointers

	for(int i = 0; i < 100; i++) {	//for each row pointer, allocate memory for columns
		a[i] = new char[50];
	}		
									
	int x = 0;	

	a[x] = strtok(sentence_array, " ,.-+?<>:;(){}[]/\"\'!@#%^&*_="); 

	while( (sentence_array != NULL) && ( x < 100) ) { 
		
		x += 1;

		a[x] = strtok(NULL, " ,.-+?<>:;(){}[]/\"\'!@#%^&*_="); 
	
	}

	//a[101] = NULL;
}
/************************************************
 *  
 * Function: make_lower
 *    
 * Description: takes in a 2d array and convers all letters in that array to lowercase
 *         
 * Parameters: - 2d array contaning rows pointing to character arrays
 * 	       - number of rows in the 2d array
 *    
 * Pre-Conditions: -2d array with rows pointing arrays of characters
 * 		   - defined amount of rows 
 *             
 * Post-Conditions: all letter characters that each row in the 2d array points to are lowercase
 *                
*********************************************/


void make_lower(char ** a, int row) {

//	cout << "wtf" << endl;
       
	for(int i = 0; i < row; i++) {

//		cout << "$" << endl;

		char *word = new char[50];
			
		strcpy(word, a[i]);

//		word[50] = '\0';

		int x = 0;
		char c;
		while( word[x] < 50) {
		
			c = word[x];
		
			c = tolower(c);

			word[x] = c;

			x++;
		//	cout << word[x] << endl;
		}			
		cout << word << endl;
		a[i] = word;
	}	

}

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


void compare_words( char **sentence_words, char **word_list, int *word_amount, int row) {

	int *gobeavs = new int[2];
	for(int i = 0; word_list[i] != NULL; i++) {

		for(int x = 0; sentence_words[x] != NULL; x++) {

			//cout << word_list[i] << endl;
			//cout << sentence_words[x] << endl;

			gobeavs[1] = strcmp(word_list[i], sentence_words[x]);

			if(gobeavs[1] == 0) {

				word_amount[i] += 1;
			}
		}
	}
//	delete [] gobeavs;
}

/************************************************
 *  
 * Function: show_results
 *    
 * Description: prints frequency of words in sentence to screen
 *         
 * Parameters: - 2d array that is list of words that were checked for
 *    	       - array of integers with count for each word
 *
 * Pre-Conditions: - 2d array with list of words
 * 		   - array of ints with count	
 *             
 * Post-Conditions: none
 *                
*********************************************/


void show_results(char **word_list, int *word_amount, int row) {


	for(int i = 0; i < row; i++) {

		cout << word_list[i] << ": " << word_amount[i] << endl;
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
void array_delete(char ** &a, int c)
{
	for (int i = 0; i < c; i++) {

		delete [] a[i];
	}				// for each row pointer, delete the array where the pointer is pointing to
	delete [] a; 		
	// delete the array that the double pointer is pointing to
}

int main() {

	//list of words I will be checking for 
	char **word_list = NULL;

	//list of words entered in as the sentence
	char **sentence_words = NULL;

	//array of characeters that makes up sentence
	char *sentence_array = get_sentence();

	//number of words the user will input
	int row;
	
	//function to get words that will be searched for in the sentence
	get_words(word_list, row);

	//spliting the sentence into a list of words 
	split_sentence(sentence_words, sentence_array);

	int x = 100;

	//word count
	int *word_amount = new int[row];

//	make_lower(word_list, row);

//	make_lower(sentence_words, 100);

	compare_words(sentence_words, word_list, word_amount, row);

	show_results(word_list, word_amount, row);

	//cout << sentence_words[0] << endl;

	//cout << word_list[0] << endl;


	//cout << strlen(word_list[0]) << endl;

	/*for(int i = 0; i < strlen(*sentence_words); i++) {

			cout << sentence_words[i] << endl;
	}
	*/

	//cout << word_list[0] << ": " << word_amount[0] << endl;

	//cout << word_list[1] << ": " << word_amount[1] << endl;
	
	//delete [] sentence_words;

//	delete [] sentence_array;

//	delete [] word_amount;	

//	for(int i = 0; i < row; i++) {

//		delete [] word_list[i];
//	}

//	delete [] word_list;

//	for(int i = 0; i < 100; i++) {

//		delete [] sentence_words[i];
//	}

//	delete [] sentence_words;
	return 0;

}
