#include <bits/stdc++.h>


//Program to find all the factors of the number
using namespace std;
void print(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (i == n / i && n % i == 0) {
            cout << i << " ";
        } else if (n % i == 0) {
            cout << i << " " << n / i << " ";
        }
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    print(n);
}