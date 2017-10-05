#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

int t, n, e, ans, h;
int s[1000];

void qsort(int left, int right)
{
	int i = left;
	int j = right;
	int mid = s[(left + right) >> 1];
	int t;
	
	while (i <= j)
	{
		while (s[i] < mid) i++;
		while (s[j] > mid) j--;
		if (i <= j)
		{
			t = s[i];
			s[i] = s[j];
			s[j] = t;
			i++;
			j--;
		}
	}

	
	if (left < j) qsort(left, j);
	if (right > i) qsort(i, right);
}

int max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}


int main()
{
	ifstream fin("B-large-practice.in");
	FILE *file = fopen("out.txt", "w");
	
	fin >> t;
	
	for (int k = 1; k <= t; k++)
	{
		fin >> e >> n;
		for (int i = 0; i < n; i++)
			fin >> s[i];
			
		ans = 0;
		h = 0;
		
		qsort(0, n-1);
		
		int left = 0, right = n - 1;
		
		bool dance;
		
		while (left <= right)
		{
			dance = false;
			
			if (s[left] < e)
			{
				e -= s[left];
				h += 1;
				ans = max(ans, h);
				dance = true;
				left++;
			}
			
			if (!dance)
			{
				if (h > 0)
				{
					e += s[right];
					h -= 1;
					
				}
				right--;
			}
		}
		
		fprintf(file, "Case #%d: %d\n", k, ans);
	}
	
	fclose(file);
	
	
	return 0;
}
