#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
bool check(char &a, char &b, int &k) {
    int x = a - 'a';
    int y = b - 'a';
    return ((x + k) % 26) == y;
}
int func(vector<int> &l, vector<int> &val, string &s, int &k) {
    int value = val[l[0]];
    for (int i = 0; i < l.size() - 1; i++) {
        if (check(s[l[i]], s[l[i + 1]], k)) {
            value += val[l[i + 1]];
        } else {
            return 0;
        }
    }
    return value;
}
void generatesub(string &s, int i, vector<int> &v1) {
    if (i == s.size()) {
        v.push_back(v1);
        return;
    }
    v1.push_back(i);
    generatesub(s, i + 1, v1);
    v1.pop_back();
    generatesub(s, i + 1, v1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    v.clear();
    while (t--) {
        int n, k;
        cin >> n >> k;
        k %= 26;
        string s;
        cin >> s;
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        vector<int> v1;
        generatesub(s, 0, v1);
        int mxm = 0;
        for (auto it : v) {
            if (it.size() == 0) continue;
            mxm = max(mxm, func(it, val, s, k));
        }
        cout << mxm << "\n";
    }
}