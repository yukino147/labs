#include <stdio.h>
#include <fstream>

std::string input = "input.txt", output = "output.txt";
int *B;

int Merge(int *A, int p, int q, int r) {
    int i1, i2, i;
    i1 = p; i2 = q + 1; i = p;
    while (i1 <= q && i2 <= r) {
    	if (A[i1] <= A[i2]) B[i++] = A[i1++];
    	else B[i++] = A[i2++];
    }
    while (i1 <= q) B[i++] = A[i1++];
    while (i2 <= r) B[i++] = A[i2++];
    for (i = p;i <= r; i++) A[i] = B[i];
    return 0;
}

void Sort(int *A, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        Sort(A, p, q);
        Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main() {
    std::ios::sync_with_stdio( false );
    std::ifstream unsorted("input.txt", std::ios::binary);
    //unsorted.open(input);
    if (!unsorted.is_open()) return 0;

    int n;
    unsorted >> n;
    int *A = new int[n];
    B = new int[n];

    for (int i = 0; i < n; i++) {
        unsorted >> A[i];
    }

    Sort(A, 0, n-1);

    std::ofstream sorted;
    sorted.open(output);
    sorted.close();

    sorted.open(output, std::ofstream::app);
    for (int i = 0; i < n; i++) {
        sorted << A[i];
        if (i < n - 1) sorted << " ";
    }

    delete[] A;
    delete[] B;
    unsorted.close();
    sorted.close();
}
