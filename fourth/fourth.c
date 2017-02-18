#include<stdio.h>
#include<stdlib.h>



int main(int argc, char** argv){
    char*filename = argv[1];
    FILE*fp;
    
    fp = fopen(filename, "r");
    
    int rows1=0;
    int columns1=0;
    int rows2=0;
    int columns2 = 0;
    
    int ** matrix1;
    int num =0;
    int**matrix2;
    
    int count = 0;
    
    
    
    while(fscanf(fp,"%d \t", &num)!=EOF){
        if(count == 0){
            rows1 = num;
            rows2 = num;
            matrix1 = (int**)malloc(rows1*sizeof(int*));
            matrix2 = (int**)malloc(rows1*sizeof(int*));
            count++;
        }else if(count == 1){
            columns1 = num;
            columns2= num;
            int i;
            for(i=0; i<rows1; i++){
                matrix1[i] = (int*)malloc(columns1*sizeof(int));
                matrix2[i] = (int*)malloc(columns2*sizeof(int*));
            }
            count++;
        }else if(count < rows1*columns1+2){
            int row = (int)((count-2)/columns1);
            int column = (int)((count-2)%columns1);
            matrix1[row][column] = num;
            count++;
        }else{
            int row =(int)((count - rows1*columns1 - 2)/(columns2));
            int column =(int)((count - rows1*columns1 - 2)%columns2);
            matrix2[row][column] = num;
            count++;
            
        }
    }
    
    
    
    
    int final_matrix[rows1][columns1];
    int x, y;
    for(x = 0; x < rows1; x++){
        for(y = 0; y<columns1; y++){
            final_matrix[x][y] = 0;
        }
    }
    
    int row =0;
    int col =0;
 
    for(row = 0; row<rows1; row++){
        for(col =0; col<columns2; col++){
            final_matrix[row][col] =  matrix1[row][col]+matrix2[row][col];
            
            
        }
    }
    
    int rf =0;
    int cf =0;
    for(rf = 0; rf<rows1; rf++){
        for(cf = 0; cf<columns2; cf++){
            printf("%d\t", final_matrix[rf][cf]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
    
}
