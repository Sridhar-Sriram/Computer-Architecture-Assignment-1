#include<stdio.h>
#include<stdlib.h>



typedef struct _Node{
    int key_index;
    float number;
    struct _Node * next;
}Node;

Node* hashtable[10000] ;

int hashkey(int);
void search(int, int);
Node* createNode(int, int);
void insert(Node*);


int main(int argc, char**argv){
    int i;
    for(i =0; i<10000; i++){
        Node * index = (Node*)malloc(sizeof(Node));
        index->key_index = i;
        index->number=0.5;
        index->next = NULL;
        hashtable[i] = index;
        
    }
    
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
    
    
    while(fscanf(fp,"%c %d \n", &ch, &num)!=EOF){
        
        Node* new_node = (Node*)malloc(sizeof(Node));
        int hashcode;
        if(num<0){
            int temp = abs(num);
            
            hashcode = 10000 -temp;
        }else{
            hashcode = hashkey(num);
        }
        
        new_node = createNode(hashcode, (float)num);
        
        if(ch == 'i'){
            insert(new_node);
            
        }else if(ch== 's'){
            search(hashcode, (float)num);
            
        }else{
            printf("error \n");
        }
    }
    
    return 0;
    
}

void search(int hashcode, int number){
    Node*ptr = (Node*) malloc(sizeof(Node));
    ptr = hashtable[hashcode];

    while(ptr!=NULL){
        
        if(ptr->number == number){
            printf("present\n");
            return;
        }else if(ptr->number > number){
            printf("absent\n");
            return;
        }else{
            ptr = ptr->next;
        }
    }
    printf("absent\n");
    return;
    
    
}

int hashkey(int num){
    int hashed = abs((num)%10000);
    
    return hashed;
}

void insert(Node* given_node){
    int given_key = given_node->key_index;
    
    Node* head = (Node*) malloc(sizeof(Node));
    head = (Node *)hashtable[given_key];
    Node * ptr = (Node*)malloc(sizeof(Node));
    ptr = head;
    Node* prev = (Node*) malloc(sizeof(Node));
    prev= NULL;
    
    if(head->number ==0.5){ //no chaining has occurred
        hashtable[given_key]= given_node;
        printf("inserted\n");
        
        return;
    }
    else{
        while(ptr!=NULL){
            if(ptr->number== given_node->number){
                printf("duplicate\n");
                return;
            }else if(ptr->number < given_node->number){
                prev = ptr;
                ptr = ptr->next;
            }else{
                if(prev == NULL){
                    given_node->next = head;
                    head = given_node;
                }
                    given_node->next = ptr;
                    prev->next = given_node;
                    printf("inserted\n");
                    return;
            }
        }
        if(ptr == NULL){//reached end of list;
            prev->next = given_node;
            printf("inserted\n");
            return;
        }

    }
}
    


Node* createNode(int code, int number){
    Node* created_Node = (Node*)malloc(sizeof(Node));
    created_Node->number = number;
    created_Node->key_index = code;
    created_Node->next = NULL;
    return created_Node;
}
