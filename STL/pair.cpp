#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	pair<int, char> p;
	p.first = 20;
	p.second = 'P';

	cout << p.first << " " << p.second << endl;

	pair<int, char> p2(p);
	cout << p2.first << " " << p2.second << endl;

	pair<int, string> car = make_pair(21, "Audi");
	cout << car.first << " " << car.second << endl;

	pair<pair<int, int>, string> id = make_pair(make_pair(18103227, 21), "Prerna");
	// cin >> id.first.first;
	// cin >> id.first.second;
	// cin >> id.second;


	cout << id.first.first << " " << id.first.second << " " << id.second << endl;

	return 0;
}