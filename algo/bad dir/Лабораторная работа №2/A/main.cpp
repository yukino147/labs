#include <fstream>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";
int top, num, size = 0;

void push(int d, int *p) {
    p[++top] = d;
}

void pop(int *p) {
    p = new int[--top];
    size--;
}

int main() {
    ifstream Array;
    Array.open(input);
    if (!Array.is_open()) return 0;

    int x;
    while(Array >> x) size++;
    Array.close();
    Array.open(input);

    top = -1;

    int *A = new int[size];
    for (int i = 0; i < size; i++) {
        Array >> num;
        push(num, A);
    }

    pop(A);

    top = -1;

    int r = size - 1;
    int *B = new int[size];
    for (int i = 0; i < size; i++) {
        num = A[r]; r--;
        push(num, B);
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
