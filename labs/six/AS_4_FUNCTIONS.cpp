#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;


//functions for assignment four 

void check_input_int(string message, int &int_input) {

	string input;
	bool bad_input;
	do{

		bad_input = false;

		cout << message;

		cin >> input;

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

void check_input_float(string message, float &float_input) {

	string input;
	bool bad_input;
	int count = 0;
	do{

		bad_input = false;

		cout << message;

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) =='.')) {
				for( int x = 0; i < input.size(); i++) { 
					if( i == '.') {
						count += 1;
					}
					if(count > 1) {
						cout << "You must input a postive float value" << endl;

						bad_input = true;
						break;
					}
				}
			}
		}
	}while(bad_input);

	float_input = atof(input.c_str());

}

int check_input_go_again(string message ) {
	string input;
	bool bad_input;
	int int_input;
	do{
		int_input = 0;

		bad_input = false;

		cout << message;

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !(input.at(i) >= '0' && input.at(i) <= '9')) {

				cout << "You must input a postive integer" << endl;

				bad_input = true;
				break;
			}


			else if( !(input.at(i) == '1' || input.at(i) == '2'))  {

				cout << "You must input a 1 or a 2." << endl;

				bad_input = true;
				break;
			}
		}


	}while(bad_input);

	int_input = atoi(input.c_str());

	return int_input;

}

int main() {

int int_input;
float float_input;

}
