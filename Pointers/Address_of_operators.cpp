#include<iostream>
using namespace std;

int main() {
	int x = 10;
	cout << &x << endl;

	// For the character the address of is not recognized by "<<"
	char ch = 'p';
	cout << &ch ;


	// so we do explicit typecasting from char * to void *
	cout << (void * )&ch << endl;
}