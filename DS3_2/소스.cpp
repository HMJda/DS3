#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_NODE 200

void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}

typedef int HNode;
#define key(n)     (n)

HNode heap[MAX_HEAP_NODE];
int heap_size;

#define Parent(i) (heap[i/2])
#define Left(i) (heap[i*2])
#define Right(i) (heap[i*2+1])

void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap_size == MAX_HEAP_NODE - 1); }
HNode find_heap() { return heap[1]; }

void insert_heap(HNode n) { //힙 삽입
	int i;
	if (is_full_heap() ) return;
	i = ++(heap_size);
	while (i!=1&&key(n)>key(Parent(i)))
	{
		heap[i] = Parent(i);
		i /= 2;
	}
	heap[i] = n;
}
HNode delete_heap() {//힙 삭제 
	HNode hroot, last;
	int parent = 1, child = 2;

	if (is_empty_heap())
		error("힙 트리 공백 에러");
	hroot = heap[1];
	last = heap[heap_size--];
	while (child <= heap_size) {
		if (child < heap_size && key(Left(parent)) < key(Right(parent)))
			child++;
		if (key(last) >= key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return hroot;
}

void print_heap() {
	int i, level;
	for (i=1,level=1;i<=heap_size ; i++)
	{
		if (i == level) {
			printf("\n");
			level *= 2;
		}
		printf("%2d ", key(heap[i]));
	}
	printf("\n");
}
void main() {
	int data[100];
	init_heap();
	insert_heap(10); insert_heap(40); insert_heap(30); insert_heap(5); insert_heap(12); insert_heap(6);
	insert_heap(15); insert_heap(9); insert_heap(60); //예제 값 입력 부분 
	print_heap();
	delete_heap();	//60 제거 
	print_heap(); 
	delete_heap(); //40 제거
	print_heap();  
	delete_heap();//30 제거
	print_heap(); 
	delete_heap(); //15 제거
	print_heap(); 
	delete_heap(); //12 제거
	print_heap();  
	delete_heap(); //10 제거 
	print_heap(); 
	delete_heap(); //9 제거
	print_heap(); 
	delete_heap(); //6 제거
	print_heap(); 
	delete_heap();  //5 제거
	print_heap();  
}
