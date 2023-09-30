#include <iostream>

using namespace std;
long long beta = 0, temp = 0, C1 = 0, C2 = 0; //global varrible

//Tinh so mu lon:
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

void maHoa(long long alpha, long long x, long long p, long long M, long long k){
    beta = fastExponenriation(alpha, x, p) % p;                                     //beta == y.
    cout <<"y = alpha^x mod p:  " << beta << endl;
    cout << "Ks: " << x << endl;
    cout << "Kp: " << p << ',' << alpha << ',' << beta << endl;
    temp = fastExponenriation(beta, k, p);                                          //temmp == K.
    cout << "K = y^k mod p:  " << temp << endl;
    C1 = fastExponenriation(alpha, k, p);
    cout << "C1 = alpha^k mod p: " << C1 << endl;
    C2 = (temp*M % p);
    cout << "C2 = (K*M) mod p: " << C2 << endl;
    cout << "Vay Ban Ma Duoc Gui Di La C = (" << C1 << ',' << C2 << ')' << endl;
}

void giaiMa(long long x, long long p){
    cout << "Ta tinh lai K " << endl;
    long long mu = p - 1 - x;
    long long K1 = fastExponenriation(C1, mu, p);
    cout << "K = C1^(p-1-x) mod p: " << K1 << endl;
    cout << "M = (K* C2) mod p: " << K1* C2 % p << endl;
}

void menu(){
    long long p, alpha, x, k;
    long long M;
    cout << "Moi nhap p: " << endl;
    cin >> p;
    cout << "Moi nhap alpha: " << endl;
    cin >> alpha;
    cout << "Moi nhap x: " << endl;
    cin >> x;
    cout << "Moi nhap k: " << endl;
    cin >> k;
    cout << "Moi nhap M: " << endl;
    cin >> M;
    int lc;
    do{
        cout << endl;
        cout << "0. Thoat " << endl;
        cout << "1. Ma Hoa He Ma " << endl;
        cout << "2. Giai Ma He Ma " << endl;
        //cout << "3. Giai Ma Ban Ro Ban Dau " << endl;
        cout << "Ban Chon. ?" << endl;
        cin >> lc;
        switch (lc){
        case 0: 
            break;
        case 1:{
            cout << "Ma Hoa: " << endl;
            maHoa(alpha, x, p, M, k);
            break;
        }
        case 2:{
            cout << "Giai Ma: " << endl;
            giaiMa(x, p);
            break;
        }
        default: cout << "Moi Ban Nhap Lai. " << endl;
        }
    } while (lc);
}
int main(){
    menu();
    return 0;
}