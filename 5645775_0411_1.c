#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_STACK_SIZE 5          //최대 크기 설정

typedef int element;

typedef struct Stacktype {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* sptr) {
	sptr->top = -1;
}


int is_empty(StackType* sptr) {         //비었는지 확인
	return (sptr->top == -1);
}


int is_full(StackType* sptr) {         //가득찼는지 확인
	return (sptr->top == MAX_STACK_SIZE - 1);
}

void push(StackType* sptr, element item) {
	if (is_full(sptr)) {
		fprintf(stderr, "Push: %d\n", item); // 푸시된 숫자 출력
		fprintf(stderr, "Stack Overflow\n");
		return;
	}
	else {
		sptr->data[++(sptr->top)] = item;
		printf("Push: %d\n", item); // 푸시된 숫자 출력
		printf("Stack elements: ");
		for (int i = 0; i <= sptr->top; i++) {
			printf("%d ", sptr->data[i]);
		}
		printf("\n");
	}
}

element pop(StackType* sptr) {
	if (is_empty(sptr)) {
		fprintf(stderr, "Stack Underflow\n"); // 스택이 비었을 때 Stack Underflow 출력
		return -1;
	}
	else {
		element temp = sptr->data[(sptr->top)--];
		printf("Pop: %d\n", temp);
		if (is_empty(sptr)) {
			printf("Stack Underflow\n"); // 스택이 비었을 때 Stack Underflow 출력
		}
		else {
			printf("Stack elements: ");
			for (int i = 0; i <= sptr->top; i++) {
				printf("%d ", sptr->data[i]);
			}
			printf("\n");
		}
		return temp;
	}
}


int main() {
	StackType s;
	int rand_num;

	srand(time(NULL));

	init(&s);

	for (int i = 0; i < 30; i++) {
		rand_num = rand() % 100 + 1;
		printf("\n");
		printf("Current rand_num: %d | %s\n", rand_num, (rand_num % 2 == 0) ? "Even" : "Odd");
		if ((rand_num % 2) == 0) {
			push(&s, rand_num);
		}
		else {
			pop(&s);
		}
	}

	return 0;
}
/*후입선출(가장 최근에 들어온 데이터가 가장 먼저 나가는 것)이 스택의 특징인데
  디버깅 결과 이러한 방식대로 push와 pop이 작동되고 있다.

  스택에서 요소를 제거하면서 꺼낼 요소가 있는지 확인할 때, 꺼낸 후 비거나 원래부터 요소가 없으면 stack empty가 발생하며
  디버깅 결과 "Stack Underflow"가 출력된다.

  스택에 새 요소를 추가하려고 할 때, 스택이 이미 최대 크기로 채워져 있는 경우 stack full이 발생한다.
  최대 크기를 5로 설정했기 때문에 요소가 5개보다 많아지면 "Stack Overflow"가 출력된다.
*/