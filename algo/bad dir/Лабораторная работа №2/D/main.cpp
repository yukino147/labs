#include <fstream>

using namespace std;

string input = "input.txt", output = "output.txt";
int top, num, size = 0;

void push(int d, int *p) {
    p[++top] = d;
}

int main() {
    ifstream Array;
    Array.open(input);
    if (!Array.is_open()) return 0;

    top = -1;
    Array >> size;
    int *A = new int[size];

    int a, b;
    Array >> a >> b;

    for (int i = 0; i < size; i++) {
        Array >> num;
        push(num, A);
    }

    top = -1;

    int *B = new int[size];
    for (int i = 0; i < size; i++) {
        if (A[i] < a) {
            num = A[i];
            push(num, B);
        }
    }
    for (int i = 0; i < size; i++) {
        if (A[i] >= a && A[i] <= b) {
            num = A[i];
            push(num, B);
        }
    }
    for (int i = 0; i < size; i++) {
        if (A[i] > b) {
            num = A[i];
            push(num, B);
        }
    }

    ofstream changedArray;
    changedArray.open(output);
    changedArray.close();

    changedArray.open(output, ofstream::app);
    for (int i = 0; i < size; i++) {
        changedArray << B[i];
        if (i < size - 1) changedArray << " ";
    }

    Array.close();
    changedArray.close();
}
