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
    double Xp, Yp = 0;
    cout << "Enter the value of Xp: ";
    cin >> Xp;

    for (int i = 0; i < n; i++) {
        double temp = 1;
        for (int j = 0; j < n; j++) {  
            if (i == j) continue;
            temp *= (Xp - X[j]) / (X[i] - X[j]);
        }
        Yp += temp * Y[i];
    }

    cout << fixed << setprecision(6) << "Y: " << Yp << endl;
    return 0;
}
/*
4
5 12
6 13
9 14
11 16
10
*/