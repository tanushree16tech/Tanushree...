#include <iostream>
using namespace std;

class Matrix {
    int **a, m, n;

public:
    Matrix(int r, int c) {
        m = r; n = c;
        a = new int*[m];

        for(int i = 0; i < m; i++)
            a[i] = new int[n];
    }

    Matrix(const Matrix &x) {
        m = x.m; n = x.n;
        a = new int*[m];

        for(int i = 0; i < m; i++) {
            a[i] = new int[n];
            for(int j = 0; j < n; j++)
                a[i][j] = x.a[i][j];
        }
    }

    ~Matrix() {
        for(int i = 0; i < m; i++)
            delete[] a[i];
        delete[] a;
    }

    void display() {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    void set() {
        int x = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = x++;
    }
};

int main() {
    Matrix m1(2,2);
    m1.set();

    Matrix m2 = m1;

    cout << "Copied Matrix:" << endl;
    m2.display();
}