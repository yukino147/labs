#include <fstream>

std::string input = "input.txt", output = "output.txt";
int *w, *p;

int utility(int W) {
	size_t n = sizeof(w);
	int max = 0, dw = 0, dp = 0;

	for (int i = 0; i < n; i++) {
		if (w[i] <= W) {
			dw = w[i];
			dp = p[i];
			for (int k = 0; k < n; k++) {
				if (i != k) {
					if (dw + w[k] <= W) {
						dw = dw + w[k];
						dp += p[k];
					}
				}
			}
			if (max < dp)
				max = dp;
		}
	}
	return max;
}

int main() {
	int n, W;
	std::ifstream in(input);
	in >> n >> W;

	w = new int[n];
	p = new int[n];

	for (int i = 0; !in.eof(); i++)
		in >> w[i] >> p[i];

	std::ofstream out;
	out.open(output);
	out << utility(W);

	delete[] w;
	delete[] p;
	in.close();
	out.close();
}