#include<iostream>
#include<list>
using namespace std;

int main() {
	// Declaration
	list<int> l;

	// Init
	list<int> l1{1, 2, 3, 4, 8, 5};

	// Different Datatype
	list<string> l2{"mango", "apple", "guava",  "banana"};
	l2.push_back("pineapple");

	// sort (built inside list class)
	l2.sort();

	// reverse
	l2.reverse();

	//pop_front
	cout << l2.front() << endl;
	l2.pop_front();

	// Add to front of the list
	l2.push_front("kiwi");
	cout << l2.back() << endl;
	l2.pop_back();

	// using iterator
	for (auto it = l2.begin(); it != l2.end(); it++) {
		cout << *it << " --> ";
	}

	cout << endl;


	// some more functions
	l2.push_back("orange");
	l2.push_back("lemon");
	l2.push_back("lemon");


	// iterate and print list
	for (string s : l2) {
		cout << s << "->";
	}

	string str;
	// cin>>str;

	// remove a string(its all occurences)
	// l2.remove(str);

	cout << endl;
	// iterate and print list
	for (string s : l2) {
		cout << s << "->";
	}

	cout<<endl;
	// erase one or more element based on index
	auto it = l2.begin();
	it++;
	it++;

	l2.erase(it);

	for (string s : l2) {
		cout << s << "->";
	}

	cout<<endl;

	it = l2.begin();
	it++;
	l2.insert(it, "FruitJuice");


	for (string s : l2) {
		cout << s << "->";
	}

	return 0;

}
