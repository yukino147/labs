#include <iostream>
#include <fstream>

using namespace std;

void swap(long *A, int i, int j) {
  int buf = A[i];
  A[i] = A[j];
  A[j] = buf;
}

void Sort(long *A, int n) {
  int i, j;
  bool obmen;
  for (i = 0; i < n; i++) {
    obmen = false;
      for (j = 0; j < n - i - 1; j++) {
        if (A[j] > A[j + 1]) {
          swap(A, j, j+1);
          obmen = true;
          }
      }
      if (!obmen) break;
  }
}

int main() {
  string input = "input.txt", output = "output.txt";
  ifstream unsorted;
  unsorted.open(input);
  if (!unsorted.is_open()) return 0;

  int num;
  long *A, n;
  unsorted >> n;
  A = new long[n];

  for (int i = 0; i < n; i++) {
    unsorted >> num;
    A[i] = num;
  }

  Sort(A, n);

  ofstream sorted;
  sorted.open(output);
  sorted.close();

  sorted.open(output, ofstream::app);
  for (int i = 0; i < n; i++) {
    sorted << A[i];
    if (i < n - 1) sorted << " ";
  }

  delete[] A;
  unsorted.close();
  sorted.close();
}
