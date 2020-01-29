#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode *children[26];
	bool isEOW;
};

struct TrieNode *getNode() {
	TrieNode *node = new TrieNode;
	node->isEOW = false;
	for(int i=0; i<26; i++) 
		node->children[i] = NULL;
	return node;
}

void insert(TrieNode *root, string key) {
	TrieNode *node = root;
	for(int i=0; i<key.length(); i++) {
		int idx = key[i]-'a';
		if(!node->children[idx])
			node->children[idx] = getNode();
		node = node->children[idx];
	}
	node->isEOW = true;
}

bool serach(TrieNode *root, string key) {
	TrieNode *node = root;
	for(int i=0; i<key.length(); i++) {
		int idx = key[i]-'a';
		if(!node->children[idx])
			return false;
		node = node->children[idx];
	}
	return (node!=NULL && node->isEOW);
}

int main(void) {
	string keys[] = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane" }; 
    int n = sizeof(keys) / sizeof(keys[0]); 
  
    struct TrieNode* root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
}