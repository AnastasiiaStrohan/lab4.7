#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double xp, xk, x, dx, eps, a, S, R;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed << setprecision(5);

    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
        << setw(15) << "ln(x) " << " |"
        << setw(15) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "---------------------------------------------------------" << endl;

    for (x = xp; x <= xk; x += dx) {
        if (x <= 0) {
            cout << "ln(x)." << endl;
            continue;
        }

        S = 0; 
        a = (x - 1) / (x + 1); 
        R = a; 
        n = 0;

        
        while (abs(R) > eps) {
            S += R;
            n++;
            R = a * pow((x - 1) / (x + 1), 2 * n) / (2 * n + 1);
        }

        S *= 2; 

        cout << "|" << setw(10) << x << " |"
            << setw(15) << log(x) << " |" 
            << setw(15) << S << " |"
            << setw(5) << n << " |" << endl;
    }

    cout << "---------------------------------------------------------" << endl;

    return 0;
}
