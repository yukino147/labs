#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string input = "input.txt", output = "output.txt";
ofstream out;

typedef int vec[8];
vec p, r;
int n;

void print() {
	for (int i = 1; i <= n; i++)
		out << p[i] - 1;
		//cout << p[i] - 1;
	out << endl;
	//cout << endl;
	return;
}

void per(int k){
	int i;
	for (i = 1;i <= n; i++) {
		if (r[i] == 0) {
			r[i] = 1; p[k] = i;
			if (k == n)
				print();
			else
				per(k + 1);
			r[i] = 0;
		}
	}
}

int main() {
	ifstream in(input);

	out.open(output);

	in >> n;
	memset(r, 0, n);

	per(1);

	in.close();
	out.close();
}