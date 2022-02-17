#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int info;
    struct Node *link;
};

struct Node* insBeg(int data,struct Node *head){
    struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    
    if(new == NULL){
        printf("Overflow...!\n");
        return head;
    }
    else{
        new->info=data;
        new->link=head;
        return new;
    }
}

struct Node* insOrd(int data,struct Node *head){
    
    struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    struct Node *save=head;
    new -> info = data;
    if(head == NULL){
        new -> link = NULL;
        return new;
    }else{
        
        if(new->info<=head->info){
            new -> link = head;
            return new;
        }
        else{
            while(save->link != NULL && new->info >=(save->link)->info){
                save = save -> link;
            }
            new -> link = save -> link;
            new -> info = data;
            save -> link = new;
            return head;
        }
        }
}



struct Node* insEnd(int data,struct Node *head){
    struct Node *save=head;
    struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    while(save->link!=NULL){
        save = save->link;
    }
    if(new == NULL){
        printf("Overflow...!\n");
        return head;
    }else{
        
        new->info=data;
        new->link=NULL;
        save->link =new;
        return head;
    }
}
struct Node* copy(struct Node *head){
    if(head==NULL){
        return NULL;
    }else{
        struct Node *new;
        new = (struct Node*)malloc(sizeof(struct Node));
        new->info = head->info;
        new->link = copy(head->link);
        return new;
    }
}

struct Node* del(int data,struct Node *head){
    struct Node *save=head;
    struct Node *pred;
    save = head;
    if(head == NULL){
        printf("Underflow\n");
        return head;
    }
    
    if (save != NULL && save->info == data) {
        head = save->link;
        free(save); 
        return head;
    }
    while(save->info!=data && save->link!=NULL)
    {
        pred = save;
        save = save->link;
        
    }
    if(save->info!=data){
        printf("data not found");
        return head;
    }else{
        pred->link = (save->link)->link;
        free(save);
        return head;
    }
    
}

void dis(struct Node *head){
    struct Node *save=head;
    printf("[");
    while(save!=NULL){
        printf("%d ",save->info);
        save = save->link;
    }
    printf("]");
    printf("\n");
}

int count(struct Node *head){
    struct Node *save=head;
    int c=0;
    while(save->link!=NULL){
        c++;
        save = save->link;
    }
    return c;
}
int main()
{
    int data,sign;
    struct Node *head;
    head = (struct Node*)malloc(sizeof(struct Node));
    
    while(sign!=7){
        printf("----------------------------------------------\n");
        printf("\n1 for Insert Element from begining\n2 for Insert Elements in order\n");
        printf("3 for display all Elements\n4 for display count of Elements\n5 for delete Element\n6 for Duplicate a Linked list\n7.for end\n");
        scanf("%d",&sign);
    switch(sign){
        case 1:
        printf("Enter Element: \n");
        scanf("%d",&data);
        head = insBeg(data,head);
        break;
        
        case 2:
        printf("Enter Element: \n");
        scanf("%d",&data);
        head = insOrd(data,head);
        break;
        
        case 3:
        dis(head);
        break;
        
        case 4:
        printf("Number of Elements in Linked List: %d\n",count(head)+1);
        break;
        
        case 5:
        printf("Enter Element who you want to delete: \n");
        scanf("%d",&data);
        head = del(data,head);
        break;
        
        case 6:
        printf("New Duplicate Linked list is:\n");
        struct Node *dup = copy(head);
        dis(dup);
        break;
        
        case 8:
        printf("Enter Element: \n");
        scanf("%d",&data);
        head = insEnd(data,head);
        break;
        
        
        default:
        printf("invalid\n");
        break;
    }
    }
    return 0;
}
