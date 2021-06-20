#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergesort(int arr[], int l, int r);
void merge(int arr[], int i1, int j1, int i2, int j2);
void store(int n, int m, int a[]);

void merge(int arr[100], int i1, int j1, int i2, int j2)
{
	int i, j, k = 0;
	int temp[100];
	i = i1;
	j = i2;
	while (i <= j1 && j <= j2)
	{
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= j1)
		temp[k++] = arr[i++];
	while (j <= j2)
		temp[k++] = arr[j++];
	for (i = i1, j = 0; i <= j2; i++, j++)
	{
		arr[i] = temp[j];
	}
}
void mergesort(int arr[100], int l, int r)
{
	int mid = 0;
	if (l < r)
	{
		mid = (l + r) / 2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		merge(arr, l, mid, mid + 1, r);
	}
}

void store(int n, int m, int a[])
{
	int j = 0, i, k, tape[20][20], r = 0, tape_ind = 0, sum_arr[10], count[10];
	float avg_arr[10], mrt=0;
	int sum = 0, sum1=0;
	for(i=0;i<10;i++)
	{
	sum_arr[i]=0;
	count[i]=0;
	avg_arr[i]=0.0;
	}
	memset(tape, 0, sizeof(tape));


	for (i = 0; i < n; i++)
	{
		tape[r][tape_ind] = a[i];
		//printf("\t%d", tape[r][tape_ind]);
		r++;
		if (r >= m)

		{

			tape_ind++;
			r = 0;
			//printf("\n");
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<20;j++)
		{
			if(tape[i][j]!=0)
			{
				count[i]=count[i]+1;
			}
		}
	}
	

	for(i=0;i<m;i++)
	{
	for(j=0;j<count[i];j++)
	{
		for(k=0;k<=j;k++)
		{
			sum1=sum1+tape[i][k];
		}
		sum=sum+sum1;
		sum1=0;
	  
	  
	}
	sum_arr[i]=sum;
	    sum=0;
	}
	printf("\n");
	
	
	
	for (i = 0; i < m; i++)
	{
		printf("\nElements in tape[%d]::",i+1);
		for (j = 0; j < count[i]; j++)
		{
			printf("\t%d", tape[i][j]);
		}
		//printf("\n");
	}
	
	printf("\n--------------------------------------------------");
	for(i=0;i<m;i++)
	{
	avg_arr[i]=(float)sum_arr[i]/count[i];
	printf("\nAverage MRT of tape[%d] = %f",i+1,avg_arr[i]);
	}
		printf("\n--------------------------------------------------");
for(i=0;i<m;i++)
{
	mrt=mrt+avg_arr[i];
}
mrt=mrt/m;
printf("\nMRT = %f",mrt);
	printf("\n");
}


int main()
{
	int i, n, a[10], t, l;
	printf("\nEnter the number of programs you want to enter::");
	scanf("%d", &n);
	printf("\nEnter the number of tapes::");
	scanf("%d", &t);
	//printf("\nEnter the length of tape::");
	//scanf("%d", &l);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the length of program [%d]::", i+1);
		scanf("%d", &a[i]);
	}
	
	mergesort(a, 0, n - 1);
	printf("\nThe sorted array is::");
	for (i = 0; i < n; i++)
	{
		printf("\t%d\t", a[i]);
	}
		printf("\n--------------------------------------------------");
	printf("\n");

	store(n, t, a);

}
/*
Enter the number of programs you want to enter::8

Enter the number of tapes::4

Enter the length of program [1]::5

Enter the length of program [2]::6

Enter the length of program [3]::7

Enter the length of program [4]::8

Enter the length of program [5]::9

Enter the length of program [6]::1

Enter the length of program [7]::2

Enter the length of program [8]::3

The sorted array is::   1               2               3               5
        6               7               8               9
--------------------------------------------------


Elements in tape[1]::   1       6
Elements in tape[2]::   2       7
Elements in tape[3]::   3       8
Elements in tape[4]::   5       9
--------------------------------------------------
Average MRT of tape[1] = 4.000000
Average MRT of tape[2] = 5.500000
Average MRT of tape[3] = 7.000000
Average MRT of tape[4] = 9.500000
--------------------------------------------------
MRT = 6.500000

--------------------------------
Process exited after 20.39 seconds with return value 10
Press any key to continue . . .*/
