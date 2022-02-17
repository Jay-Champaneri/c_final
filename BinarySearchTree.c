#include<stdio.h>
#include<stdlib.h>
struct node {
   int data; 
	
   struct node *lptr;
   struct node *rptr;
};

struct node *BST(struct node *t,int key){
struct node *new= (struct node *)malloc(sizeof(struct node));
	if(t == NULL){
		new->data=key;
		new->lptr = new->rptr = NULL;
		t=new;
		return t;
	}
	else if (key < t->data){
        	t->lptr = BST(t->lptr, key);
    	}
    	else if (key > t->data){
        	t->rptr = BST(t->rptr, key);
	}
	return t;
}
struct node *search(struct node *t, int key)
{
    if (t == NULL || t->data == key)
       return t;
    
    if (t->data < key)
       return search(t->rptr, key);
 
    return search(t->lptr, key);
}
struct node *preTree(struct node *t){
	if(t == NULL){
		printf("empty");
	}
	
	printf("%d\t",t->data);
	
	if(t->lptr != NULL){
		preTree(t->lptr);
	}
	
	if(t->rptr != NULL){
		preTree(t->rptr);
	}
}

struct node *inTree(struct node *t){
char temp='\0';
	if(t == NULL){
		printf("empty");
	}
	
	if(t->lptr != NULL){
		inTree(t->lptr);
	}
	
	printf("%d\t",t->data);
		
	if(t->rptr != NULL){
		inTree(t->rptr);
	}
}
void main(){

	int a[10]={50,25,75,22,40,60,80,90,15,30};
	struct node *temp = NULL ;
	for(int i=0;i<10;i++){
		temp=BST(temp,a[i]);
	}	
	printf("inOrder= ");inTree(temp);
	printf("\n");
	
}
