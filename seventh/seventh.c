#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char**argv){
    if(argc <0){
        return 0;
    }
    
    int iterator;
    for(iterator = 1; iterator<argc; iterator++){
        char*iterator_string = argv[iterator];
        int iterator_string_length = strlen(iterator_string);
        printf("%c",iterator_string[iterator_string_length -1]);
        
    }
    printf("\n");
    return 0;
}
