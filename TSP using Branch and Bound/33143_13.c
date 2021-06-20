#include <stdio.h>
#include <stdlib.h>

int parent, source=0;
int result[10];


void PrintMat(int arr[10][10],int n);
int ReduceMatrix(int arr[10][10], int num);
void CopyMat(int src[10][10], int dest[10][10], int num);
void TSP(int graph[10][10], int num, int src, int marked[10], int count);
int Apply(int graph[10][10], int num, int row, int col, int marked[10]);
void Print_Result(int num);


int main()
{
    int num, i, j;
    int graph[10][10], marked[10];
    parent=0;
    printf("\nEnter no. of vertex :");
    scanf("%d",&num);
    printf("\nEnter cost matrix:");
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("\ncost[%d][%d] : ",i,j);
            scanf("%d",&graph[i][j]);
            if(graph[i][j] == 0)
                graph[i][j] = 999;
        }
    }
       
    printf("\nEntered cost matrix :");
    PrintMat(graph,num);
    
    //printf("\nEnter source :");
   // scanf("%d",&source);
    
    for(i=0;i<num;i++)
    {
        marked[i] = 0;
        result[i] = -1;
    }
    
    parent = ReduceMatrix(graph, num);
    printf("\nInitial Reduced Graph :");
    PrintMat(graph,num);
    printf("\nCost of parent : %d\n\n\n",parent);
    
    marked[0]=1;
    TSP(graph,num,0,marked,1);
    
    return 0;
}

int Apply(int graph2[10][10], int num, int row, int col, int marked[10])
{
    int i,j,sum=0;
    int min = 999;
    
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(i==row || j==col || (i==col && marked[j] == 1))
                graph2[i][j] = 999;
        }
    }
    
    sum = ReduceMatrix(graph2,num);
    
    return(sum);
}

void Print_Result(int num)
{
    int i,count=0,sum=0;
    
    printf("\nPath  \n");
    
    i=source;
    while(count<=num)
    {
        printf("%d ->",i+1);
        //sum = sum + cost[i][result[i]];
        i = result[i];
        count++;
    }
    printf("\n\n\tCost : %d\n\n",parent);
}

void TSP(int graph[10][10], int num, int src, int marked[10], int count)
{
    int l=0;
    int graph1[10][10];
    int i, j, temp, d, min = 999, chk = 0, red_cost;
    
    
    for(i=0;i<num;i++)
    {
        if(marked[i]==0)
        {
            CopyMat(graph,graph1,num);
            
            temp = Apply(graph1,num,src,i,marked);
            red_cost = temp+parent+graph[src][i];
            printf("\nFor Path (%d,%d) : Cost = %d",src,i,red_cost);
            if(red_cost < min)
            {
                min = red_cost;
                d = i;
            }
            
        }
    }
    
    printf("\nSelected Path : (%d,%d)\n",src,d);
    result[src] = d;
    
    temp = Apply(graph,num,src,d,marked);
    printf("\nReduced Matrix :");
            PrintMat(graph,num);
    
    marked[d] = 1;
    parent = min;
    printf("\nCost of parent : %d",parent);
    if(count == num-1)
    {
        result[d]=source;
        Print_Result(num);
        return;
    }
    else
        TSP(graph,num,d,marked,count+1);
}

void PrintMat(int graph[110][10], int num)
{
    int i, j;
    for(i=0;i<num;i++)
    {
        printf("\n");
        for(j=0;j<num;j++)
            printf("%d\t",graph[i][j]);
    }
    printf("\n");
}

int Min_Row(int graph[10][10], int num, int row)
{
    int i, min=999;
    for(i=0;i<num;i++)
        if(graph[row][i] < min)
            min = graph[row][i];
    if(min == 999)
        return 0;
    return min;
}

int Min_Col(int graph[10][10], int num, int col)
{
    int i, min=999;
    for(i=0;i<num;i++)
        if(graph[i][col] < min)
            min = graph[i][col];
    if(min == 999)
        return 0;
    return min;
}

int ReduceMatrix(int arr[10][10], int num)
{
    int i, j, temp, sum = 0;

    for(i=0;i<num;i++)
    {
        temp = Min_Row(arr,num,i);
        if(temp!=0)
        {
            for(j=0;j<num;j++)
            {
                if(arr[i][j] != 999)
                {
                    arr[i][j] -= temp;
                }
            }
        }
        sum += temp;
    }
    
    for(i=0;i<num;i++)
    {
        temp = Min_Col(arr,num,i);
        if(temp!=0 )
        {
            for(j=0;j<num;j++)
                if(arr[j][i] != 999)
                    arr[j][i] -= temp;
        }
        sum += temp;
    }
    return sum;
}

void CopyMat(int src[10][10], int dest[10][10], int num)
{
    int i,j;
    for(i=0;i<num;i++)
        for(j=0;j<num;j++)
            dest[i][j] = src[i][j];
}
/*

Enter no. of vertex :5

Enter cost matrix:
cost[0][0] : 999

cost[0][1] : 20

cost[0][2] : 30

cost[0][3] : 10

cost[0][4] : 11

cost[1][0] : 15

cost[1][1] : 999

cost[1][2] : 16

cost[1][3] : 4

cost[1][4] : 2

cost[2][0] : 3

cost[2][1] : 5

cost[2][2] : 999

cost[2][3] : 2

cost[2][4] : 4

cost[3][0] : 19

cost[3][1] : 6

cost[3][2] : 18

cost[3][3] : 999

cost[3][4] : 3

cost[4][0] : 16

cost[4][1] : 4

cost[4][2] : 7

cost[4][3] : 16

cost[4][4] : 999

Entered cost matrix :
999     20      30      10      11
15      999     16      4       2
3       5       999     2       4
19      6       18      999     3
16      4       7       16      999

Initial Reduced Graph :
999     10      17      0       1
12      999     11      2       0
0       3       999     0       2
15      3       12      999     0
11      0       0       12      999

Cost of parent : 25



For Path (0,1) : Cost = 35
For Path (0,2) : Cost = 53
For Path (0,3) : Cost = 25
For Path (0,4) : Cost = 31
Selected Path : (0,3)

Reduced Matrix :
999     999     999     999     999
12      999     11      999     0
0       3       999     999     2
999     3       12      999     0
11      0       0       999     999

Cost of parent : 25
For Path (3,1) : Cost = 28
For Path (3,2) : Cost = 50
For Path (3,4) : Cost = 36
Selected Path : (3,1)

Reduced Matrix :
999     999     999     999     999
999     999     11      999     0
0       999     999     999     2
999     999     999     999     999
11      999     0       999     999

Cost of parent : 28
For Path (1,2) : Cost = 52
For Path (1,4) : Cost = 28
Selected Path : (1,4)

Reduced Matrix :
999     999     999     999     999
999     999     999     999     999
0       999     999     999     999
999     999     999     999     999
999     999     0       999     999

Cost of parent : 28
For Path (4,2) : Cost = 28
Selected Path : (4,2)

Reduced Matrix :
999     999     999     999     999
999     999     999     999     999
999     999     999     999     999
999     999     999     999     999
999     999     999     999     999

Cost of parent : 28
Path
1 ->4 ->2 ->5 ->3 ->1 ->

        Cost : 28


--------------------------------
Process exited after 70.83 seconds with return value 0
Press any key to continue . . .*/
