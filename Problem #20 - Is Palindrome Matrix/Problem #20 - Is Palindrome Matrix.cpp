#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[4][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}

bool IsPalindromeMatrix(int Matrix1[4][3], short Rows, short Cols) {

    for (short i = 0; i < Rows; i++) {

        if (Matrix1[i][0] != Matrix1[i][Cols - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int Matrix1[4][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7}, {5, 3, 5} };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 4, 3);

    if (IsPalindromeMatrix(Matrix1, 4, 3)) {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else {
        cout << "\nNo: Matrix is NOT Palindrome\n";
    }

    return 0;
}
