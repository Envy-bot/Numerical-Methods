#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Number of data: ";
    cin >> n;

    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of x" << i + 1 << " y" << i + 1 << ": ";
        cin >> X[i] >> Y[i];
    }
    double Xp, Yp = Y[0];
    cout << "Enter the value of Xp: ";
    cin >> Xp;

    vector<vector<double>> table(n, vector<double>(n, 0));
    //Divided difference table calculation
    //First col is y
    for (int i = 0; i < n; i++) {
        table[i][0] = Y[i];
    }
    //Build Table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j-1] - table[i][j-1]) / (X[i+j] - X[i]);
        }
    }

    cout << "The divided difference table: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }

    //Applying divided difference table
    for (int i = 1; i < n; i++) {
        double pro = 1;
        for (int j = 0; j < i; j++) {
            pro *= (Xp - X[j]);
        }
        Yp += pro * table[0][i];
    }

    cout << fixed << setprecision(6) << "Y: " << Yp << endl;

    return 0;
}
/*
5
5 150
7 392
11 1452
13 2366
21 9702
6
*/