#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << -1 << endl; 
            } else {
                cout << 0 << endl; 
            }
        } else {
            double y = -c / b;
            if (y > 0) {
                cout << 2 << endl; 
            } else if (y == 0) {
                cout << 1 << endl; 
            } else {
                cout << 0 << endl; 
            }
        }
        return 0;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << 0 << endl; 
        return 0;
    }  
    int count = 0;
    if (delta == 0) {
        double y = -b / (2 * a);
        if (y > 0) {
            count = 2;
        } else if (y == 0) {
            count = 1; 
        }
    } else {
        double y1 = (-b + sqrt(delta)) / (2 * a);
        double y2 = (-b - sqrt(delta)) / (2 * a);
        if (y1 > 0) count += 2; 
        else if (y1 == 0) count += 1; 
        if (y2 > 0) count += 2; 
        else if (y2 == 0) count += 1; 
    }
    cout << count << endl;
    return 0;
}
