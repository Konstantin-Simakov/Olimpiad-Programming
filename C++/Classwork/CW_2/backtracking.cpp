// backtracking.cpp
// The program searches for the number of all possible arrangements 
// of n queens on the nxn board using the backtracking method.
#include <iostream>
#include <ctime>
using namespace std;

const int N = 4;        // The number of queens and size of the board (one side).

int search(int y, int col[], int diag_1[], int diag_2[]);

int main(void)
{
    // Initially there are no queens on the board.
    int col[N] = {0}, diag_1[(2 * N) - 1] = {0}, diag_2[(2 * N) - 1] = {0};
    int count;
    
    // Start search and display results.
    clock_t start = clock();
    // search(0, count, col, diag_1, diag_2);
    count = search(0, col, diag_1, diag_2);
    clock_t end = clock();
    cout << "The number of all possible \"peaceful\" permutations of " 
         << N << " queens on the " << N << "x" << N << " board is " << count << endl;
    cout << "The time of the algorithm is " << (double) (end - start) / CLOCKS_PER_SEC << " seconds.\n";

    return 0;
}

int search(int y, int col[], int diag_1[], int diag_2[])
{
    int count = 0;

    if (N == y)
        count++;
    else
    {
        for (int x = 0; x < N; x++)
        {
            if (col[x] || diag_1[x + y] || diag_2[x - y + N - 1])
                continue;
            col[x] = diag_1[x + y] = diag_2[x - y + N - 1] = 1;
            count += search(y + 1, col, diag_1, diag_2);
            col[x] = diag_1[x + y] = diag_2[x - y + N - 1] = 0;
        }
    }

    return count;
}
