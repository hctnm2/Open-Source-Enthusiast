#include<stdio.h>
int main()
{
  int i,j,n,temp;
  int a[10];
  int *p=&a[0];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",(p+i));
  }
  printf("before sort\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",*(p+i));
  }
  for(i=0;i<n-1;i++)
  {
      for(j=0;j<n-i-1;j++)
      {
          if(*(p+j)>*(p+(j+1)))
          {
              temp=*(p+j);
              *(p+j)=*(p+(j+1));
              *(p+(j+1))=temp;
          }
      }
  }
  printf("after sort\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",*(p+i));
  }
  return 0;
}
