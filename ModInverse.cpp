#include <iostream>

using namespace std;

int extendedEculid(int a, int b, int &x, int &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedEculid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
int modInverse(int a, int n){
    int x, y;
    int gcd = extendedEculid(a, n, x, y);
    if (gcd != 1) {
        // Khong ton tai modulo dao nhuoc vi a va b khong nguyen to cung nhau.
        return -1;
    }
    x=(x % n + n) % n;
    return x;
}

int main(){
    cout << modInverse(83,792);
}