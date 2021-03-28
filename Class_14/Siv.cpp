#include <bits/stdc++.h>

using namespace std;
const int n = 10e5 + 5;
bool isprime[n + 5];

void siv() {
    for (int i = 0; i < n; i++) {
        isprime[i] = true;
    }
    //Set 1 as false
    isprime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (isprime[i]) {
            //Make all multiples of i as non prime
            for (long long int k = i * i; k < n; k += i) {
                isprime[k] = false;
            }
        }
    }
}

int main() {
    siv();
    //Query part goes here
}