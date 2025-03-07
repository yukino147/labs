#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

long *arr = new long [1000000];
int comp(const void *i, const void *j) {
  return (*(long *)i - *(long *)j);
}

int main() {
    string input = "input.txt", output = "output.txt";
    ifstream unsorted;
    unsorted.open(input);
    if (!unsorted.is_open()) return 0;

    int n;
    unsorted >> n;

    for (int i = 0; i < n; i++) {
        unsorted >> arr[i];
    }

    qsort(arr, n, sizeof(long), comp);

    ofstream sorted;
    sorted.open(output);
    sorted.close();

    sorted.open(output, ofstream::app);
    for (int i = 0; i < n; i++) {
        sorted << arr[i];
        if (i < n - 1) sorted << " ";
    }

    unsorted.close();
    sorted.close();
  /*int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%ld", &arr[i]);
  }
  qsort(arr, n, sizeof(long), comp);
  for (int i = 0; i < n; i++) {
    printf("%ld", arr[i]);
    if (i < n - 1) printf(" ");
    }*/
  return 0;
}
