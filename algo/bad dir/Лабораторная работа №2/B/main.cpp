#include <fstream>

using namespace std;

string input = "input.txt", output = "output.txt";

void push(int *&A, int &top, const int x) {
    int *newA = new int[++top + 1];
    for (int i = 0; i < top + 1; i++)
        newA[i] = A[i];
    newA[top] = x;
    delete[] A;
    A = newA;
}

int pop(int *&A, int &top) {
    int x = A[top];
    top--;
    int *newA = new int;
    if (top > 0) {
        int *newA = new int[top + 1];
        for (int i = 0; i < top + 1; i++)
            newA[i] = A[i];
    } else {
        int *newA = new int[1];
        newA[0] = A[0];
    }
    delete[] A;
    A = newA;
    return x;
}

int main() {
    ifstream RPN;
    RPN.open(input);
    if (!RPN.is_open()) return 0;

    int top = -1;
    int *A = new int[1];
    char ch;
    int x, st, nd;
    bool iscont = false, isdigit;
    while (RPN.get(ch)) {
        if (ch >= '0' && ch <= '9') {
            isdigit = true;
            if (!iscont) {
                x = ch - '0';
            } else {
                x *= 10;
                x += ch - '0';
            }
            iscont = true;
        } else if (ch == ' ') {
            if (isdigit) push(A, top, x);
            isdigit = false;
            iscont = false;
        } else if (ch == '\n') {
            break;
        } else {
            iscont = false;
            if (ch == '+') {
                nd = pop(A, top); st = pop(A, top);
                x = st + nd;
                push(A, top, x);
            }
            if (ch == '-') {
                nd = pop(A, top); st = pop(A, top);
                x = st - nd;
                push(A, top, x);
            }
            if (ch == '*') {
                nd = pop(A, top); st = pop(A, top);
                x = st * nd;
                push(A, top, x);
            }
            if (ch == '/') {
                nd = pop(A, top); st = pop(A, top);
                x = st / nd;
                push(A, top, x);
            }
        }
    }

    ofstream calced;
    calced.open(output);
    calced.close();

    calced.open(output, ofstream::app);
    calced << pop(A, top);
    
    delete[] A;
    RPN.close();
    calced.close();
}
