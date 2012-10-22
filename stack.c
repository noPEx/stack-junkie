#include <stdio.h>

#include <stdlib.h>

typedef struct {
	struct node* next ;
	int value ;

} node ;


/* given a node prints all the nodes
* used for debugging purpose only
* you cannot see the contents of a queue, can you?
*/
/* parameters
	@head :
		head of the linked list
*/
void print_nodes( node* head ){
	node* oldhead = head ;
	while( head ) {
		printf("%d-> ",head->value ) ;
		head = head->next ;

	}
	printf("\n") ;
}

/* given the tail of the queue append a number */
/*
	parameters
		@tail_add_Ptr:
			it is the address of the head, head is itself a address :P
*/
node* push( node* head, int n ) {
	node* new = ( node* )malloc( sizeof( node ) ) ;
	new->value = n ;
	new->next = head ;
	head = new ;
	return head ;

}

node* initialize(  int arr[], int size ) {
	node* current = NULL ;
	int i ;
	for( i = 0 ; i < size ; i++ ) {
		node* new = ( node* )malloc( sizeof( node ) ) ;
		new->value = arr[i] ;
		new->next = current ;
		current = new ;
	}
	return current ;
}

/* pops the first element in the queue LIFO : first appended remove first
* returns the next element
*/
node* pop( node* head ) {
	return head->next ;
}

int main( int argc,char** argv ) {


	int arr[] = {1,2,3,4,5 } ;
	node* head = NULL ;

	head = initialize( arr, 5 ) ;

	printf("nodes in list are :\n");
	print_nodes( head ) ;
	head = push( head,6 ) ;
	printf("nodes after pushing stack are : \n");
	print_nodes( head ) ;
	head = pop( head ) ;
	printf("after dequeuing 1 element queue becomes\n");
	print_nodes( head ) ;



	return 0 ;
}
