#include <iostream>

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
int main(){
    std::cout << fastExponenriation(105, 79, 589);
}

