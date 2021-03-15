//Program to find the prime factorization
#include <bits/stdc++.h>

using namespace std;

void primefact(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n = n / i;
            }
            cout << i << "^" << count << endl;
        }
    }
    if (n > 1) {
        cout << n << "^" << 1 << endl;
    }
}
int main() {
    int n;
    cin >> n;
    primefact(n);
}