class Solution {
public:
    struct trieNode {
        int idx;
        unordered_map<char, trieNode*> children;

        trieNode(int i) {
            idx = i;
        }

        ~trieNode() {
            for (auto& it : children) {
                delete it.second;
            }
        }
    };

    void insertTrie(trieNode* root, int i,
                    vector<string>& wordsContainer) {

        string& word = wordsContainer[i];
        int n = word.size();

        if (wordsContainer[root->idx].size() > n) {
            root->idx = i;
        }

        for (int j = n - 1; j >= 0; j--) {
            char ch = word[j];

            if (root->children.find(ch) == root->children.end()) {
                root->children[ch] = new trieNode(i);
            }

            root = root->children[ch];

            if (wordsContainer[root->idx].size() > n) {
                root->idx = i;
            }
        }
    }

    int searchTrie(trieNode* root, string& word) {
        int res_idx = root->idx;

        for (int i = word.size() - 1; i >= 0; i--) {
            char ch = word[i];

            if (root->children.find(ch) == root->children.end()) {
                return res_idx;
            }

            root = root->children[ch];
            res_idx = root->idx;
        }

        return res_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int n = wordsQuery.size();
        vector<int> res(n);

        trieNode* root = new trieNode(0);

        for (int i = 0; i < wordsContainer.size(); i++) {
            insertTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            res[i] = searchTrie(root, wordsQuery[i]);
        }

        delete root; // calls destructor recursively

        return res;
    }
};