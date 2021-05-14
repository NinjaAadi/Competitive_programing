#include <bits/stdc++.h>

//Code for huffman encoding and decoding
using namespace std;

//Node for huffman tree
class Node {
   public:
    char curr;
    int feq;
    Node *left;
    Node *right;
    Node(int feq, char c) {
        this->curr = c;
        this->feq = feq;
    }
};

//To store the tree
priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> tree;
unordered_map<char, string> codes;  //Map to store the codes

//function to get character from integer

char getchar(int id) {
    return (char)('a' + id);
}

//Calculate fequency array for the string and insert into the priority queue
void feqcal(string &s) {
    if (s.size() == 1) {
        tree.push({1, new Node(1, s[0])});
        return;
    }
    int feq[27]; 
    memset(feq, 0, sizeof(feq));
    for (auto &i : s) {
        int id = i - 'a';
        feq[id]++;
    }

    //Insert it in the priority queue
    for (int i = 0; i < 27; i++) {   
        if (feq[i] > 0) {     
            Node *n = new Node(feq[i], getchar(i));
            tree.push({feq[i], n});
        }
    }
}

//Function to create Huffman Tree and return the root
Node *createHuffmanTree() {
    while (tree.size() > 1) {
        //Get the top 2 min fequence node
        auto first = tree.top();
        tree.pop();
        auto second = tree.top();
        tree.pop();
        //Create a new node
        int newfeq = first.first + second.first;
        Node *newnode = new Node(newfeq, '$');
        //Set the tree left and right
        newnode->left = first.second;
        newnode->right = second.second;

        //Insert the new node
        tree.push({newfeq, newnode});
    }
    Node *root = tree.top().second;

    return root;
}

string encode(string &s) {
    string encoded = "";
    for (auto i : s) {
        encoded += codes[i];
    }
    return encoded;
}

string decode(string &encoded, Node *root) {
    string res = "";
    Node *troot = root;
    for (auto &i : encoded) {
        if (i == '0' && troot->left != NULL) {
            troot = troot->left;
        } else {
            if (troot->right != NULL) {
                troot = troot->right;
            }
        }
        if (troot->curr != '$') {
            res += troot->curr;
            troot = root;
        }
    }
    return res;
}
//Dfs function to get the codes for character
void dfs(Node *curr, string s) {
    if (curr->curr != '$') {
        cout << curr->curr << " " << s << endl;
        codes[curr->curr] = s;
        return;
    }
    dfs(curr->left, s + '0');
    dfs(curr->right, s + '1');
}
int main() {
    string s;
    cin >> s;
    cout << "Original is : " << s << endl;
    feqcal(s);
    Node *root = createHuffmanTree();
    //Only one char
    if (root->left == NULL && root->right == NULL) {
        codes[root->curr] = '0';
    } else {
        dfs(root, "");
    }
    string encoded = encode(s);
    cout << "Encoded string is : " << encoded << endl;
    string decoded = decode(encoded, root);
    cout << "Decoded string is : " << decoded << endl;
}