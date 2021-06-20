//write a program to find maximum and minimum elements in an array using divide and conquer strategy and verify the time complexity.
#include <stdio.h>
#include <stdlib.h>

struct node
{
 int max; 
 int min;
 int a[50];
}t;
struct node maxmin(int i, int j, struct node t)
{
	int mid;
	if (i == j)
	{
		t.max = t.min = t.a[i];
		return t;
	}
	else if (i == j - 1)
	{
		if (t.a[i] < t.a[j])
		{
			t.max = t.a[j];
			t.min = t.a[i];
		}
		else
		{
			t.max = t.a[i];
			t.min = t.a[j];
		}
		return t;
	}
	else
	{
		mid = (i + j) / 2;
		t=maxmin(i, mid, t);
		struct node t1=t;
		t1.max=t.max;
		t1.min=t.min;
		t1=maxmin(mid + 1, j, t1);

		if (t.max < t1.max)
		{
			t.max = t1.max;
		}
		if (t.min > t1.min)
		{
			t.min = t1.min;
		}
		return t;
	}
}
int main()
{

	int i, n;
	printf("\nEnter number of elements::");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter a[%d]::", i);
		scanf("%d", &t.a[i]);
	}
	t.max = t.min = t.a[0];

	printf("\n");
	t=maxmin(0, n - 1, t);
	
	printf("\nMaximum::%d", t.max);
	printf("\nMinimum::%d", t.min);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("\t%d", t.a[i]);
	}
	printf("\n");
}
/*
Enter number of elements::6

Enter a[0]::7

Enter a[1]::5

Enter a[2]::1

Enter a[3]::2

Enter a[4]::3

Enter a[5]::4


Maximum::7
Minimum::1
        7       5       1       2       3       4

--------------------------------
Process exited after 10.59 seconds with return value 10
Press any key to continue . . .*/
