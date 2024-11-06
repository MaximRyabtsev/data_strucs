#include <stdio.h>
#include <stdlib.h>
struct node{
	
	void* value;
	struct node* next;

};

struct steck{

	struct node* top;

};

/*
 * При создании top нужно заNULLить
 */
void create_st(struct steck* st){
	st->top = NULL;
}


/*
 * Добавление элемента в стек
 * Значение передовать как указатель (например &int)
 */
void push(struct steck* st, void* value){

	struct node* apple = malloc(sizeof(struct node));
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
	struct node* peach = st->top;
	void* value = st->top->value;
	st->top = st->top->next;
	free(peach);
	return value;

}
