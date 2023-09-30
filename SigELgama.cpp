#include <iostream>
#include <math.h>

using namespace std;
long long s1g, s2g, yg;

long long fastExponenriation(long long a, long long b, long long m){
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1){
            result = (result * a) % m; //Nhan vao kq lay modulo m.
        }
        a = (a * a) % m; // Binh phuong a va lay modulo m.
        b/=2;
    }
    return result;
}

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

void createKey(long long p, long long alpha, long long a){
    long long y = fastExponenriation(alpha, a, p); yg = y;
    
    cout << "Khoa bi mat la: " << a << endl;
    cout << "Khoa cong khai la: " << "(" << p <<", " << alpha << ", " << y << ")" << endl;
}

void kySo(long long p, long long alpha, long long a, long long x, long long k){
    cout << "Khoa ly: " << "(" << a << ", " << k << ")" << endl;
    long long inverseK = modInverse(k, p-1);

    long long S1 = fastExponenriation(alpha, k, p);
    long long S2 = (((x - a*S1)* inverseK) % (p-1));
    if (S2 < 0) S2 += (p-1);

    cout << "k^-1: " << inverseK << endl;

    cout << "S1 = " << S1 << endl; s1g = S1;
    cout << "S2 = " << S2 << endl; s2g = S2;
}

void kiemTraChuKy(long long s1, long long s2, long long p, long long alpha, long long x, long long y){
    long long kq1 = fastExponenriation(y, s1, p)*fastExponenriation(s1, s2, p);
    kq1 = kq1 % p;
   // kq1 = kq1 % p; if (kq1 < 0) kq1 += p;
    long long kq2 = fastExponenriation(alpha, x, p);
   // cout << "test: " << s1g << endl;
    cout << "y^S1* S1^S2 = " << kq1 << endl;
    cout << "alpha^x mod p = " << kq2 << endl;

    if (kq1 == kq2) cout << "Chu Ky Dung." << endl; else cout << "Chu Ky Sai." << endl;
}

void menu(){
    long long p, alpha, a, x, k;
    cout << "Moi nhap p: " << endl;
    cin >> p;
    cout << "Moi nhap alpha: " << endl;
    cin >> alpha;
    cout << "Moi nhap a: " << endl;
    cin >> a;
    cout << "Moi nhap x: " << endl;
    cin >> x;
    cout << "Moi nhap k: " << endl;
    cin >> k;
    int lc;
    //cin >> lc;
    do{
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "0. Thoat." << endl;
        cout << "1. Tao cap khoa." << endl;
        cout << "2. Ky so." << endl;
        cout << "3. Kiem tra chu ky." << endl;
        cout << "Ban chon ? " << endl;

        cin >> lc;
        switch (lc)
        {
            case 0: break;
            case 1:{
                createKey(p, alpha, a);
                break;
            }
            case 2:{
                kySo(p, alpha, a, x, k);
                break;
            }
            case 3:{
                kiemTraChuKy(s1g, s2g, p, alpha, x, yg);
            }
        default: cout << "Moi ban nhap lai." << endl; 
        }
    }while (lc);
}

int main(){
    menu();
    return 0;
}