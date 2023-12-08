#include <iostream>

using namespace std;

struct Coo
{
	int x;
	int y;
};

int** genMatrix(int N)
{
	srand(time(0));
	int** arr= new int* [N];
	if(!arr)
		return 0;
	for(int i= 0; i< N;i++)
	{
		arr[i]= new int [N];
		if (!arr[i])
			return 0;
	}
	for(int i= 0; i< N;i++)
	{
		for(int j= 0; j<N; j++)
		{
			arr[i][j]= rand()% 100;
			cout.width(2);
			cout << arr[i][j]<< " ";
		}
		cout << "\n";
	}
	return arr;
}

void a_point(int N, int** arr,  int* D) // по правым диагоналям, начиная с правого верхнего элемента
{
	Coo point= {N-1, 0};
	int inD= 0;
	int x;
	int y;
	while(point.x>0)
	{
		x= point. x;
		y= point.y;
		for(int i= 0; i< N-point.x; i++)
		{
			D[inD++]= arr[y][x];
			y++;
			if(x< N-1)
				x++;
		}
		point.x--;
	}

	while(point.y< N)
	{
		x= point.x;
		y= point.y;

		for(int i= 0; i< N-point.y; i++)
		{
			D[inD++]= arr[y][x];
			x++;
			if(y< N-1)
				y++;
		}
		point.y++;
	}

}

void b_point(int N, int** arr,  int* D) // по левым диагоналям, начиная с левого верхнего элемента
{
	Coo point= {0, 0};
	int inD= 0;
	int x;
	int y;
	while(point.x< N-1)
	{
		x= point.x;
		y= point.y;
		for(int i= 0; i< point.x+1; i++)
		{
			D[inD++]= arr[y][x];
			y++;
			if(x> 0)
				x--;
		}
		point.x++;
	}

	while(point.y< N)
	{
		x= point.x;
		y= point.y;

		for(int i= 0; i< N-point.y; i++)
		{
			D[inD++]= arr[y][x];
			x--;
			if(y< N-1)
				y++;
		}
		point.y++;
	}
}

void nextSide(int *side)
{
	(*side)++;
	if(*side> 3)
		*side= 0;
}

void record(int side, int *inD, Coo* point, int **arr, int *D)
{
	switch (side)
	{
		case 0:
			D[(*inD)++]= arr[point->y][(point->x)--];
			break;
		case 1:
			D[(*inD)++]= arr[(point->y)--][point->x];
			break;
		case 2:
			D[(*inD)++]= arr[point->y][(point->x)++];
			break;
		case 3:
			D[(*inD)++]= arr[(point->y)++][point->x];
	}
}


void c_point(int N, int** arr,  int* D) // по спирали, начиная с центрального элемента
{
	Coo point= {N/2, N/2};
	int side= 0; // сторона движения 0-лево 1-вверх 2-вправо 3-вниз
	int length= 0; // длинна текущего участка спирали
	int inD= 0; // индекс для массива D
	int side_num= 0; // номер 2-x смежных сторон спирали одной длины
	int exp_length= 1; // ожидаемая длина стороны спирали

	while(exp_length<= N)
	{
		for(int i= 0; i< 2; i++)
		{
			for(length= 0; length< exp_length; length++)
				record(side, &inD, &point, arr, D);
			nextSide(&side);
		}
		side_num++;
		exp_length= 1+side_num;
	}
} 


void d_point(int N, int** arr,  int* D) // по спирали, начиная с левого верхнего элемента
{
	Coo point= {0, 0};
	int side= 2; // сторона движения 0-лево 1-вверх 2-вправо 3-вниз
	int length= 0; // длинна текущего участка спирали
	int inD= 0; // индекс для массива D
	int side_num= 0; // номер 2-x смежных сторон спирали одной длины
	int exp_length= N-1; // ожидаемая длина стороны спирали

	for(int i= 0; i< N-1; i++)// записываем первый "лишний" ряд
		record(side, &inD, &point, arr, D);
	nextSide(&side);

	while(exp_length>0)
	{
		for(int i= 0; i< 2; i++)
		{
			for(length= 0; length< exp_length; length++)
				record(side, &inD, &point, arr, D);
			nextSide(&side);
		}
		side_num++;
		exp_length= N-1-side_num;
	}
	D[inD]= arr[point.y][point.x]; // запись последнего элемента
}

void print_arr (int D[], int N)
{
	for(int i= 0; i< N*N; i++)
		cout << D[i] << " ";
	cout << "\n";
}

int main()
{
	int N= 4;
	int** arr= genMatrix(N);
	if(!arr)
		return 1;
	int* D= new int [N*N];

	cout << "a) по правым диагоналям, начиная с правого верхнего элемента\n";
	a_point(N, arr, D);
	print_arr (D, N);

	cout << "b) по левым диагоналям, начиная с левого верхнего элемента\n";
	b_point(N, arr, D);
	print_arr (D, N);

	cout << "c) по спирали, начиная с центрального элемента\n";
	c_point(N, arr, D);
	print_arr (D, N);

	cout << "d) по спирали, начиная с левого верхнего элемента\n";
	d_point(N, arr, D);
	print_arr (D, N);

	delete [] D;
	for(int i= 0; i< N; i++)
	{
		delete[]  arr[i];
	}
	delete [] arr;
	return 0;
}
