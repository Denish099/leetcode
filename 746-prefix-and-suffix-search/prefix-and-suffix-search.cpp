struct Node{
    Node* list[27] = {};
    int index = -1;
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string s,int idx){
        Node* curr = root;

        for (char c:s){
            int x;
            if(c == '#'){
                x = 26;
            }else{
                x =  c - 'a';
            }

            if(curr->list[x] == nullptr){
                curr->list[x] = new Node();
            }
            curr = curr->list[x];
            curr->index = max(curr->index,idx);
        }
    }

    int search(string s){
        Node* curr = root;

        for(char c:s){
            int x;
            if(c == '#'){
                x = 26;
            }else{
                x =  c - 'a';
            }

            if(curr->list[x] == nullptr){
                return -1;
            }
            curr = curr->list[x];
        }
        return curr->index;
    }
};

class WordFilter {
    Trie* trie = new Trie();

public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            for (int j = 0; j < word.size(); j++) {
                string s = word.substr(j) + "#" + word;
                trie->insert(s, i);
            }
        }
    }

    int f(string pref, string suff) {
        return trie->search(suff + "#" + pref);
    }
};