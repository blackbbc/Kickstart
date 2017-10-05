#include <iostream>
#include <cstdio>

using namespace std;

int t, n;
int a[10001];

int llist[10000];
int rlist[10000];

bool qsort(int left, int right)
{
	int i = 0, j = 0 , mid, t;
	mid = a[(left + right) >> 1];

	int index = left, count = 0;
	
	while (index <= right)
	{
		if (a[index] < mid)
		{
			llist[i] = a[index];
			i++;
		}
		else if (a[index] > mid)
		{
			rlist[j] = a[index];
			j++;
		}
		index++;
	}	
	
	bool flag = false;
	if (i == right - left || j == right - left)
	{
		flag = true;
	}
	
	index = 0;
	count = 0;
	while (count < i)
	{
		a[left + index] = llist[count];
		index++;
		count++;
	}
	
	a[left + index] = mid;
	index++;
	
	count = 0;
	while (count < j)
	{
		a[left + index] = rlist[count];
		index++;
		count++;
	}
	
	
	if (i > 1) 
	{
		flag = flag & qsort(left, left + i - 1);
	}
	if (j > 1)
	{
		flag = flag & qsort(right - j + 1, right);
	}
	
	return flag;
}

int main()
{
	cin >> t;

	FILE *file = fopen("out.txt", "w");
	for (int k = 1; k <= t; k++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		
		bool flag = qsort(0, n - 1);
			
		if (flag)
		{
			fprintf(file, "Case #%d: %s\n", k, "YES");
		}
		else
		{
			fprintf(file, "Case #%d: %s\n", k, "NO");
		}
		
	}
	
	fclose(file);
	
	return 0;
}
