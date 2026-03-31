#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    
    // Trý?ng h?p a = 0
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << -1 << endl; // Vô s? nghi?m
            } else {
                cout << 0 << endl; // Vô nghi?m
            }
        } else {
            double y = -c / b;
            if (y > 0) {
                cout << 2 << endl; // Có 2 nghi?m x = ±?y
            } else if (y == 0) {
                cout << 1 << endl; // Ch? có nghi?m x = 0
            } else {
                cout << 0 << endl; // Không có nghi?m
            }
        }
        return 0;
    }
    
    // Trý?ng h?p a ? 0, gi?i phýõng tr?nh ay² + by + c = 0
    double delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        cout << 0 << endl; // Không có nghi?m th?c
        return 0;
    }
    
    int count = 0;
    if (delta == 0) {
        double y = -b / (2 * a);
        if (y > 0) {
            count = 2; // Có 2 nghi?m x = ±?y
        } else if (y == 0) {
            count = 1; // Ch? có nghi?m x = 0
        }
    } else {
        double y1 = (-b + sqrt(delta)) / (2 * a);
        double y2 = (-b - sqrt(delta)) / (2 * a);
        if (y1 > 0) count += 2; // Có 2 nghi?m x = ±?y1
        else if (y1 == 0) count += 1; // Ch? có nghi?m x = 0
        if (y2 > 0) count += 2; // Có 2 nghi?m x = ±?y2
        else if (y2 == 0) count += 1; // Ch? có nghi?m x = 0
    }
    
    cout << count << endl;
    return 0;
}
