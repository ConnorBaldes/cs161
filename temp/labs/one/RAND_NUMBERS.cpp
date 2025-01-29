#include <iostream>
#include <ctime>		/* include to allow time() to be used */
#include <cstdlib>		/* include to allow rand() and srand() to be used */

using namespace std;

int main() {

	int num;	//wariable to hold our random integer
	srand(time(NULL));	//seeds random number generator. Done only once.

	num = rand()%6;
	//cout  << "x = " << x << endl;
	//srand(time(NULL));
	//cout << "x = " << x << endl;
	cout << num << endl;	
	if(num == 0) {

		cout << "Bummer, I'm zero!!" << endl;
	}	
	else if((num%2) == 1) {

		cout << "I'm an odd number!"<< endl;

		if(num == 1) {
			cout << "I'm the number 1!" << endl;
		}
	}
	else{

	cout << "I'm and even number!" << endl;

	}
	
	return 0;
}
