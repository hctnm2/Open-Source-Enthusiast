#include<stdio.h>
int main(){
    int A[10][10],B[10][10],C[10][10],m,n,i,j,k,r1,r2,c1,c2;
    printf("Enter numbers of size of array :");
    scanf("%d%d",&m,&n);
    printf("\nEnter row and column size of matrix A : ");
    scanf("%d%d",&r1,&c1);
    printf("\nEnter row and column size of matrix B : ");
    scanf("%d%d",&r2,&c2);
    if (r1==c1) {   
    // Input array elements of A matrix
    printf("Enter elements of Array A : ");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter elements of Array B : ");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&B[i][j]);
        }
    }
    //Output array
    printf("\nThe array elements of Array A :\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\nThe array elements of Array B :\n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    // multiplication calculation
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            C[i][j]=0;
            for(k=0;k<c1;k++){
                C[i][j]=C[i][j]+A[i][k]*B[j][k];
            }
        }
        printf("\n");
    }
    //Display multiplication
    printf("The multiplication of matrix A and B is : \n");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }}else {
    printf("Enter valid matrix to be multiply.");
    }
    return 0;
}
