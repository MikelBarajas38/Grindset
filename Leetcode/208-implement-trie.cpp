#include<bits/stdc++.h>
using namespace std;

struct Vertex {

    vector<int> next;
    bool exists = false;

    Vertex() {
        next.assign(26, -1);
    }
    
};

class Trie {
private:

    vector<Vertex> T;

public:
    Trie() {
        T.emplace_back();
    }
    
    void insert(string word) {

        int i = 0;
        for(char &c : word) {
            //Vertex current = T[i];
            int index = c - 'a';
            if(T[i].next[index] == -1) {
                T[i].next[index] = T.size();
                T.emplace_back();
            }
            i = T[i].next[index];
        }

        T[i].exists = true;

    }

    int traversal(string &word) {
        int i = 0;
        for(char &c : word) {
            int index = c - 'a';
            if(T[i].next[index] == -1) {
                return -1;
            }
            i = T[i].next[index];
        }
        return i;
    }
    
    bool search(string word) {

        int i = traversal(word);

        if(i == -1) return false;
        return T[i].exists;

    }
    
    bool startsWith(string prefix) {

        int i = traversal(prefix);

        if(i == -1) return false;
        return !T[i].exists;
        
    }
};

int main() {

    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << '\n';
    cout << obj->search("app") << '\n';
    cout << obj->startsWith("app") << '\n';
    obj->insert("app");
    cout << obj->search("app") << '\n';

    return 0;
}