#include <iostream>
#include <fstream>
using namespace std;
int N, W;
int w[20], p[20];

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N; in >> W;
    int i = 0, s_w = 0, s_p = 0;
    while (!in.eof()) {
        in >> w[i];
        in >> p[i];
        i++;
    }
    int MAX = 0;
    for (int i = 0; i < N; i++) {
        if (w[i] <= W) {
            s_w = w[i];
            s_p = p[i];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    if (s_w + w[j] <= W) {
                        s_w = s_w + w[j]; s_p += p[j];
                    }
                }
            }
            if (MAX < s_p) MAX = s_p;
        }
    }
    out << MAX;
    return 0;
}