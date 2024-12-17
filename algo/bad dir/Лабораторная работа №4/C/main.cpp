#include <fstream>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";

int table[8][8], counts = 0;

void print() {
    ofstream out;
    out.open(output);

    for (int a = 0; a < 8; ++a) {
        for (int b = 0; b < 8; ++b) {
            if (table[a][b] == true) {
                out << b + 1;
                if (a < 7)
                    out << " ";
            }
        }
    }
    out.close();
}

bool beat(int a, int b) {
    for (int i = 0; i < a; ++i) {
        if (table[i][b]) {
            return false;
        }
    }

    for (int i = 1; i <= a && b - i >= 0; ++i) {
        if (table[a - i][b - i]) {
            return false;
        }
    }

    for (int i = 1; i <= a && b + i < 8; i++) {
        if (table[a - i][b + i]) {
            return false;
        }
    }
    return true;
}

void setQ(int a, int k) {
    if (a == 8) {
        if (counts + 1 == k)
            print();
        ++counts;
    }

    for (int i = 0; i < 8; ++i) {
        if (beat(a, i)) {
            table[a][i] = 1;
            setQ(a + 1, k);
            table[a][i] = 0;
        }
    }
}

int main() {
    ifstream in(input);

    int k;
    in >> k;

    in.close();

    setQ(0, k);
}