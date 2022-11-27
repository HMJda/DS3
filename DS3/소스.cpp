#include <stdio.h>
#include <stdlib.h>

typedef char TE1ement; 
typedef struct BinTrNode {
	TE1ement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;
TNode* root;

void init_tree() { root = NULL; }
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; }

TNode* create_tree(TE1ement val, TNode* l, TNode* r) {
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}



void main() {
	TNode* b, * c, * d, * e, * f;
	init_tree();
	scanf_s()
	d = create_tree();
}