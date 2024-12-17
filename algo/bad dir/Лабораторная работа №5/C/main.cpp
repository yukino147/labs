#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

string input = "input.txt", output = "output.txt";

long long A[200][200], i, j;

string S;

int main() {
	ifstream in(input);
	
	int n;
	in >> S;
	n = S.length();

	for (int i = 0; i < n; i++)
		A[i][i] = 1;

	for (int j = 0; j < n; j++) {
		for (int i = j - 1; i >= 0; i--) {
			if (S[i] == S[j]) {
				A[i][j] = A[i+1][j] + A[i][j-1] + 1;
			} else {
				A[i][j] = A[i+1][j] + A[i][j-1] - A[i+1][j-1];
			}
		}
	}

	ofstream out(output);
	out << A[0][n-1];

	in.close();
	out.close();
}