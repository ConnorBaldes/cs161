#include <iostream>

using namespace std;

int main() {
	//Defines varialbe and sets count to 0
	int intval;
	int i;
	int count = 0;
	
	cout << "Enter a positive integer value: ";
	cin >> intval;
	
	if(intval == 0) { // If user inputs 0
		
		cout << "\n" << intval << " is not prime." << endl;
	}
	
	else { 

		for(i=2; i < intval; i++) { // sets counter to two and increments count any time the int is divisable

			if(intval % i == 0) {
				
				count++;
			}
		}
	
	
		if (count > 1) {
			// If count is higher than 1 number is not prime
			cout << "\n" << intval << " is not prime. " << endl;
		}
		
		else {
	
			cout << "\n" << intval << " is prime." << endl;
		}
	
	}
	return 0;
}
						
