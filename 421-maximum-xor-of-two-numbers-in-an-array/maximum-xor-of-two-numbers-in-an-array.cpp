const int LOG = 30;

struct Node {
    Node* lists[2] = {};
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node* curr = root;

        for (int i = LOG; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (curr->lists[bit] == nullptr) {
                curr->lists[bit] = new Node();
            }

            curr = curr->lists[bit];
        }
    }

    int getMaxXor(int x) {
        Node* curr = root;
        int ans = 0;

        for (int i = LOG; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = bit ^ 1;

            if (curr->lists[want] != nullptr) {
                ans |= (1 << i);
                curr = curr->lists[want];
            } else {
                curr = curr->lists[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    Trie* trie = new Trie();

    int findMaximumXOR(vector<int>& nums) {
        for (int x : nums) {
            trie->insert(x);
        }

        int ans = 0;

        for (int x : nums) {
            ans = max(ans, trie->getMaxXor(x));
        }

        return ans;
    }
};