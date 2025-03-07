#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

int main() {
	vector<int> A;
	int num;

	ifstream in;
	in.open(input);
	while (true) {
		in >> num;
		if (num == 0) break;
		A.push_back(num);
	}

	sort(A.begin(), A.end());
	//for (int i = 0; i < A.size(); i++) cout << A[i] << " ";

	ofstream out;
	out.open(output);
	for (int i = 0; i < A.size(); i++) {
		out << A[i];
		if (i < A.size() - 1) out << " ";
	}

	in.close();
	out.close();
}