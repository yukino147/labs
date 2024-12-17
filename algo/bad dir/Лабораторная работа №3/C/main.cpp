#include <fstream>
#include <set>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

int main() {
	multiset<int> ms;

	int N, M;

	ifstream in;
	in.open(input);
	in >> N >> M;

	int t;
	for (int i = 0; i < N; i++) {
		in >> t;
		ms.insert(t);
	}

	while (M != 0) {
		multiset <int> :: reverse_iterator rit = ms.rbegin();
		ms.insert((*rit) / 10);
		ms.erase(--ms.end());
		M--;
	}

	int p = 0;
	multiset <int> :: iterator it = ms.begin();
	for (int i = 1; it != ms.end(); i++, it++)
		p = p + (*(it));

	ofstream out;
	out.open(output);
	out << p;

	in.close();
	out.close();
}