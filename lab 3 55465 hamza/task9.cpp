#include <iostream>
using namespace std;

int main()
{
    const int size = 3;
    int matrix[size][size], transpose[size][size];

    cout << "Enter the elements of a 3x3 matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "The transposed matrix is:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}