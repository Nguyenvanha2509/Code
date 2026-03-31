#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "vo so nghiem" << endl;
            } else {
                cout << "vo nghiem" << endl;
            }
        } else {
            double x = -c / b;
            cout << fixed << setprecision(3) << x << endl;
        }
        return 0;
    }
    
    double delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        cout << "vo nghiem" << endl;
    } else if (delta == 0) {
        double x = -b / (2 * a);
        cout << fixed << setprecision(3) << x << endl;
    } else {
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        if (x1 < x2) {
            cout << fixed << setprecision(3) << x1 << " " << x2 << endl;
        } else {
            cout << fixed << setprecision(3) << x2 << " " << x1 << endl;
        }
    }
    
    return 0;
}
