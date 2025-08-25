#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Numbre of data: ";
    cin >> n;

    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cout << "Enter the value of x" << i + 1 << " y" << i + 1 << ": ";
        cin >> X[i] >> Y[i];
    }
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, a, b;

    for (int i = 0; i < n; i++)
    {
        sumX += log(X[i]);
        sumY += log(Y[i]);
        sumXY += log(X[i]) * log(Y[i]);
        sumX2 += log(X[i]) * log(X[i]);
    }
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = exp((sumY - b * sumX) / n);

    cout << fixed << setprecision(6) << "a : " << a << " " << "b: " << b << endl;

    return 0;
}
