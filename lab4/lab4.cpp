#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

template <typename T>

class Matrix {
public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        matrix = new T*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new T[m];
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }
        
        // Удаление старых данных
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        n = other.n;
        m = other.m;
        matrix = new T*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new T[m];
            for (int j = 0; j < m; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }

    Matrix(){
 n = m = 0;
 
 }

    ~Matrix() {
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void SetM(int i, int j, T chislo) {
        matrix[i][j] = chislo;
    }

    void GetM(int i, int j) {
        cout << "Взятое число: " << matrix[i][j] << endl;
    }

private:
    T** matrix;
    int n;
    int m;
};

int main() {
    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    Matrix<int> matr(n, m);
    cout << "Матрица:" << endl;
    matr.print();

    Matrix<int> matr1(n, m);
    matr1 = matr;
    cout << "Скопированная матрица:" << endl;
    matr1.print();

    matr.SetM(0, 0, 15);
    cout << endl;
    matr.print();
    matr.GetM(0, 0);

    return 0;
}
