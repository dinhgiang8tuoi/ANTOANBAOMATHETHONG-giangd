#include <iostream>

using namespace std;
long long c1,d1; // Luu c và d trong fucntion;

// Nghich dao modulo:
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

// Tinh so mu lon : (Ma hoa ban ro, Giai ma ban ro)
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

// Thu tuc sinh khoa'
void sinhKhoa(long long p, long long q, long long e){
    long long temp = p*q;
    long long temp1 = (p-1) * (q-1);
    long long d = modInverse(e, temp1);
    cout << "Khoa cong khai : K = {" << e << ',' << temp << '}' << endl;
    cout << "Khoa bi mat : K = {" << d << ' ' << temp << '}' << endl;
    d1=d;
}

void menu(){
    long long p, q, e;
    long long m;
        cout << "Nhap p: " << endl;
        cin >> p;
        cout << "Nhap q: " << endl;
        cin >> q;
        cout << "Nhap e: " << endl;
        cin >> e;
    long long n=p*q;
    int lc;
    do{
        cout << endl;
        cout << "0.Thoat " << endl;
        cout << "1.Thu tuc sinh khoa RSA " << endl;
        cout << "2.Thu tuc ma hoa RSA " << endl;
        cout << "3.Thu tuc giai ma RSA " << endl;
        cout << "Ban chon ? " << endl;
        cin >> lc;
        cout << endl;
        switch( lc ){
            case 0: break;
            case 1: {
                sinhKhoa(p, q, e);
                break;
            }
            case 2:{
                cout << "C = M^e mod N" << endl;;
                cout << "Nhap m: ";
                cin >> m;
                c1 = fastExponenriation(m, e, n);
                cout << "Ban ma C = " << c1 << endl;
                break;
            }
            case 3:{
                cout << "G = C^d mod N" << endl;
                cout << "Giai ma G = " << fastExponenriation(c1, d1, n) << endl;
                break;
            }
            default: cout << "Nhap lai " << endl;;
        }
    } while( lc ); // while lc!=0;

}
int main(){
    menu();
    return 0;
}