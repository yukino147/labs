#include <fstream>
#include <iostream>

using namespace std;

string input = "input.txt", output = "output.txt";
char *A = new char[100];

void push(int &top, const char x) {
    top++;
    A[top] = x;
}

char pop(int &top) {
    char x = A[top];
    top--;
    return x;
}

int main() {
    ifstream usual;
    usual.open(input);
    if (!usual.is_open()) return 0;

    ofstream RPN;
    RPN.open(output);
    RPN.close();

    RPN.open(output, ofstream::app);

    int top = -1;
    char x;
    //bool iscont = false;
    while (usual.get(x)) {
    	if (x == '(')
    		push(top, x);
    	if (x == ')') {
    		for (; top > -1;) {
	    		if (A[top] == '(') {
	    			A[top] = ' ';
	    			top--;
	    			break;
	    		}
	    		RPN << " " << pop(top);
    		}
    	}
    	if (x >= '0' && x <= '9') {
    		RPN << x;
    		//iscont = true;
    	}
    	if (x == '+' || x == '-') {
    		RPN << " ";
    		if (top < 0 || A[top] == '(')
    			push(top, x);
    		else if (A[top] == '*' || A[top] == '/') {
    			for (; top > -1;) {
		    		if (A[top] == '(') {
		    			A[top] = ' ';
		    			top--;
		    			break;
		    		}
	    		RPN << pop(top) << " ";
    		}
    			push(top, x);
    		}
    		else
    			push(top, x);
    	}
    	if (x == '*' || x == '/') {
    		RPN << " ";
    		if (top > -1 && (A[top] == '*' || A[top] == '/')) {
    			for (; top > -1;) {
		    		if (A[top] == '(') {
		    			A[top] = ' ';
		    			top--;
		    			break;
		    		}
		    		RPN << " " << pop(top) << " ";
    			}
    		}
    		push(top, x);
    	}
    }

    if (top > -1) {
    	for (; top > -1;) {
    		if (A[top] != '(') {
    			RPN << " " << pop(top);
    		}
    	}
    }

    delete[] A;
    usual.close();
    RPN.close();
}
