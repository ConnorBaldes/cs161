#include <iostream>
#include <string>

using namespace std;

string d_t_r(int num, string rm);
string d_t_r( int num, string rm) {
	
	while(num > 0) {
		
		if( num  >= 1000) {
			rm +="M";
			num -= 1000;
		}
		else if(num >= 500) {
			rm +="D";
			num -= 500;
		}
		else if(num >= 100) {
			rm += "C";
			num -= 100;
		}
		else if(num >= 50) {
			rm += "L";
			num -= 50;
		}
		else if(num >= 10) {
			rm += "X";
			num -= 10;
		}
		else if (num >= 5) {
			rm += "V";
			num -= 5;
		}
		else {
			rm += "I";
			num -= 1;

		}
	}	
	
	return rm;

}
int main() {
	string rm;
	int num =0;
	int x = 1;
	string result;
	while( x > 0) {
		cout << "Please input a positive integer: ";
		cin >> num;

		result =d_t_r(num, rm);
		cout << result;
		cout << "If you would like to go again enter 1 if not enter 0: ";
		cin >> x;
	}
}	

