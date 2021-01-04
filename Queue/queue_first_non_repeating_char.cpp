#include<iostream>
#include<queue>
using namespace std;

//First Non repeating character Problem

int main() {
	queue<char> q;
	int freq[27] = {0};

	char ch;
	cin >> ch;

	while (ch != '.') {
		// logic goes here
		freq[ch - 'a']++;
		q.push(ch);

		// query
		while(!q.empty()) {
			int idx = q.front() - 'a';
			if(freq[idx] > 1) {
				q.pop();
			} else {
				cout<<q.front()<<" ";
				break;
			}
		}

		// q is empty
		if(q.empty()) {
			cout<<"-1 ";
		}

		cin >> ch;
	}

	return 0;
}