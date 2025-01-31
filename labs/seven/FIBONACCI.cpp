#include <iostream>
#include <cstdlib>


using namespace std;



int fib_recurs(int n) {
	
	//cout << "Fib Sequence: " << endl;
	int i;	

	if( n == 0) {
		cout << n << endl;
		return 0;
	} 

	else if( n == 1) {

		cout << n << endl;
		return 1;
	}	

	else {

		cout << n << endl;
		return fib_recurs(n-1) + fib_recurs(n-2);	
	}
}
int main() {
	int result;

	result = fib_recurs(6); 

	cout << "Result: " << result << endl;
}
