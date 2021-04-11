class Solution {
   public:
    string h(int a, int b) {
        if (a == b) {
            return to_string(a);
        }
        return to_string(a) + "->" + to_string(b);
    }
    vector<string> summaryRanges(vector<int>& arr) {
        if (arr.size() == 1) {
            return {to_string(arr[0])};
        }
        int s = 0;
        int e = 0;
        int n = arr.size();
        arr.push_back(LONG_MAX);
        vector<string> res;
        int i = 0;
        while (i < n) {
            int s = i;
            int e = i;
            while (arr[i + 1] - arr[i] == 0 || arr[i + 1] - arr[i] == 1) {
                i++;
            }
            e = i;
            res.push_back(h(arr[s], arr[e]));
            i++;
        }
        return res;
    }
};