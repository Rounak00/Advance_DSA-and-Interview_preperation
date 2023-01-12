//Leetcode 1519
class Solution {
public:
    void dfs(int i, string &l, vector<vector<int>>& al, int cnt[], vector<int> &res) {

    if (res[i] == 0) {

        res[i] = 1;

        for (auto j : al[i]) {

            int cnt1[26] = {};

            dfs(j, l, al, cnt1, res);

            for (auto k = 0; k < 26; ++k)

                cnt[k] += cnt1[k];

        }

        res[i] = ++cnt[l[i] - 'a'];

    }

}

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

    vector<int> res(n);

    int cnt[26] = {};

    vector<vector<int>> al(n);

    for (auto &e : edges) {

        al[e[0]].push_back(e[1]);

        al[e[1]].push_back(e[0]);

    }

    dfs(0, labels, al, cnt, res);

    return res;

}
        
    
};