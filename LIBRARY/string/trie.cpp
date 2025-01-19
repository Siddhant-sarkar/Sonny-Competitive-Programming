#include <bits/stdc++.h>
using namespace std;

// defines
using ll = long long;
using vi = std::vector<ll>;
// macros
#define nl "\n"
#define sz(a) (ll) a.size();
#define all(a) begin(a), end(a)
#define FOR(i, a, b) for (int i = a; i <= (int)b; i++)
#define ROF(i, a, b) for (int i = a; i >= (int)b; i--)

// " Is man one of God’s blunders or is God one of man’s blunder?? "

struct node {
  node* child[26];
  int prefix = 0, leaf = 0;
  vector<string> wend;
  node() {
    for (int i = 0; i < 26; i++) {
      prefix = 0;
      child[i] = NULL;
    }
  }
};

struct Trie {
  node* t;
  Trie() { t = new node(); }
  void insert(string s) {
    node* curr = t;
    for (auto c : s) {
      curr->prefix++;
      int x = c - 'a';
      if (curr->child[x] == NULL) {
        curr->child[x] = new node();
      }
      curr = curr->child[x];
    }
    curr->wend.push_back(s);
    curr->leaf = 1;
  }
  void remove(string& s) {
    node* curr = t;
    for (auto c : s) {
      curr->prefix--;
      if (curr->child[c - 'a'] == NULL) return;
      curr = curr->child[c - 'a'];
    }
    curr->wend.pop_back();
  }
  bool search(string& s) {
    node* curr = t;
    for (auto c : s) {
      if (curr->child[c - 'a'] == NULL) return 0;
      curr = curr->child[c - 'a'];
    }
    return 1;
  }
};
int main() {
  Trie* t = new Trie();
  t->insert("siddhant");
  t->insert("sid");
  string s = "sidd";
  cout << t->search(s) << endl;
}