#include <bits/stdc++.h>

using namespace std;

void tower(int n, string start, string middle, string end) {
    if (n == 1) {
        cout << "Move disk " << n << " from " << start << " to " << end << endl;
        return;
    }
    tower(n - 1, start, end, middle);
    cout << "Move disk " << n << " from " << start << " to " << end << endl;
    tower(n - 1, middle, start, end);
}

int main() {
    int n = 3;
    tower(n, "a", "b", "c");
}