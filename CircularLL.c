#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*last;

struct node* insertAtFirst(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    
    struct node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=temp;
    temp->next = head;
    head =temp;
    return head;
    
}
struct node* insertAtIndex(struct node *head,int data,int index){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i=0;
    if(index==1){
        head = insertAtFirst(head,data);
    }
    else{
        do{
            p = p->next;
            i++;
        }while(i!=index-2 && p!=head);
        if(p==head){
            printf("Wrong index\n");
        }else{
            temp->next = p->next;
            p->next = temp;
            temp->data = data;
        }
        
    }
    return head;
}

struct node* insertAtEnd(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    
    struct node *p=head;
    do{
        p=p->next;
    }while(p->next!=head);
    p->next=temp;
    temp->next = head;
    last = temp;
    return head;
}

//delete first element of linked list 
struct node* deleteFirst(struct node *head){
    if(head==last){
        printf("Linked List is empty..!\n");
    }
    struct node *temp = head;
    printf("Deleted element is %d\n",temp->data);
    head = head->next;
    free(temp);
    return head;
}

//delete last element of linked list 
struct node* deleteLast(struct node *head){
    if(head==last){
        printf("Linked List is empty..!\n");
    }
    struct node *temp =head;
    struct node *prevNode;
    do{
        prevNode = temp;
        temp = temp->next;
    }while(temp->next!=head);
    printf("Deleted element is %d\n",temp->data);
    prevNode->next=head;
    last = prevNode;
    free(temp);
    return head;
    
}

void display(struct node *head){
    struct node *ptr = head;
    printf("[ ");
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=head);
    printf("]");
    printf("\n");
}

int main(){
    
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next = head;
    last = head;
    
    head = insertAtFirst(head,5);
    head = insertAtFirst(head,10);
    head = insertAtFirst(head,100);
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,12);
    head = insertAtEnd(head,15);
    head = insertAtIndex(head,50,3);
    display(head);
    head = deleteFirst(head);
    head = deleteFirst(head);
    display(head);
    head = deleteLast(head);
    display(head);
    return 0;
}