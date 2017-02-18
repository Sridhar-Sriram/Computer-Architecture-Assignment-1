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
            matrix1 = (int**)malloc(rows1*sizeof(int*));
            count++;
        }else if(count == 1){
            columns1 = num;
            int i;
            for(i=0; i<rows1; i++){
                matrix1[i] = (int*)malloc(columns1*sizeof(int));
            }
            count++;
        }else if(count == (rows1*columns1 + 2)){
            rows2 = num;
            if(rows2!=columns1){
                printf("error \n");
                exit(0);
                return 1;
            }
            matrix2 = (int**)malloc(rows2*sizeof(int*));
            count++;
        }else if(count == (rows1*columns1 + 3)){
            columns2 = num;
            int j;
            for(j=0; j<rows2; j++){
                matrix2[j] = (int*)malloc(columns2*sizeof(int));
            }
            count++;
        }else if(count < rows1*columns1+2){
            int row = (int)((count-2)/columns1);
            int column = (int)((count-2)%columns1);
            matrix1[row][column] = num;
            count++;
        }else{
            int row =(int)((count - rows1*columns1 - 4)/(columns2));
            int column =(int)((count - rows1*columns1 - 4)%columns2);
            matrix2[row][column] = num;
            count++;
            
        }
    }
    
    
    
    
    int final_matrix[rows1][columns2];
    int x, y;
    for(x = 0; x < rows1; x++){
        for(y = 0; y<columns2; y++){
            final_matrix[x][y] = 0;
        }
    }

    int row1 =0;
    int col2 =0;
    int col1 = 0;
    for(row1 = 0; row1<rows1; row1++){
        for(col2 =0; col2<columns2; col2++){
            for(col1 = 0; col1 <columns1; col1++){
                final_matrix[row1][col2] =  final_matrix[row1][col2]+ matrix1[row1][col1]*matrix2[col1][col2];
            }
            
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
