/*
 *		ОДНОСВЯЗНЫЙ СПИСОК
 */




#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/*
 *node - эллемент односвязного списка
 */
struct node{
	
	int value;
	struct node* next;

};

/*
 *spis - список 
 */

struct spis{

	struct node* head;

};

/*
 *Вспомогательная функция для создания элемента списка 
 */
struct node* ncreate(int value, struct node* next){
	
	struct node* n = malloc(sizeof(struct node));
	n->next = next;
	n->value = value;
	return n;

}


/*
 *Функция для создания списка принимающая на вход n значений, которые быдут находится в списке
 */
struct spis* screate(int n,  ...){
	if(n <= 0) abort();
	va_list args;
	va_start(args, n);
	struct spis* h = malloc(sizeof(struct spis));
	h->head = ncreate(va_arg(args, int), NULL);
	struct node* last = h->head ,*next;
	for(int i = 1; i < n; ++i){
		next = ncreate(va_arg(args, int), NULL);
		last->next = next;
		last = last->next;
	}
	va_end(args);
	return h;
}


/*
 *Вставка в конец
 */
void push(struct spis* h, int value){
	if(h->head == NULL){
		h->head = ncreate(value, NULL);
		return;
	}
	struct node* last = h->head;
	while(last->next != NULL)
		last = last->next;
	last->next = ncreate(value, NULL);

}

/*
 * Удаление последнего эллемента 
 *
 * 1 - успешно 
 *
 * 0 - удаление не произошло
 */

int pop(struct spis* h){
	if(h->head == NULL) return 0; 
	if(h->head->next == NULL){
		free(h->head);
		h->head = NULL;
		return 1;
	}
	struct node* last = h->head;
	while(last->next->next != NULL)
		last = last->next;
	free(last->next);
	last->next = NULL;
	return 1;
}

/*
 *Вспомогательная функция для освобождения памяти
 */
void del_h(struct node* l){

	if(l == NULL) return;
	del_h(l->next);
	free(l);

}

/*
 *Функция для освобождения памяти списка (удаляет все эллементы списка и сам список)
 */
void del_spis(struct spis* h){
	
	del_h(h->head);
	free(h);

}

/*
 *Функция для вставки значения в конкретную позицию(СЧИТАТЬ С НУЛЯ)
 *1 - успешно 
 *0 - не корректный запрос (нет эллемента или что то еще)
*/
int insert(struct spis* h, int pos, int value){
	
	if(h->head == NULL){
		if(pos == 0){
			
			h->head = ncreate(value, NULL);
			return 1;

		}
		return 0;	
	}
	if(pos == 0){
	
		struct node* apple = ncreate(value, h->head);
		h->head = apple;
		return 1;

	}
	struct node* peach = h->head;
	for(int j = 0;peach != NULL;++j, peach = peach->next){
		
		if((j+1) == pos){
		
			struct node* apple = ncreate(value, peach->next);
			peach->next = apple;
			return 1;

		}
	}
	return 0;
}

/*
 *Функция удаления эллемента по позиции(СЧИТАТЬ С НУЛЯ)
 *1 - успешно 
 *0 - не корректный запрос (нет эллемента или что то еще)
*/
int del(struct spis* h, int pos){
	
	if(h->head == NULL){
		return 0;	
	}
	if(pos == 0){
		
		struct node* n = h->head;
		h->head = n->next;
		free(n);
		return 1;

	}
	struct node* peach = h->head;
	for(int j = 0;peach != NULL;++j, peach = peach->next){
		
		if((j+1) == pos){
			if(peach->next == NULL) return 0;
			struct node* n = peach->next;
			peach->next = n->next;
			free(n);		
			return 1;

		}
	}
	return 0;
}
/*
 * Отображение односвязного списка
 */
void v(struct spis* h){
	struct node* l = h->head;
	while(l != NULL){
		printf("%d", l->value);
		l = l->next;
	}
}
