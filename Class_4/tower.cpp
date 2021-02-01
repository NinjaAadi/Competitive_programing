#include <bits/stdc++.h>

using namespace std;

void tower(int n, string start, string middle, string end) {
    //Base case 
    if (n == 1) {

        cout << "Move disk " << n << " from " << start << " to " << end << endl;
        return;
    }
    tower(n - 1, start, end, middle); // We are telling the recur. fun to move n -1 disks from start to middle using end
    cout << "Move disk " << n << " from " << start << " to " << end << endl; //Move the last disk directly from start to end tower without using any intermediate tower
    tower(n - 1, middle, start, end); // We are telling the recur fun to move the n-1 disks from middle to the end tower using the start tower.
}

int main() {
    int n = 3;
    tower(n, "a", "b", "c"); //The big problem
}
//a b c