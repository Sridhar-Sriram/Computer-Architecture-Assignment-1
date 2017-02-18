#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char** argv){
    if(argc<2){
        printf("error \n");
        return 0;
    }
    
    int i;
    for(i = 1; i<argc; i++){
        char*string_at_iterator = argv[i];
        printf("%c", string_at_iterator[0]);
    }
    printf("\n");
    return 0;
    
}
