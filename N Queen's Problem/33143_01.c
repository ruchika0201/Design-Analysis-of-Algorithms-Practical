#include<stdio.h>
#include<stdlib.h>

int x[100];

int place(int k, int i)
{
  int j;
  for(j=1;j<=k-1;j++)
  {
    if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
    {
      return 0;
    }
  }
   return 1;
}

void queen(int k, int n)
{
  int i, j;
  for(i=1;i<=n;i++)
  {
    if(place(k,i))
    {
      x[k]=i;
      if(k==n)
      {
        printf("\nPrinting the chessboard with the queens\n");
        printf("\n");
        for(i=1;i<=n;i++)
        {
          printf("[%d]\t",x[i]);
        
        }
        printf("\n\n");
        for(i=1;i<=n;i++)
        {
          for(j=1;j<=n;j++)
          {
            if(x[i]==j)
            {
              printf("Q\t");
            }
            else
            {
              printf("-\t");
            }
          }
        	printf("\n");
        }
      
      }
      else
      {
        queen(k+1, n);
      }
    }
    
  
  }

}





int main()
{
 int i, j, k, n, a[100][100];
 printf("\nEnter the number of queens::");
 scanf("%d",&n);
 if(n>=4 && n<=12)
 {
 queen(1,n);
}
else
{
 printf("\nThere is no solution!");
}

}


/*

Enter the number of queens::4

Printing the chessboard with the queens

[2]     [4]     [1]     [3]

-       Q       -       -
-       -       -       Q
Q       -       -       -
-       -       Q       -

Printing the chessboard with the queens

[3]     [1]     [4]     [2]

-       -       Q       -
Q       -       -       -
-       -       -       Q
-       Q       -       -

--------------------------------
Process exited after 2.417 seconds with return value 5
Press any key to continue . . .


*/
