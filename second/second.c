#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>




typedef struct _Node{
    int number;
    struct _Node * next;
}Node;


Node * head_of_list = NULL;

void insert(Node*);
void delete(int);
void printList(Node*);
Node* createNode(int);

int main(int argc, char**argv){
    char*filename = argv[1];
    FILE*fp;
    char ch;
    int num;
    fp = fopen(filename, "r");
    
    if(fp == NULL){
        printf("error \n");
        exit(0);
        return 1;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    while(fscanf(fp,"%c %d \n", &ch, &num)!=EOF){
        //printf("%c %d \n", ch, num)
        new_node = createNode(num);
        //printf("This is the Node's number: %d \n", new_node->number);
        if(ch == 'i'){
            //printf("About to be inserted \n");
            insert(new_node);
        }else if(ch== 'd'){
            //printf("About to be deleted \n");
            delete(num);
            
        }else{
            printf("error \n");
            exit(0);
            return 1;
        }
    }
    printList(head_of_list);
    return 0;
}

void insert(Node* passed_in_Node){
    Node* ptr = (Node*) malloc(sizeof(Node));
    ptr = head_of_list;
    Node* prev = (Node*) malloc(sizeof(Node));
    prev= NULL;
    
    
    if(head_of_list == NULL){
        head_of_list = passed_in_Node;
        //printf("This is the head of the list: %d \n", head_of_list -> number);
        return;
    }
    //printf("This is the head of the list: %d \n", head_of_list -> number);
    
    while(ptr!= NULL){
        if(ptr->number <passed_in_Node->number){
            prev = ptr;
            ptr= ptr->next;
            
        }else if(ptr->number == passed_in_Node->number){
            return;
        }else{
            if(prev==NULL){//head_of_list
                passed_in_Node->next = head_of_list;
                head_of_list = passed_in_Node;
                return;
            }else{
                passed_in_Node->next = ptr;
                prev->next = passed_in_Node;
                return;
            }
        }
    }
    if(ptr == NULL){//reached end of list;
        prev->next = passed_in_Node;
        return;
    }
    return;
    
}
void delete(int target){
    //printf("WE ARE TRYING TO DELETE THIS NUMBER: %d", target);
    if(head_of_list == NULL){
        return;
    }
    
    Node*ptr = (Node*) malloc(sizeof(Node));
    ptr = head_of_list;
    Node*prev = (Node*) malloc(sizeof(Node));
    prev= NULL;
    
    
    while(ptr!=NULL){
        if(ptr->number == target){
            if(prev==NULL){ //head of the list
                if(ptr->next == NULL){//only element in list
                    head_of_list = NULL;
                    return;
                }else{
                    head_of_list = ptr->next;
                    ptr =NULL;
                    return;
                }
            }else{//anywhere else in LL
                if(ptr->next == NULL){//last element in list
                    prev->next = NULL;
                    return;
                }else{
                    prev->next = ptr->next;
                    ptr = NULL;
                    //free(ptr);
                }
            }
        }else if(ptr->number > target){
            return;
        }
        else{
            if(ptr->next == NULL){//reached the end of the list
                return;
            }
            
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return;
    
}

Node* createNode(int passed_in_number){
    Node* created_Node = (Node*)malloc(sizeof(Node));
    created_Node->number = passed_in_number;
    created_Node->next = NULL;
    return created_Node;
}

void printList(Node* start){
    //printf("This is the head of the list: %d \n", start->number);
    if(start == NULL){
        printf("\n");
    }
    while(start!=NULL){
        //printf("I have entered the while loop \n");
        printf("%d\t", start->number);
        start = start->next;
    }
    printf("\n");
}
