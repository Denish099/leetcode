struct Node {
    Node* list[26] = {};
    int sum = 0;
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string s, int val) {
        Node* curr = root;

        for (char c : s) {
            int x = c - 'a';

            if (curr->list[x] == nullptr) {
                curr->list[x] = new Node();
            }

            curr = curr->list[x];
            curr->sum += val;
        }
    }

    int search(string prefix) {
        Node* curr = root;

        for (char c : prefix) {
            int x = c - 'a';

            if (curr->list[x] == nullptr) {
                return 0;
            }

            curr = curr->list[x];
        }

        return curr->sum;
    }
};

class MapSum {
    Trie* trie;
    unordered_map<string, int> mp;

public:
    MapSum() {
        trie = new Trie();
    }

    void insert(string key, int val) {
        int diff = val - mp[key];

        mp[key] = val;

        trie->insert(key, diff);
    }

    int sum(string prefix) {
        return trie->search(prefix);
    }
};