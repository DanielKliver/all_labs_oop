#include<iostream>

using namespace std;

int** genRandMatrix(int intsize, int intmaxValue)
{

	int** arr = new int* [intsize];
	for(int i = 0; i<=intsize; i++)
	{
		if(i==0)
		{
			arr[i] = new int[1];
			arr[i][0] = intsize;
		}
		else
		{
			int value = rand()%20;
			arr[i] = new int[value];
			arr[i][0] = value;

		}
	}
	for(int i = 1; i<=intsize; i++)
	{
		for(int j = 1; j<=arr[i][0];j++)
		{
			arr[i][j] = rand()%intmaxValue;
		}
	}

	return arr;
}
void printMatrix(int** matrix)
{
	cout<<matrix[0][0]<<endl;
	for(int i = 1; i<=matrix[0][0]; i++)
	{
		for(int j=0;j<=matrix[i][0]; j++)
		{
			if(j==0)
			{
				cout<<matrix[i][j]<<": ";
			}
			else
			{
				cout<<matrix[i][j]<<" ";
			}
		}
		cout<<endl;
	}

}

int main()
{
	int size=rand()%10;
	int maxValue = 100;
	int** matrix = genRandMatrix(size, maxValue);
	printMatrix(matrix);
	//очистка памяти
	for(int i = 0; i<=size;i++)
	{
		for(int j = 0; i<=matrix[i][j];j++)
		{
			delete[] matrix[i];

		}
	}
	return 0;
}
