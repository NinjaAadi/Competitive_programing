#include <bits/stdc++.h>
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int s = (r - l + 1);
    int a[s];
    int i = l;      //first array
    int j = m + 1;  //second array;
    int k = 0;
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            a[k] = arr[i];
            i++;
        } else if (arr[j] < arr[i]) {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        a[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        a[k] = arr[j];
        j++;
        k++;
    }
    k = 0;
    //merged the array now we need to copy the array to main array
    for (int i = l; i <= r; i++) {
        arr[i] = a[k];
        k++;
    }
}

void mergesort(int arr[], int l, int r, int n) {
    whatis2(l, r);
    //Base condition
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergesort(arr, l, m, n);
    mergesort(arr, m + 1, r, n);
    merge(arr, l, m, r);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    //The array is already broken into single pieces
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
