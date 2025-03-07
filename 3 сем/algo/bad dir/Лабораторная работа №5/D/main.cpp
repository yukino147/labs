#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

int main() {
    ifstream in(input);

    int N;
    in >> N;

    vector<int> A(N);
    vector<int> d(N), p(N);
    for (int i = N - 1; i >= 0; i--)
        in >> A[i];

    for (int i = 0; i < N; i++) {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; j++)
            if (A[j] > A[i])
                if (1 + d[j] > d[i]) {
                    d[i] = 1 + d[j];
                    p[i] = j;
                }
    }
 
    ofstream out;
    out.open(output);
    int ans = d[0], pos = 0;
    for (int i = 0; i < N; i++)
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    out << ans << endl;

    vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = p[pos];
    }

    for (int i = 0; i < (int)path.size(); i++)
        out << A[path[i]] << " ";
    
    in.close();
    out.close();
}