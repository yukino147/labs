#include <fstream>

using namespace std;

string input = "input.txt", output = "output.txt";
int *A = new int[100];

void push(int &top, const int x) {
    top++;
    A[top] = x;
}

int pop(int &top) {
    int x = A[top];
    top--;
    return x;
}

int main() {
    ifstream RPN;
    RPN.open(input);
    if (!RPN.is_open()) return 0;

    int top = -1;
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
            if (isdigit) push(top, x);
            isdigit = false;
            iscont = false;
        } else if (ch == '\n') {
            break;
        } else {
            iscont = false;
            if (ch == '+') {
                nd = pop(top); st = pop(top);
                x = st + nd;
                push(top, x);
            }
            if (ch == '-') {
                nd = pop(top); st = pop(top);
                x = st - nd;
                push(top, x);
            }
            if (ch == '*') {
                nd = pop(top); st = pop(top);
                x = st * nd;
                push(top, x);
            }
            if (ch == '/') {
                nd = pop(top); st = pop(top);
                x = st / nd;
                push(top, x);
            }
        }
    }

    ofstream calced;
    calced.open(output);
    calced.close();

    calced.open(output, ofstream::app);
    calced << pop(top);

    delete[] A;
    RPN.close();
    calced.close();
}
