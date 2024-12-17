#include <fstream>

std::string input = "input.txt", output = "output.txt";
int *w, *p, *x = new int[10000];
int max = 0, W, value = 1;

int utility(int v) {
	size_t n = sizeof(w);
	int dw = 0, dp = 0, d;

	for (int i = 1; i <= v; i++)
		x[i] = i;

	for (int i = 1; i <= value; i++) {
		dw += w[x[i]];
		dp += p[x[i]];
		if (dw <= W && dp > max)
			max = dp;
	}
	dw = 0;
	dp = 0;

	do {
		d = 0;
		for (int i = v; i >= 1; i--)
			if (x[i] < n - v + i) {
				d = i;
				break;
			}
		if (d > 0) {
			x[d]++;
			for (int i = d + 1; i <= v; i++)
				x[i] = x[i-1] + 1;
			for (int i = 1; i <= value; i++) {
				dw += w[x[i]];
				dp += p[x[i]];
				if (dw <= W && dp > max)
					max = dp;
			}
			dw = 0;
			dp = 0;
		}
	} while (d > 0);
}

int main() {
	int n;
	std::ifstream in(input);
	in >> n >> W;

	w = new int[n];
	p = new int[n];

	for (int i = 0; !in.eof(); i++)
		in >> w[i] >> p[i];

    while(value <= n) {
        utility(value);
        value++;
    }

	std::ofstream out;
	out.open(output);
	out << max;

	delete[] w;
	delete[] p;
	delete[] x;
	in.close();
	out.close();
}