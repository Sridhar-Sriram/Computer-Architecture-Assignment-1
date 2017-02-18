#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
    
    int inputted_number = atoi(argv[1]);
    
    int i;
    for(i = 2; i<inputted_number; i++){
        if(inputted_number%i == 0){
            printf("no \n");
            exit(0);
        }
    }
    printf("yes\n");
    return 0;
    
}
