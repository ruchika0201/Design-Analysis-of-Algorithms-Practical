#include<iostream>
#define MAX 10
using namespace std;

typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void bellman_ford(int nv,edge e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];
  
  
  for(i=0;i<nv;i++)
  {
    dis[i]=999;
  }
    
 
  dis[src_graph]=0;
  

  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      weight=e[j].wt;
    

      if(dis[u]!=999 && dis[u]+weight < dis[v])
      {
        dis[v]=dis[u]+weight;
      }	
    }
    
  }
  
  
  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;
    
    if(dis[u]+weight < dis[v])
    {
      cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
      return;
    }	
  }
  
  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<=nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i];
  }

}


int main()
{
  int nv,ne,src_graph;
  edge e[MAX];
  
  cout<<"Enter the number of vertices: ";
  cin>>nv;	
  
  
  printf("Enter the source vertex of the graph: ");
  cin>>src_graph;	
  
  cout<<"\nEnter no. of edges: ";
  cin>>ne;
  
  for(int i=0;i<ne;i++)
  {
    cout<<"\nFor edge "<<i+1<<"=>";
    cout<<"\nEnter source vertex :";
    cin>>e[i].src;
    cout<<"Enter destination vertex :";
    cin>>e[i].dest;
    cout<<"Enter weight :";
    cin>>e[i].wt;	
  }
  
  bellman_ford(nv,e,src_graph,ne);
  
  return 0;
}
/*Enter the number of vertices: 5
Enter the source vertex of the graph: 1

Enter no. of edges: 9

For edge 1=>
Enter source vertex :1
Enter destination vertex :2
Enter weight :4

For edge 2=>
Enter source vertex :1
Enter destination vertex :3
Enter weight :2

For edge 3=>
Enter source vertex :2
Enter destination vertex :4
Enter weight :2

For edge 4=>
Enter source vertex :2
Enter destination vertex :3
Enter weight :3

For edge 5=>
Enter source vertex :3
Enter destination vertex :2
Enter weight :1

For edge 6=>
Enter source vertex :3
Enter destination vertex :4
Enter weight :4

For edge 7=>
Enter source vertex :3
Enter destination vertex :5
Enter weight :5

For edge 8=>
Enter source vertex :2
Enter destination vertex :5
Enter weight :3

For edge 9=>
Enter source vertex :5
Enter destination vertex :4
Enter weight :-5

Vertex  Distance from source
1       0
2       3
3       2
4       -5
5       0
--------------------------------
Process exited after 150.4 seconds with return value 0
Press any key to continue . . .*/
