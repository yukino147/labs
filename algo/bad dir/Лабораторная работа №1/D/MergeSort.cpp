#include <stdio.h>
#include <ctime>
#include <iostream>

using namespace std;

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
    int n;
    time_t t0 = 0, t1 = 0;
    cin >> n;
    int *A = new int[n];
    B = new int[n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
        A[i] = 0 + 21 * (1.0 * rand()) /RAND_MAX;
    }
    /*for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;*/

    t0 = clock();
    Sort(A, 0, n-1);
    t1 = clock();
    /*for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;*/

    cout << "t = " << 1.0 * (t1 - t0) / CLOCKS_PER_SEC << endl;
    //cout << "t = " << t1 - t0 << "ms" << endl;

    delete[] A;
    delete[] B;
}
