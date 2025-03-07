#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 8;
ifstream in("input.txt");
ofstream out("output.txt");

int k;
int board[SIZE][SIZE];
int results_count = 0;
void showBoard()
{
    for (int a = 0; a < SIZE; ++a)
    {
        for (int b = 0; b < SIZE; ++b)
        {
            if (board[a][b] == true) out << b + 1 << " ";
        }
    }
}
bool tryQueen(int a, int b)
{
    for (int i = 0; i < a; ++i)
    {
        if (board[i][b])
        {
            return false;
        }
    }

    for (int i = 1; i <= a && b - i >= 0; ++i)
    {
        if (board[a - i][b - i])
        {
            return false;
        }
    }

    for (int i = 1; i <= a && b + i < SIZE; i++)
    {
        if (board[a - i][b + i])
        {
            return false;
        }
    }

    return true;
}
void setQueen(int a)
{
    if (a == SIZE)
    {
        if (results_count + 1 == k) showBoard();
        ++results_count;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        if (tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a + 1);
            board[a][i] = 0;
        }
    }
}

int main()
{
    in >> k;
    setQueen(0);
    return 0;
}
