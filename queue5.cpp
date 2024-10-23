#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số siêu nguyên tố
bool isSuperPrime(int n) {
    // Kiểm tra nếu n không là số nguyên tố
    if (!isPrime(n)) return false;
    
    // Lần lượt xóa chữ số cuối cùng và kiểm tra
    while (n > 0) {
        n /= 10;  // Xóa chữ số cuối
        if (n > 0 && !isPrime(n)) return false;
    }
    
    return true;
}

vector<int> superPrimeNumber(int n) {
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (isSuperPrime(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    
    vector<int> superPrimes = superPrimeNumber(n);
    
    cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la: ";
    for (int prime : superPrimes) {
        cout << prime << " ";
    }
    
    return 0;
}
