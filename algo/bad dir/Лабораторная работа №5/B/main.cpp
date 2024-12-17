#include <fstream>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

int main() {
	ifstream in(input);

	int N;
	in >> N;

	int *A = new int[N];
	for (int i = 0; i < N; i++)
		in >> A[i];

	int ans = A[0], ans_l = 0, ans_r = 0, sum = 0, minus_pos = -1;
	for (int r = 0; r < N; r++) {
		sum += A[r];
		if (sum > ans) {
			ans = sum;
			ans_l = minus_pos + 1;
			ans_r = r;
		}
		if (sum < 0) {
			sum = 0;
			minus_pos = r;
		}
	}

	ofstream out;
	out.open(output);
	out << ans_l + 1 << " " << ans_r + 1 << endl;

	delete[] A;
	in.close();
	out.close();
}