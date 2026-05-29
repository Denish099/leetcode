class Trie {
public:
    Trie* children[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }

    void insert(string word) {
        Trie* temp = this;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if (temp->children[idx] == NULL) {
                temp->children[idx] = new Trie();
            }

            temp = temp->children[idx];
        }

        temp->isEnd = true;
    }

    bool search(string word) {
        Trie* temp = this;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if (temp->children[idx] == NULL) {
                return false;
            }

            temp = temp->children[idx];
        }

        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* temp = this;

        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';

            if (temp->children[idx] == NULL) {
                return false;
            }

            temp = temp->children[idx];
        }

        return true;
    }
};