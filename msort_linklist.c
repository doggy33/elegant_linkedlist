#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
	int val;
	struct node_t *next;
}node_t;


static void print_list(node_t*);

static node_t *mergeTwoLists(node_t *left , node_t *right){
	if(!left && !right)
		return NULL;
	node_t head,*prev = &head;
	
	while(left && right){
		if(left->val >= right->val){
			prev->next = right;
			right = right ->next;
		}else{
			prev->next = left;
			left = left->next;
		}
		prev = prev ->next;
	}
	if(left){
		prev ->next = left;
	}else{
		prev->next = right;
	}
	return head.next;
}

static node_t *mergesort_list(node_t *head){
	if(!head || !head ->next)
		return head;
	
	node_t *slow = head;
	if(head->next->next){
		for(node_t *fast = head; fast && fast->next; fast = fast ->next->next)
			slow = slow ->next;
	}
	node_t *mid = slow ->next;
	slow->next = NULL;
	node_t *left  = mergesort_list(head);
	node_t *right = mergesort_list(mid);
	print_list(left);
	print_list(right);
	return mergeTwoLists(left, right);	
}

static void print_list(node_t *head){
	while(head){
		printf("%d\t", head->val);
		head = head ->next;
	}
	printf("\n");
}

int main(){
	int a[] = {5,1,3,6,7,9,2};
	//int a[] = {2,9};
	int a_size = sizeof(a) / sizeof(a[0]);
	node_t *prev = NULL , *node;

	/*  append */
	for(int i =0;i<a_size;i++){
		node = (node_t *)malloc(sizeof(node_t));
		node->val = a[i];
		node->next = prev;
		prev = node;
	}
	/* print */
	puts("\nOriginal List\n");
	print_list(node);
	/* sort */
	node = mergesort_list(node);
	//node = mergeTwoLists(node, NULL);
	/* print */
	puts("\nSorted List\n");
	print_list(node);	
	free(node);
	return 0;
}
