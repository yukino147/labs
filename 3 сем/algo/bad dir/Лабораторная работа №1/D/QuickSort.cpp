#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

long *arr = new long [1000000];
int comp(const void *i, const void *j) {
  return (*(long *)i - *(long *)j);
}

int main() {
  int n;
  time_t t0 = 0, t1 = 0;
  cin >> n;

  srand(time(0));
  for (int i = 0; i < n; i++) {
    arr[i] = 0 + 21 * (1.0 * rand()) /RAND_MAX;
  }
  /*for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
  cout << endl;*/

  t0 = clock();
  qsort(arr, n, sizeof(long), comp);
  t1 = clock();
  /*for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
  cout << endl;*/

  cout << "t = " << 1.0 * (t1 - t0) / CLOCKS_PER_SEC << endl;

  delete[] arr;
}
