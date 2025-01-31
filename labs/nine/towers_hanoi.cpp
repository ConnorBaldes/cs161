#include <iostream>
#include <cstdlib>

using namespace std;


void towers(int number_of_disks, int **array, int from_col, int to_col, int spare) {

	if(number_of_disks >= 1) {


	}
}
	

		
int** create_array(int row) {

	int **array = new int*[row];

	for(int i = 0; i < row; i++) {

		array[i] = new int[3];
	}
	return array;
}

void print(int**tower_array, int row) {

	cout << "----------" << endl;

	for(int i = 0; i < row; i++) {

		for(int j = 0; j < 3; j++) {

			cout << tower_array[i][j];
		}
		cout << endl;
	}
	cout << "----------" << endl;
}
void delete_array( int**tower_array, int row) {

	for(int i = 0; i < row; i++) {

		delete [] tower_array[i];
	}
	delete []tower_array;
}

int main() {

	int row;

	cout << "How many disks would you like to use: ";
	cin >> row;

	int **tower_array = create_array(row);

	print(tower_array, row);

}
