/*
 *		Бинарное дерево (не поисковое)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "steck.h"

/*
 *Узел бинарного дерева
 */
struct node{

	void* value;
	struct node* left;
	struct node* right;
	//struct node* parent; //Указатель на root дерева

};

/*
 *Структура бинарного дерева
 */
struct bin_tree{

	struct node* root;

};

/*
 * Вспомогательная функция для создания эллемента дерева
 */
struct node*  tr_ncreate(void* value, struct node* left, struct node* right){
	
	struct node* apple = malloc(sizeof(struct node));
	apple->value = value;
	apple->left = left;
	apple->right = right;

	return apple;
}	

/*
 *Функция для вставки эллемент  
 *Принимает указатель на дерево, указатель на эллемент, указатель на компоратор(0 - меньше, 1 - больше, 2 - равны)
 */
int insert(struct bin_tree* tr, void* value,int (*comp)(void*, void*)){
		if(tr->root == NULL){
		tr->root = tr_ncreate(value, NULL, NULL);
		return 0;
	}
	int result;
	struct node* peach = tr->root;
	while(1){
		result = comp(value, peach->value);
		if(result == 2){
			return 0;
		}
		if(result == 1){
			if(peach->right != NULL){
				peach = peach->right;
				continue;
			}
			peach->right = tr_ncreate(value, NULL, NULL);
			return 0;
		}
		if(result == 0){
			if(peach->left != NULL){
				peach = peach->left;
				continue;
			}
			peach->left = tr_ncreate(value, NULL, NULL);
			return 0;
		}
	}
	return 3;
}


/*
 * Функция для создания 
*/
void create(struct bin_tree* tr, int (*comp)(void*, void*),int n, ...){

	va_list args;
	va_start(args, n);
	for(int i = 0; i < n; ++i){
		insert(tr, va_arg(args, void*), comp);
	}
	va_end(args);
}

void v_tr(struct bin_tree* tr,void (*v)(void*)){

	if(tr->root == NULL) return;
	struct steck st;
	create_st(&st);
	push(&st, tr->root);

	struct node* apple;
	while(!emp(&st)){
		apple = (struct node*)pop(&st);
		if(apple->right != NULL){
			push(&st, apple);
			push(&st, apple->right);
		}else{
			v(apple->value);
			if(apple->left != NULL)
				push(&st, apple->left);

		}
	}


}


int del(){} //удаление по значению

//написать поисковое дерево 
//написать стек для обхода в преордер
//обход в ширину и глубину
//проекция с помощью пост ордер
//void (){}

/*
 *Освобождение памяти дерева
 */
int free_tree(){}//с помощью инордер 








