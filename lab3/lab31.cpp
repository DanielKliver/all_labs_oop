#include<iostream>


using namespace std;

class work_with_matrix{

	public:
		work_with_matrix()
		{
			int** arr = new int* [0];
			for(int i = 0; i<0; i++)
			{
				arr[i] = new int[0];
			}
			cout<<"Матрица инициализирована"<<endl;
		}

	public:

		work_with_matrix(int intsize_y, int intsize_x)
		{
			int** arr = new int* [intsize_y];
			for(int i = 0; i<0; i++)
			{
				arr[i] = new int[intsize_y];
			}
			cout<<"Матрица, указанной размерности инициализирована."<<endl;
		}

	public:
		work_with_matrix(int intsize)
		{
			int** arr = new int* [intsize];
			for(int i = 0; i<intsize; i++)
			{


				arr[i] = new int[intsize];


			}

			int counter = intsize-1;
			for(int i = 0; i<intsize;i++)
			{
				for(int j=0; j<intsize;j++)
				{
					if(j==counter)
					{
						arr[i][j] = 1;
						counter--;
					}
					else
					{
						arr[i][j] = 0;
					}
				}
			}

		}
		void arr_num_user()
		{
			cout << "Enter array numbers" << endl;
			for (int i = 0; i < intsize_y; i++)
			{
				for (int j = 0; j < intsize_x; j++)
				{
					int a = 0;
					cin >> a;
					arr[i][j] = a;
				}
			}
		}
		void arr_num_rand()
		{
			srand(time(0));
			for (int i = 0; i < intsize_y; i++)
			{
				for (int j = 0; j < intsize_x; j++)
				{
					arr[i][j] = rand() % 100;
				}
			}
		}
		void print_matrix()
		{
			cout << "Matrix";
			for (int i = 0; i < intsize_y; i++)
			{
				cout << endl;
				for (int j = 0; j < intsize_x; j++)
					cout << arr[i][j] << " ";
			}
			cout << endl
				<< endl;
		}
		void sum_matrix()
		{
			for (int i = 0; i < intsize_y; i++)
			{
				for (int j = 0; j < intsize_x; j++)
				{
					sum += arr[i][j];
				}
			}
			cout << "Sum:" << sum << endl;
			cout << endl;
		}
		void multiply_i_j()
		{
			for (int i = 0; i < intsize_y; i++)
			{
				for (int j = 0; j < intsize_x; j++)
				{
					arr[i][j] = i * j;
				}
			}
		}
		~Matrix()
		{
			for (int i = 0; i < n; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
		}




};

int main()
{

	cout<<"Введите размерность матрицы:"<<endl;
	int intsize = 0;
	cin>>intsize;
	cout<<endl;
	work_with_matrix obj1;
	cout << "obj2" << endl;
	work_with_matrix obj2(intsize)
		obj2.print_matrix();
	obj2.multiply_i_j();
	obj2.print_matrix();
	int intsize_y, intsize_x;
	cout<<"Введите y матрицы: ";
	cin>>intsize_y;
	cout<<endl<<"Введите x матрицы: ";
	cin>>intsize_x;
	cout<<endl;
	work_with_matrix obj3(intsize_y, intsize_x);
	cout << "obj3" << endl;
	obj3.print_matrix();
	obj3.arr_num_rand();
	obj3.print_matrix();
	obj3.sum_matrix();
	cout<<"Введите y матрицы: ";
	cin>>intsize_y;
	cout<<endl<<"Введите x матрицы: ";
	cin>>intsize_x;
	cout<<endl;
	work_with_matrix obj4(intsize_y, intsize_x);
	cout << "obj4" << endl;
	obj4.print_matrix();
	obj4.arr_num_user();
	obj4.print_matrix();


	return 0;
}
