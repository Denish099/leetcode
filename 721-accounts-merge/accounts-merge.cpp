class Solution {
public:
    struct DSU {

        vector<int> parent;
        vector<int> size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {

            if (parent[x] == x) {
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {

            a = find(a);
            b = find(b);

            if (a == b) {
                return false;
            }

            if (size[a] < size[b]) {
                swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];

            return true;
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end()) {

                    mp[mail] = i;

                } else {

                    dsu.unite(i, mp[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> groups;

        for (auto& [mail, account] : mp) {

            int root = dsu.find(account);

            groups[root].push_back(mail);
        }

        vector<vector<string>> ans;

        for (auto& [root, mails] : groups) {

            sort(mails.begin(), mails.end());

            vector<string> temp;

            temp.push_back(accounts[root][0]);

            for (string& mail : mails) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};