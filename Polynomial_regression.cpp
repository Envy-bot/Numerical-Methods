#include <bits/stdc++.h>
using namespace std;

double determinant(vector<vector<double>> mat)
{
    int n = mat.size();
    if (n == 1)
        return mat[0][0];
    if (n == 2)
        return (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);

    double det = 0;
    for (int i = 0; i < n; i++)
    {
        vector<vector<double>> subMat(n - 1, vector<double>(n - 1));

        for (int row = 1; row < n; row++)
        {
            int subCol = 0;
            for (int col = 0; col < n; col++)
            {
                if (col == i) continue;
                subMat[row-1][subCol++] = mat[row][col];
            }
        }

        det += mat[0][i] * determinant(subMat) * pow(-1, i);
    }
    return det;
}

vector<double> cramersRule(vector<vector<double>> &A, vector<double> &B) {
    int n = A.size();
    vector<double> result(n, 0);

    double D = determinant(A);
    for (int i = 0; i < n; i++) {
        vector<vector<double>> Di = A;

        for (int j = 0; j < n; j++) {
            Di[j][i] = B[j];
        }

        result[i] = determinant(Di) / D;
    }

    return result;
}

int main()
{
    int n, degree;
    cout << "Numbre of data: ";
    cin >> n;

    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of x" << i + 1 << " y" << i + 1 << ": ";
        cin >> X[i] >> Y[i];
    }
    cout << "Enter the degree of polynomial: ";
    cin >> degree;
    int m = degree + 1;
    vector<vector<double>> C(m, vector<double>(m, 0));
    vector<double> B(m, 0);

    for (int row = 0; row < m; row++)
    {

        for (int col = 0; col < m; col++)
        {
            double sumC = 0;
            for (int i = 0; i < n; i++)
            {
                sumC += pow(X[i], row + col);
            }
            C[row][col] = sumC;
        }
        double sumB = 0;
        for (int i = 0; i < n; i++)
        {
            sumB += Y[i] * pow(X[i], row);
        }
        B[row] = sumB;
    }

    vector<double> coeff = cramersRule(C, B);

    cout << "y = ";
    for (int i = 0; i < m; i++)
    {
        cout << coeff[i];
        if (i >= 1)
            cout << "x^" << i;
        if (i < m - 1)
            cout << " + ";
    }

    return 0;
}
/*
4
1 6
2 11
3 18
4 27
2
*/