#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    bool isend;
    Node *child[26];
    Node() {
        isend = false;
    }
};

Node *head;
void insert(string &s) {
    Node *temp = head;
    for (int i = 0; i < s.size(); i++) {
        int curr = s[i] - 'a';
        if (temp->child[curr] == NULL) {
            temp->child[curr] = new Node();
        }
        temp = temp->child[curr];
    }
    temp->isend = true;
}

bool search(string &s) {
    Node *temp = head;
    for (int i = 0; i < s.size(); i++) {
        int curr = s[i] - 'a';
        if (temp->child[curr] == NULL) return false;
        temp = temp->child[curr];
    }
    return temp->isend;
}
int main() {
    head = new Node();
    vector<string> arr = {"acd", "abc", "agfc", "atgs", "agfr"};
    for (auto &i : arr) {
        insert(i);
    }
    string s = "a";
    cout << search(s) << "\n";
}