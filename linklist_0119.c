#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
};

typedef struct node Node;




Node* CreateList(int*a, int size){
	
	if(size > 0){
		Node* prev = NULL;
		Node* head;
		for(int i = 0;i<size; i++){
			Node* current = (Node*)malloc(sizeof(Node));
			current ->data = a[i];
			current ->next = NULL;

			if(i == 0){
				head = current;

			}else{
				prev->next = current;
			}
			prev = current;			
		}

		return head;
	}
	return NULL;
}

void printList(Node* head){
	Node* current = head;
	while(current){
		printf("%d\t", current -> data);
		current = current ->next; 
	}
}


int main(){
	int arr[] = {5,8,2,3,7};
	int size = sizeof(arr)/ sizeof(arr[0]);
	Node* head = CreateList(arr, size);
	printList(head);
	free(head);
	
	return 0;
}
