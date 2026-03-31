#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int S, n, T;
    cin >> S >> n >> T;
    
    double sum_ab = (double)(T - n * n) / n;
    double delta = sum_ab * sum_ab - 4 * S;
    
    if (delta < 0) {
        cout << "Khong co nghiem thoa man";
        return 0;
    }
    
    double sqrt_delta = sqrt(delta);
    double a = (sum_ab + sqrt_delta) / 2;
    double b = (sum_ab - sqrt_delta) / 2;

    int a_int = (int)(a + 0.5); 
    int b_int = (int)(b + 0.5);
    
    if (a_int * b_int == S && 
        a_int + b_int == sum_ab && 
        a_int >= b_int && b_int > 0) {
        cout << a_int << " " << b_int;
    } else {
        cout << "Khong co nghiem thoa man";
    } 
    return 0;
}
