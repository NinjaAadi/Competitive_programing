#include <bits/stdc++.h>

using namespace std;

//heap creation
class Maxheap {
   public:
    int lastindex;
    vector<int> arr;
    Maxheap() {
        lastindex = -1;
        this->arr.resize(1e5, INT_MIN);
    }
    void heapifyup(int index) {
        //Base Case
        if (index == 0) return;

        //Current index
        //Parent ->  floor (index-1)/2;
        int par = floor((index - 1) / 2.0);
        if (this->arr[par] <= this->arr[index]) {
            swap(this->arr[par], this->arr[index]);
            this->heapifyup(par);
        }
        //if is is valid then do nothing
    }
    void heapifydown(int index) {
        int leftchildid = 2 * index + 1;
        int rightchildid = 2 * index + 2;
        //Base case
        if (leftchildid > this->lastindex) return;
        int nextchildid = this->arr[leftchildid] > this->arr[rightchildid] ? (leftchildid) : (rightchildid);

        if (this->arr[index] <= this->arr[nextchildid]) {
            swap(this->arr[index], this->arr[nextchildid]);
            this->heapifydown(nextchildid);
        }
    }

    //Function to insert value to the heap
    void insert(int val) {
        //Insert at the last position
        this->arr[++lastindex] = val;

        //Heapify the heap
        this->heapifyup(lastindex);
    }

    //Function to delete from heap

    void pop() {
        //Delete from the root
        //Replace the last element
        swap(this->arr[0], this->arr[lastindex--]);
        this->arr[lastindex + 1] = INT_MIN;
        //Heapify down
        heapifydown(0);
    }
    int top() {
        //Return the root value;
        return this->arr[0];
    }
    int size() {
        return this->lastindex + 1;
    }
};
int main() {
    vector<int> arr = {4, 3, 2, 5, 1};
    Maxheap *pq = new Maxheap();
    for (auto &i : arr) pq->insert(i);
    pq->insert(1000);
    while (pq->size()) {
        cout << pq->top() << " ";
        pq->pop();
    }
    cout << endl;
}
/*

    0(7)
 /   \
1(6)     2(4)

*/