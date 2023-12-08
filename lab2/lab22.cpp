#include <iostream>

using namespace std;

int** genMatrix(int N)
{
	srand(time(0));
	int** arr= new int* [N];
	if(!arr)
		return 0;

	for(int i= 0; i< N;i++)
	{
		int size= rand()%50+1;
		arr[i]= new int [size];
		if (!arr[i])
			return 0;
		arr[i][0]= size;
	}

	for(int i= 0; i< N;i++)
	{
		for(int j= 1; j<=arr[i][0]; j++)
		{
			arr[i][j]= rand()% 100;
			cout << arr[i][j]<< " ";
		}
		cout << "\n";
	}
	return arr;
}

int main()
{
	int N= 10;
	int** arr= genMatrix(N);
	if(!arr)
		return 1;
	cout <<"\n\n";

	for(int i= 0; i< N; i++)
	{
		cout << arr[i][0] << ": ";
		for(int j= 1; j<= arr[i][0]; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}


	return 0;
}
