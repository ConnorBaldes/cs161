#include <iostream>
#include <cstdlib>

using namespace std;

int a( int i) {

return i + a(i-1);

}


int main() {


	cout << a(4);


}
