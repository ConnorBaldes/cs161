#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;



int main() {


	srand(time(NULL));

	int array [5][5];

	

	for(int i = 0; i < 4; i++) {

		for(int j = 0; j < 5; j++) {

			array[i][j] = rand()%99 + 1;

			array[i][4] = array[i][0] + array [i][1] + array[i][2] + array[i][3];

			cout << setw(4) << array[i][j];

		}	

		cout << endl;

	}

	for(int i = 0; i < 5; i++) {

		array[4][i] = 0;
	}
	for(int i = 0; i < 5; i++) {

		for(int j = 0; j < 4; j++) {

			array[4][i] += array[j][i];
		}

		cout << setw(4) << array[4][i];

	}

	cout << endl;
	
	

	
	return 0;

}
