#include<iostream>
using namespace std;


//	int dis[10][10];
int temp[5]={0}, fair[5]={0}, v=0, flag=0;
int tsp(int mask, int pos, int n, int dis[10][10])
{
	int visited_all=(1<<n)-1;
	if(mask==visited_all)
	{
		temp[v++]=0;
		flag=1;
		return dis[pos][0];
	}

	int ans=999999;
	for(int city=0;city<n;city++)
	{
		if((mask&(1<<city))==0)
		{
		
		temp[v++]=city;
		//	cout<<"\n"<<temp[v];
			int newans=dis[pos][city]+tsp(mask|(1<<city), city, n, dis);
			if(newans<ans)
			{
					int k;
				for(k=0;k<n;k++)
				{
					fair[k]=temp[k];
				}
			
			}
			else
			{
				v=0;
			}
			ans=min(ans, newans);
	
		}
		
	}
	
	
	
	return ans;
}
int main()
{
	int n, dis[10][10], i, j, c;
	cout<<"\nEnter the number of cities :: ";
	cin>>n;
	cout<<"\nThe cities are :: ";
	for(i=0;i<n;i++)
	{
		cout<<i<<"\t";
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"\nEnter the distance between city "<<i<<" and city "<<j<<" :: ";
			cin>>c;
			dis[i][j]=c;
		
		}
	}
	
	cout<<"The shortest path is::"<<tsp(1, 0, n, dis)<<"\n";
	cout<<"Path is :: 0->";
	for(i=0;i<n;i++)
	{
		cout<<temp[i]<<"->";
	}
	return 0;
}
/*
Enter the number of cities :: 4

The cities are :: 0     1       2       3
Enter the distance between city 0 and city 0 :: 0

Enter the distance between city 0 and city 1 :: 20

Enter the distance between city 0 and city 2 :: 42

Enter the distance between city 0 and city 3 :: 25

Enter the distance between city 1 and city 0 :: 20

Enter the distance between city 1 and city 1 :: 0

Enter the distance between city 1 and city 2 :: 30

Enter the distance between city 1 and city 3 :: 34

Enter the distance between city 2 and city 0 :: 42

Enter the distance between city 2 and city 1 :: 30

Enter the distance between city 2 and city 2 :: 0

Enter the distance between city 2 and city 3 :: 10

Enter the distance between city 3 and city 0 :: 25

Enter the distance between city 3 and city 1 :: 34

Enter the distance between city 3 and city 2 :: 10

Enter the distance between city 3 and city 3 :: 0
The shortest path is::85
Path is :: 0->3->1->2->0->
--------------------------------
Process exited after 321.5 seconds with return value 0
Press any key to continue . . .*/
