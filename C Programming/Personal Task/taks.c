#include "prototypes.h"

int main(void){
    FILE *inputFilePtr; /* Creating pointer to the input file */
    int row, col;

    inputFilePtr = fopen("conc.inp", "r"); /* Opening the file in read mode */

    if(inputFilePtr==NULL){ /* Checking if the file is correctly opened */
        perror ("Error in opening file");
        return (-1);
    }

    fscanf(inputFilePtr, "%d ", &col); /* Using the input to initialize the columns of the matrix */
    fscanf(inputFilePtr, "%d ", &row); /* Using the input to initialize the rows of the matrix */

    int **resultsArr = (int **)malloc(row * sizeof(int *));  /* Dynamically  allocating memory for the matrix I need */
    for (int i = 0; i < row; i++){
        resultsArr[i] = (int *)malloc((col+1) * sizeof(int)); /* Dynamically  allocating memory for the rows of the matrix I nedd */
    }
    
    for (int i = 0; i < row; i++){  
        for (int j = 0; j < col; j++){
            fscanf(inputFilePtr, "%d ", &resultsArr[i][j]); /* Filling the matrix with the input */
        }
    }

    calculateAndSaveResult(resultsArr, row, col); /* Calling the function that actually calculates the final results and write them in conc.out file */

    fclose(inputFilePtr); /* Closing the input file */
    inputFilePtr = NULL; /* Setting the pointer to the input file to NULL */
    for (int i = 0; i < row; i++){  
        free(resultsArr[i]); /* Releasing the memory used for the rows in the matrix */
    }
    free(resultsArr); /* Releasing the memory for the matrix */

    return 0;
}
