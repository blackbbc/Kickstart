#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T, N;
int f[10001];
bool flag = true;


int main()
{
	FILE *file = fopen("out.txt", "w");
	
	memset(f, 0x7f, sizeof(f));
	f[0] = 0;
	
	while (flag)
	{
		flag = false;
		for (int j = 10000; j >= 0; j--)
			for (int i = 1; i <= 100; i++)
				if (j - i * i >= 0 && f[j - i * i] + 1 < f[j])
				{
					flag = true;
					f[j] = f[j - i * i] + 1;
				}
	}
	
	cin >> T;
	
	for (int k = 1; k <= T; k++)
	{
		cin >> N;
		fprintf(file, "Case #%d: %d\n", k, f[N]);
	}
	
	fclose(file);
	
	return 0;
}
