
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
    printf("\nMatrix before swap :\n");
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
         printf("%d",arr[i][j]);
        }
        printf("\n");
      }  
      for(i=0;i<n;i++){
        for(j=i;j<n;j++){
          int s=arr[i][j];
          arr[i][j]=arr[j][i];
          arr[j][i]=s;
        } 
      }   
    printf("\nMatrix after swap:\n"); 
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
         printf("%d",arr[i][j]);
        }
        printf("\n");
      }  
    return 0;
}
