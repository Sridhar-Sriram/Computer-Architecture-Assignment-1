#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int number;
    int height;
    struct _Node*right;
    struct _Node*left;
    struct _Node*parent;
}TreeNode;

TreeNode * root = NULL;


void insert(TreeNode*);
void search(int);
TreeNode*createNode(int);
void delete(TreeNode*, int);
TreeNode* dsearch(int);
void updateHeights(TreeNode*,int);
TreeNode* findminNode(TreeNode*);



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
            
        }else if(ch=='d'){
            TreeNode*delete_this = dsearch(num);
            if(delete_this == NULL){
                printf("fail \n");
            }else{
                delete(delete_this, num);
                updateHeights(root,1);
            }
            
        }
        else{
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
        given_node->parent = parent;
        printf("inserted %d \n", given_node->height);
    }
    return;
    
}

void delete(TreeNode* target, int targetNum){
    
    if(target->right == NULL && target -> left == NULL){
        if(target!= root){
            if(target == target->parent->right){
                target->parent->right = NULL;
                free(target);
                printf("success \n");
                updateHeights(root,1);
            }else{
                target->parent->left = NULL;
                free(target);
                printf("success \n");
                updateHeights(root,1);
            }
            return;

        }else{
            root = NULL;
            printf("success \n");
            updateHeights(root,1);
            return;
        }
    }
    else if(target->left ==NULL & target->right !=NULL){
        if(target!=root){
            if(target->parent->left == target){
                target->parent->left = target->right;
                free(target);
                printf("success \n");
                updateHeights(root,1);
                return;
            }else{
                target->parent->right = target->right;
                printf("success \n");
                free(target);
                updateHeights(root,1);
                return;
            }
        }else{
            root = target->right;
            printf("success \n");
            updateHeights(root, 1);
            return;
        }
    } else if(target->left != NULL && target->right == NULL){
        if(target!=root){
            if(target->parent->left == target){
                target->parent->left = target->left;
                free(target);
                printf("success \n");
                updateHeights(root,1);
                return;
            }else{
                target->parent->right = target->left;
                free(target);
                printf("success \n");
                updateHeights(root,1);
                return;
            }
        }else{
            root = target->left;
            printf("success \n");
            updateHeights(root,1);
            return;
        }
    }else{
       
        TreeNode*temp = findminNode(target->right);
        int tempnum = temp->number;
        temp->number = target->number;
        target->number = tempnum;
        delete(temp, temp->number);
        
        updateHeights(root,1);
        
    }
    return;
    
}
TreeNode* findminNode(TreeNode* origin){
    TreeNode*ptr = origin;
    while(ptr->left!=NULL){
        ptr = ptr->left;
    }
    return ptr;

}

void updateHeights(TreeNode*ptr, int height){
    if(ptr == NULL){
        return;
    }else if(ptr == root){
        ptr->height = 1;
        updateHeights(ptr->left, height);
        updateHeights(ptr->right, height);
        return;
    }
    else{
        height++;
        ptr->height = height;
        updateHeights(ptr->left, height);
        updateHeights(ptr->right, height);
        return;
    }
    return;
}

TreeNode* dsearch(int target){
    if(root == NULL){
        return NULL;
    }
    
    TreeNode*ptr = (TreeNode*)malloc(sizeof(TreeNode));
    ptr = root;
    
    
    while(ptr!=NULL){
        if(ptr->number == target){
            return ptr;
        }else if(ptr->number >target){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
    
    if(ptr ==  NULL){
        return NULL;
    }
    return NULL;
}

void search(int target){
    if(root == NULL){
        printf("absent \n");
        return;
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

