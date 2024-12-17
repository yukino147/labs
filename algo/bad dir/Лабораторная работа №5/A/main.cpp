#include <fstream>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

long long tails[100];

int main() {
	ifstream in(input);
	int N;
	long long ind = 1;
	in >> N;

	tails[0] = 2;
	for (int i = 1; i < N; i++) {
		tails[i] = tails[i-1] + ind;
		ind = tails[i-1];
	}

	ofstream out;
	out.open(output);
	out << tails[N-1];

	in.close();
	out.close();
}