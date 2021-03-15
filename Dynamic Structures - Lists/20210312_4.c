/* The Floyd-Warshall algorithm */

#include <stdio.h>

#define N 6
#define INF 9999

int main(void){
    int i,j,k;
    int A[N][N] = {
        {0, 7, 9, INF, INF,14},
        {7, 0, 10, 15,INF,INF},
        {9, 10, 0,11,INF, 2},
        {INF,15,11,0,6,INF},
        {INF,INF,INF,6,0,9},
        {14,INF,2,INF,9,0}};

    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (A[i][k] + A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                        printf("A[%d][%d] = A[%d][%d] + A[%d][%d] = %d\n", i, j, i, k, k, j, A[i][j]);
                }

    for(i=0;i< N;i++){
        for(j=0;j< N;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* Prints 
A[1][5] = A[1][0] + A[0][5] = 21
A[5][1] = A[5][0] + A[0][1] = 21
A[0][3] = A[0][1] + A[1][3] = 22
A[3][0] = A[3][1] + A[1][0] = 22
A[3][5] = A[3][1] + A[1][5] = 36
A[5][3] = A[5][1] + A[1][3] = 36
A[0][3] = A[0][2] + A[2][3] = 20
A[0][5] = A[0][2] + A[2][5] = 11
A[1][5] = A[1][2] + A[2][5] = 12
A[3][0] = A[3][2] + A[2][0] = 20
A[3][5] = A[3][2] + A[2][5] = 13
A[5][0] = A[5][2] + A[2][0] = 11
A[5][1] = A[5][2] + A[2][1] = 12
A[5][3] = A[5][2] + A[2][3] = 13
A[0][4] = A[0][3] + A[3][4] = 26
A[1][4] = A[1][3] + A[3][4] = 21
A[2][4] = A[2][3] + A[3][4] = 17
A[4][0] = A[4][3] + A[3][0] = 26
A[4][1] = A[4][3] + A[3][1] = 21
A[4][2] = A[4][3] + A[3][2] = 17
A[0][4] = A[0][5] + A[5][4] = 20
A[2][4] = A[2][5] + A[5][4] = 11
A[4][0] = A[4][5] + A[5][0] = 20
A[4][2] = A[4][5] + A[5][2] = 11
0 7 9 20 20 11 
7 0 10 15 21 12 
9 10 0 11 11 2 
20 15 11 0 6 13 
20 21 11 6 0 9 
11 12 2 13 9 0 */