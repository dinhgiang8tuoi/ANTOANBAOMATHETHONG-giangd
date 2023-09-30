#include <iostream>

using namespace std;
long long s;

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
void enCode(long long p, long long q, long long e, long long M){
    long long temp = p*q;
    long long temp1 = (p-1) * (q-1);
    long long d = modInverse(e, temp1);
    cout << "Khoa cong khai : K = {" << e << ',' << temp << '}' << endl;
    cout << "Khoa bi mat : K = {" << d << ' ' << temp << '}' << endl;
    long long sigKey = fastExponenriation(M, d, temp);
    cout << "Sinh chu ky : S = " << sigKey << endl;
    s = sigKey;
}

void checkSig(long long n, long long e, long long s, long long M){
    long long check = fastExponenriation(s, e, n);
    if (check == M) cout << "m' = S^e mod n == M -> " << check << " == " << M << " -> TRUE" << endl; 
     else cout << "m' != M " << check << " != " << M << "FALSE" << endl;
}

void menu(){
    long long p, q ,e;
    long long M;
    cout << "Moi nhap p: " << endl;
    cin >> p;
    cout << "Moi nhap q: " << endl;
    cin >> q;
    cout << "Moi nhap e: " << endl;
    cin >> e;
    cout << "Moi nhap M: " << endl;
    cin >> M;

    int lc;
    do{ 
        cout << endl;
        cout << "0.Exit" << endl;
        cout << "1.Sinh Khoa và Sinh Chu Ky" << endl;
        cout << "2.Xac Dinh Chu Ky" << endl;
        cout << "Ban chon ? " << endl;
        cin >> lc;

        switch (lc)
            {
            case 0: break;
            case 1:{
                cout << "Ma Hoa va Sinh Chu Ky:  " << endl;
                enCode(p, q, e, M);
                break;
            }
            case 2:{
                cout << "Xac Dinh Chu Ky: " << endl;
                checkSig(p*q, e, s, M);
                break;
            }
            default: cout << "Moi Ban Nhap Lai: ... " << endl;
            }
    }while(lc);
}
int main(){
    menu();
    return 0;
}



