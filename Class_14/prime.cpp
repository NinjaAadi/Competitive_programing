#include <bits/stdc++.h>

using namespace std;

bool isprime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {

        //If it is divisible by any i then it is not a prime number
        if (n % i == 0) return false;
    }
    //Else it is a prime number
    return true;
}
int main() {
    int n;
    cin >> n;
    if (isprime(n)) {
        cout << n << " is a prime number\n";
    } else {
        cout << n << " is not a prime number\n";
    }
}