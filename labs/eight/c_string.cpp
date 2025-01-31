#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char *array = new char[256];

	cout << "Ener and array of characters: " << endl;

	cin.getline(array, 256);
	cin.ignore(256,'\n');

	if(cin.fail()) {

		cin.ignore(256, '\n'); //get rid of everything leftover
		cin.clear(); //reset he failbit for the next cin
	}
		int n;


		cout << "How many words would you like to search for: ";
		cin >> n;
		cin.ignore();

		string word_array[n];

		for (int i = 0; i < n; i++) {


			cout << i+1 <<":";

			getline(cin, word_array[i]);

			cout << endl;

		}

	delete []array;

}
