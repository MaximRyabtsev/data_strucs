#include <stdio.h>
#include <stdlib.h>
struct node_st{

	
	void* value;
	struct node_st* next;

};

struct steck{

	struct node_st* top;

};

/*
 * При создании top нужно заNULLить
 */
void create_st(struct steck* st){
	st->top = NULL;
}

/*
 * Проверка на пустой стек
 */
int emp(struct steck* st){

	if(st->top == NULL)
		return 1;
	return 0;

}

/*
 * Добавление элемента в стек
 * Значение передовать как указатель (например &int)
 */
void push(struct steck* st, void* value){

	struct node_st* apple = malloc(sizeof(struct node_st));
	apple->value = value;
	apple->next = st->top;
	st->top = apple;

}


/*
 *Возвращение верхнего эллемента стека в виде указателя на него 
 */
void* pop(struct steck* st){
	
	if(st->top == NULL){
		return NULL;
	}
	struct node_st* peach = st->top;
	void* value = st->top->value;
	st->top = st->top->next;
	free(peach);
	return value;

}
