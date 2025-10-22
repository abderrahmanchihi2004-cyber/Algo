#include<stdio.h>

int main()
{
   int n;
    printf("entersize of matrix");
    scanf("%d",&n);
    int arr[n][n],i,j;
    printf("enter the elements of the matrix:\n");
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
         scanf("%d",&arr[i][j]);
        }
      } 
    printf("Matrix before swap");
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
         printf("%d",arr[i][j]);
        }
        printf("\n");
      }  
      for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
          int temp=arr[i][j];
          arr[i][j]=arr[j][i];
          arr[j][i]=temp;
        } 
      }   
    printf("Matrix after swap"); 
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
         printf("%d",arr[i][j]);
        }
        printf("\n");
      }  
    return 0;
}
