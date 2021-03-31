#include <bits/stdc++.h>
#define pb push_back
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cerr << #x << " = " << x << " and " << #y << " = " << y << endl;
using namespace std;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//partition the pivort
int partition(int arr[], int l, int r) {
    //Random number from l - r
    //rand()%(l-r+1) + l;
    // int t = rand() % (r - l + 1) + l;
    // swap(&arr[t], &arr[r]);
    int pivort = arr[r];

    //Move all the elements smaller than the pivort to the left of the pivort and move all the greater element to the right of the pivort
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivort) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}
int n;
//Quick sort function
void quicksort(int l, int r, int arr[]) {
    whatis2(l,r);
    if (l > r) {
        return;
    }
    int pi = partition(arr, l, r);
    quicksort(l, pi - 1, arr);
    quicksort(pi + 1, r, arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    clock_t start, end;
    start = clock();
    quicksort(0, n - 1, arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cerr << " sec " << endl;
}