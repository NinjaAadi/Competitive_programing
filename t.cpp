#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
};

struct LinkedList {
    Node *head = NULL;
    void insert(int val) {
        if (head == NULL) {
            head = (Node *)malloc(sizeof(Node));
            head->val = val;
            head->next = NULL;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = (Node *)malloc(sizeof(Node));
            temp->next->val = val;
        }
    };
    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList *l1 = new LinkedList();
    l1->insert(1);
    l1->insert(2);
    l1->insert(3);
    l1->print();
}

