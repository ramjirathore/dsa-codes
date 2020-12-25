#include<iostream>
using namespace std;

// Problem - Calculate square of a number without using *, / and pow()
// Solution - 
// Observation - Any number's square for ex 25*25
// can be written with help of power's of 2
// 25*16 + 25*8+ 25*1
// or 15 * 15 = 15*8 + 15*4 + 15*2 + 15*1
// #multiplication  can be achieved by bitwise left shift with powers of 2

int calculateSquare(int n) {
	int times = n;
	int res = 0;

	while(times>0) {
		int possibleShifts = 0, currTimes = 1;
		while(currTimes<<1 <= times) {
			currTimes = currTimes <<1;
			++possibleShifts;
		}
		res = res + n<<possibleShifts;
		times = times - currTimes;
	}

	return res;
}

int main() {
	int n;
	cin>>n;

	cout<<calculateSquare(n);
}
