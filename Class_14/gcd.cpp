//Program to calculate the gcd of two numbers
#include <bits/stdc++.h>

using namespace std;
//First we use euclid's theorm to calculate the gcd
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a % b);
}

//Now we use extended euclid algorithm to calculate gcd
int egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int res = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - floor(a / b) * y1;
    return res;
}
int main() {
    int x, y;
    cout << egcd(10, 14, x, y) << endl;
}