#include <iostream>
#include<iomanip>// this library stored the std::setw
using namespace std;

int RandomNumber(int From, int To) {
    // Function to generate a random number
    int randNum = 1 + rand() % (To - From + 1) + From;
    return randNum;
}


void FillMatrix(short arr[3][3]) { 

    short count = 0;

    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            count++;
            arr[i][j] = count;
        }
    }
}

void PrintMatrix(short arr[3][3]) {

    cout << "\n The following is a 3x3 random matrix:\n";

    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << '\n';
    }
    cout << endl;
}


void PrintTransposeMatrix(short arr[3][3]) {

    cout << "\n The following is a 3x3 random matrix Col:\n";

    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[j][i] << "\t";
        }
        cout << '\n';
    }
    cout << endl;
}


int main()
{
    srand((unsigned)time(NULL));

    short Arr[3][3] = {};

    FillMatrix(Arr);
    PrintMatrix(Arr);

    PrintTransposeMatrix(Arr);

    return 0;
}