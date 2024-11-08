// cache.cpp
// Demonstrate how to use cache memory of processor.
// This code will work in supposed that matrix is square.
#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = ROWS;

int sum_with_cache(int matrix[][COLS], int rows);
int sum_without_cache(int matrix[][COLS], int rows);

int main(void)
{
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    };

    cout << "The sum of matrix element by rows is " 
         << sum_with_cache(matrix, ROWS) << endl;
    cout << "The sum of matrix element by columns is " 
         << sum_without_cache(matrix, ROWS) << endl;

    return 0;
}

int sum_with_cache(int matrix[][COLS], int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < COLS; ++j)
            sum += matrix[i][j];        // Count by rows.
    }

    return sum;
}

int sum_without_cache(int matrix[][COLS], int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < COLS; ++j)
            sum += matrix[j][i];        // Count by columns.
    }

    return sum;
}
