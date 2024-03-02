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

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3] = {};

    FillMatrix(arr);

    PrintMatrix(arr);

    return 0;
}