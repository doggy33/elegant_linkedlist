#include <stdio.h>
#include <stdlib.h>

struct IntListItem{
	int value;
	struct IntListItem *next;
};

typedef struct IntListItem IntListItem;

struct IntList{
	IntListItem *head;
};

typedef struct IntList IntList;

IntListItem *find_remove(IntList *list, int num);
IntList *create(IntList *list, int *, int);
void remove_cs101(IntList *list, IntListItem *target);
void remove_elegant(IntList *list , IntListItem *target);
void print_list(IntList *list);


void remove_cs101(IntList *list, IntListItem *target){
	IntListItem *current = list->head, *prev = NULL;
	while(current != target){
		prev = current;
		current = current->next;
	}
	if(current){
		prev->next = current ->next;
	}else{
		list->head = current->next;
	}
}

void remove_elegant(IntList *list , IntListItem *target){
	IntListItem **p = &list->head;	
	printf("p is : %p *p is %p\n", p,*p); //p = list address ,*p = head node
	while((*p) != target ){
		p = &(*p)->next;
	}
	*p = target->next;
}

IntList *create(IntList *list, int *arr, int size){
	IntListItem *new, *prev=NULL;
	
	for(int i =0;i<size;i++){
		new = (IntListItem *)malloc(sizeof(IntListItem));
		new->value = arr[i];
		new->next = prev;
		prev = new;
	}
	list->head = prev;
	return list;
}

IntListItem *find_remove(IntList *list, int num){
	IntListItem *current = list->head;
	while(current->value != num ){
			current = current ->next;
	}
	if(current)
		return current;
	return NULL;
}

void print_list(IntList *list){
	IntListItem *current = list->head;
	printf("List element is:\n");
	while(current){
		printf("value: %d ", current->value);
		printf("addr : %p\n", current);
		current = current->next;
		printf("========\n");
	}
	printf("List is empty\n\n");
}


int main(){
		int num;
		int a[] = {5,3,6,8,1};
		int size = sizeof(a)/sizeof(a[0]);
		IntList *list = (IntList *)malloc(sizeof(IntList));
		IntListItem *delItem;

		list = create(list, a, size);
		print_list(list);
		printf("Give remove number\n");
		scanf("%d", &num);
		delItem = find_remove(list, num);
		printf("Remove num %d addr is %p\n", num,delItem);
		remove_elegant(list, delItem);
		print_list(list);

		free(list);
		return 0;
}


