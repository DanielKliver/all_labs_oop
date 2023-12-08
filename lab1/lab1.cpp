#include<iostream>

using namespace std;

int* genRandArray(int size, int maxValue)
{
	int* array = (int*)malloc(sizeof(size));
	for (int i = 0; i <= size; i++)
	{
		if (i == 0)
		{
			array[i] = size;
		}
		else
		{
			array[i] = rand() % maxValue;
		}
		I
	}
	return array;
}

void print(int* arr)
{
	for(int i =0; i<=arr[0]; i++)
	{
		if(i==0)
		{
			cout<<arr[0]<<": ";
		}
		if(i>0&&i!=arr[0])
		{
			cout<<arr[i]<<", ";
		}
		if(i==arr[0])
		{
			cout<<arr[i]<<"."<<endl;
		}
	}
}

int main()
{
	int size = rand() % 10;
	int maxValue = 100;
	int* arr = genRandArray(size, maxValue);
	print(arr);
	delete[] arr;
	return 0;
}
