#include <fstream>
#include <list>
//#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

int main() {
	list<int> A;
	int num;

	ifstream in;
	in.open(input);
	while (true) {
		in >> num;
		if (num == 0) break;
		A.push_back(num);
	}

	for (auto i = A.begin(); i != A.end(); i++) {
		if (*i < 0) {
			A.erase(i);
			i = A.begin();
		}
	}

	//for (int i = 0; i < A.size(); i++) cout << A[i] << " ";

	ofstream out;
	out.open(output);
	for (auto i = A.begin(); i != A.end(); i++) {
		out << *i << " ";
	}

	in.close();
	out.close();
}