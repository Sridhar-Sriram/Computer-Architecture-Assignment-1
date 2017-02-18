#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int number;
    int height;
    struct _Node*right;
    struct _Node*left;
}TreeNode;

TreeNode * root = NULL;


void insert(TreeNode*);
void search(int);
TreeNode*createNode(int);

int main(int argc, char** argv){
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
        if(ch == 'i'){
            TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
            new_node = createNode(num);
            insert(new_node);
        }else if(ch== 's'){
            //printf("About to be deleted \n");
            search(num);
            
        }else{
            printf("error \n");
        }
    }
    return 0;
}

void insert(TreeNode* given_node){
    if(root == NULL){
        root = given_node;
        given_node->height = 1;
        printf("inserted %d \n", given_node->height);
        return;
    }
    int height_counter = 1;
    
    TreeNode*ptr = (TreeNode*)malloc(sizeof(TreeNode));
    ptr = root;
    TreeNode*parent = (TreeNode*)malloc(sizeof(TreeNode));
    parent = NULL;
    
    while(ptr!= NULL){
        if(ptr->number > given_node->number){
            parent = ptr;
            ptr = ptr->left;
        }else if(ptr->number == given_node->number){
            printf("duplicate \n");
            return;
        }else{
            parent = ptr;
            ptr = ptr->right;
        }
        height_counter++;
    }
    if(ptr == NULL){
        given_node->height = height_counter;
        if(parent->number > given_node->number){
            parent->left = given_node;
        }else{
            parent->right = given_node;
        }
        printf("inserted %d \n", given_node->height);
    }
    return;
    
}

void search(int target){
    if(root == NULL){
        printf("absent \n");
    }
    
    TreeNode*ptr = (TreeNode*)malloc(sizeof(TreeNode));
    ptr = root;
    
    while(ptr!=NULL){
        if(ptr->number == target){
            printf("present %d \n", ptr->height);
            return;
        }else if(ptr->number >target){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
    
    if(ptr ==  NULL){
        printf("absent \n");
        return;
    }
}

TreeNode* createNode(int number){
    TreeNode*created_node= (TreeNode*)malloc(sizeof(TreeNode));
    created_node->number = number;
    created_node->height = 0;
    created_node->right = NULL;
    created_node->left = NULL;
    
    return created_node;
}

