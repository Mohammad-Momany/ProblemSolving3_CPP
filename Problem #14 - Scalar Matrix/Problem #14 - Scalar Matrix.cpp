#include <iostream>
#include <cstdlib>
#include<iomanip>

using namespace std;

int randomNumber(int from, int to)
{
	int randomNum = rand() % (to - from + 1) + from;

	return randomNum;
}

void PrintMatrix(short arr[3][3]) {

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

bool IS_Scalar_Matrix(short arr[3][3])
{
	for (short i = 1; i < 3; i++)
	{
		for (short j = 1; j < 3; j++)
		{

			if (i == j && arr[i - 1][j - 1] != arr[i][j])
				return false;

			else if (i != j && arr[i][j] != 0)
				return false;
		}
	}
	return true; 
}

int main()
{
	srand((unsigned)time(NULL));

	short arr[3][3] = {
		{ 5,0,0 } ,
		{ 0,5,0 } ,
		{ 0,0,5 } };


	cout << "\n Matrix 1 : \n";
	PrintMatrix(arr);

	if (IS_Scalar_Matrix(arr))
		cout << "YES , IS An Scalar Matrix...\n";
	else
		cout << "NO , ISn't An Scalar Matrix...\n";

	return 0;

}