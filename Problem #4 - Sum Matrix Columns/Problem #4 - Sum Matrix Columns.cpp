#include <iostream>
#include<iomanip>// this library stored the std::setw
using namespace std;

int RandomNumber(int From, int To) {
    // Function to generate a random number
    int randNum = 1 + rand() % (To - From + 1) + From;
    return randNum;
}


void FillMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void SumMatrixCol(int arr[3][3], int sumArr[3]) {

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumArr[j] += arr[i][j];
        }
    }
}

void PrintMatrix(int arr[3][3]) {

    cout << "\n The following is a 3x3 random matrix:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << '\n';
    }
    cout << endl;
}

void PrintMatrixCol(int arr[3]) {

    cout << "\n The following is a 3x3 random matrix Columns:\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Column " << i + 1<< " Sum = " << arr[i] << '\n';
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int SumArr[3] = {};
    int Arr[3][3] = {};

    FillMatrix(Arr);
    PrintMatrix(Arr);
    SumMatrixCol(Arr, SumArr);
    PrintMatrixCol(SumArr);

    return 0;
}