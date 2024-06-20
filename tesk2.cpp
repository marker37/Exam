//Реалізуйте клас Matrix, що представляє матрицю.Напишіть конструктор
//копіювання, що глибоко копіює елементи матриці.Поясніть, як використовується
//вказівник this у методах класу Matrix.

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;

public:

    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {

        data = new double* [rows];
        for (int i = 0; i < rows; ++i)
        {

            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = 0.0;
            }
        }
    }
    //


    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
    {

        data = new double* [rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j)
            {

                data[i][j] = other.data[i][j];
            }
        }
    }





    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }




    Matrix& operator=(const Matrix& other)
    {
        if (this == &other)
        {
            return *this;
        }


        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new double* [rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }





    void setElement(int row, int col, double value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        }
    }



    double getElement(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        }
        return 0.0;

    }



    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};



void main()
{
    Matrix mat1(2, 3);
    mat1.setElement(0, 0, 1.0);
    mat1.setElement(0, 1, 2.0);
    mat1.setElement(0, 2, 3.0);
    mat1.setElement(1, 0, 4.0);
    mat1.setElement(1, 1, 5.0);
    mat1.setElement(1, 2, 6.0);

    cout << "Matrix 1:" << endl;
    mat1.print();


    Matrix mat2 = mat1;

    cout << "Matrix 2 (after copy):" << endl;
    mat2.print();


    mat2.setElement(0, 0, 7.0);
    cout << "Matrix 2 (after modification):" << endl;
    mat2.print();


    cout << "Matrix 1 (after modifying Matrix 2):" << endl;
    mat1.print();



}






// this вказує на  об'єкт класу, для якого викликається метод






