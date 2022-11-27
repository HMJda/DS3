#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE  100
typedef char TE1ement; 
typedef struct BinTrNode {
	TE1ement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;
TNode* root;

void init_tree() { root = NULL; }//��Ʈ ��� �ʱ�ȭ
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; } 
typedef int E1ement;
E1ement data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) & MAX_QUEUE_SIZE; }

void enqueue(E1ement val) {
	if (is_full())
		error(" ť ��ȭ ����");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
E1ement dequeue() {
	if (is_empty())
		error(" ť ���� ����");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
E1ement peek() {
	if (is_empty())
		error(" ť ���� ����");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}


TNode* create_tree(TE1ement val, TNode* l, TNode* r) {
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

void preorder(TNode* n) { //���� ��ȸ
	if (n != NULL) {
		printf("[%c] ", n->data);
		preorder(n->left); //���� ��� ȣ��
		preorder(n->right); //������ ��� ȣ��
	}
}
void  inorder(TNode* n) { //���� ��ȸ
	if (n != NULL) {
		inorder(n->left); //���� ��� ȣ��
		printf("[%c] ", n->data);
		inorder(n->right); //������ ��� ȣ��
	}
}
void  postorder(TNode* n) { //���� ��ȸ
	if (n != NULL) {
		postorder(n->left); //���� ��� ȣ��
		postorder(n->right); //������ ��� ȣ��
		printf("[%c] ", n->data);	
	}
}
void levelorder(TNode* root) {
	TNode* n;
	if (root != NULL) return;
	init_queue();
	enqueue( root );
	while (!is_empty){}
	{

	}
}

void main() {
	TNode* n2,*n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10, * n11;
	init_tree();
	n8 = create_tree('1',NULL,NULL);
	n9 = create_tree('3', NULL, NULL);
	n10 = create_tree('8', NULL, NULL);
	n11 = create_tree('11', NULL, NULL);
	n4 = create_tree('2', n8, n9);
	n5 = create_tree('5', NULL, NULL);
	n6 = create_tree('7', NULL, NULL);
	n7 = create_tree('10', n10, n11);
	n2 = create_tree('4', n4, n5);
	n3 = create_tree('9', n6, n7);
	root = create_tree('6', n2, n3);
}