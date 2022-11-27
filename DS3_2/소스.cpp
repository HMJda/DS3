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
	if (is_full_heap() ) return; //포화상태 유무 판단
	i = ++(heap_size);  //힙삽입후 heap_size+1 해줌
	while (i!=1&&key(n)>key(Parent(i)))  //i가 루트 노드가 아니고 n의 key가 i의 부모보다 크면 루프
	{
		heap[i] = Parent(i); //i의 부모노드를 i위치로 내림
		i /= 2; //한 레벨 위로 이동 
	}
	heap[i] = n;//최종위치 데이터 복사
}
HNode delete_heap() {//힙 삭제 
	HNode hroot, last;
	int parent = 1, child = 2; //초기화

	if (is_empty_heap()) //공백상태 유무 판단
		error("힙 트리 공백 에러");
	hroot = heap[1]; 
	last = heap[heap_size--]; //힙의 마지막 요소를 리스트에 복사
	while (child <= heap_size) { //힙트리를 벗어나지 않는 동안
		if (child < heap_size && key(Left(parent)) < key(Right(parent))) //현재노드중 더 큰 자식을 찾고 child를 증가
			child++;
		if (key(last) >= key(heap[child]))  //마지막 노드가 더 큰 자식 보다 크면 이동 완료,루프 탈출
			break;
		heap[parent] = heap[child]; //아니면 한단계 아래로 이동
		parent = child;
		child *= 2;
	}
	heap[parent] = last; //마지막 노드를 최종위치에 저장
	return hroot; //반환
}

void print_heap() { //힙 출력 부분 
	int i,j, level;
	
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
