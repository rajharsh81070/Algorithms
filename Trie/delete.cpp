#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode *children[26];
	bool isEOW;
};

TrieNode *getNode() {
	TrieNode *root = new TrieNode;
	root->isEOW = false;
	for(int i=0; i<26; i++) 
		root->children[i] = NULL;
	return root;
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
 
bool search(TrieNode *root, string key) {
	TrieNode *node = root;
	for(int i=0; i<key.size(); i++) {
		int idx = key[i]-'a';
		if(!node->children[idx])
			return false;
		node = node->children[idx];
	}
	return (node!=NULL && node->isEOW);
}

bool isEmpty(TrieNode *root) {
	for(int i=0; i<26; i++) {
		if(root->children[i])
			return false;
	}
	return true;
}

TrieNode *remove(TrieNode *root, string key, int depth=0) {
	if(!root)
		return NULL;
	if(depth==key.length()) {
		if(root->isEOW)
			root->isEOW = false;
		if(isEmpty(root)) {
			delete(root);
			root = NULL;
		}
		return root;
	}

	int idx = key[depth]-'a';
	root->children[idx] = remove(root->children[idx], key, depth+1);
	if(isEmpty(root) && root->isEOW==false) {
		delete(root);
		root = NULL;
	}

	return root;
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
  
    remove(root, "heroplane"); 
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
}