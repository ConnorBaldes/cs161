/************************************
 ** Program: ASSIGNMENT_ONE.cpp

 ** Author: Connor Baldes

 ** Date: 1/12/2019

 ** Description: Assignment shows the size of different types of numbers in C++ and shows their limitations 

 ** Input: The iostream, cmath  and climits library will be include as input to allow the program to run and perform mathmatical equations. 
 The C++ fundementals short, int, and long are used along with functions such as sizeof() and pow() to perform computations
 in the function.

 ** Output: The maximum and minimum number of bytes in signed and unsigned short, int, and long.

 ************************************/


#include <iostream> 
#include <climits>
#include <cmath>

using namespace std;

int main() {
	//defines constants with the limits of fundamental integral types
	cout << "Climints" << endl;
	cout << "Unsigned Int Max: " << UINT_MAX << endl;
	cout << "Unsigned Long Int Max: " << ULLONG_MAX << endl;
	cout << "Unsigned Short Max: " << USHRT_MAX << endl;
	cout << "Int Max: " << INT_MAX << endl;
	cout << "Int Min: " << INT_MIN << endl;
	cout << "Long Max: " << LLONG_MAX << endl;
	cout << "Long Min: " << LLONG_MIN << endl;
	cout << "Short Max: " << SHRT_MAX << endl;
	cout << "Short Min: " << SHRT_MIN << "\n" << endl;
	
	//calculations for int, short, and long
	//Type casting so that pow() returns whole numbers to the screen
	cout << "Calculations" << endl;
	cout << "Unsigned Int Max: " << (unsigned int) pow(2, sizeof(int)*8)-1 << endl;
	cout << "Unsigned Long Max: " << (unsigned long) pow(2, sizeof(long)*8)-1 << endl;
	cout << "Unsigned Short Max: " << pow(2, sizeof(short)*8)-1 << endl;
	cout << "Int Max: " << (signed int) pow(2, sizeof(int)*8)-1 << endl;
	// Min values do not require "-1" because negative numbers start at -1 not 0
	cout << "Int Min: " << (signed int) pow(-2, sizeof(int)*8) << endl;
	cout << "Long Max: " << (signed long) pow(2, sizeof(long)*8)-1 << endl;
	cout << "Long Min: " << (signed long) pow(2, sizeof(long)*8) << endl;
	// Type casting signed for short was not giving the correct values so instead I manually subtracted one to representing sign bit
	cout << "Short Max: " <<  pow(2, (sizeof(short)*8)-1)-1 << endl; 
	cout << "Short Min: " <<  pow(-2, (sizeof(short)*8)-1) << endl;
	return 0;
}

