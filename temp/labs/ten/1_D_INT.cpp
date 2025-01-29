#include <iostream>
#include <cstdlib>

using namespace std;

void sum( int*x, int*y, int*z, int n) {

	for(int i = 0; i < n; i++) {

		z[i] = (x[i] +y[i]);

		cout << z[i] << endl;
	}

}


int main() {

	int n;

	cout << "Enter a number: ";
	cin >> n;
	
	int *x = new int[n];
	int *y = new int[n];
	int *z = new int[n];

	for(int i = 0; i < n; i++ ) {

		if(i == 0) {

			x[i] = 2;
		}
		else {

			x[i] = x[i-1] + 2;

		}
	}
	
	for(int i = 0; i < n; i++) {

		cout << x[i] << endl;

	}

	for(int i = 0; i < n; i++ ) {

		if(i == 0) {

			y[i] = 1;
		}
		else {

			y[i] = y[i-1] + 2;

		}
	}
	
	for(int i = 0; i < n; i++) {

		cout << y[i] << endl;

	}

	sum(x, y, z, n);

	delete [] x;
	delete [] y;
	delete [] z;

	return 0;
}
