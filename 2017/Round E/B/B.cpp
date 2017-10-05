#include <iostream>
#include <cstdio>

using namespace std;

int T, N, ans;
int l[5000];
int trapezoid[4];

bool judge(int l1, int l2, int l3, int l4)
{
    if (l1 == l2 && l3 != l4 && l1 > abs((l3-l4)/2))
        return true;
    else
        return false;
}

void dfs(int floor, int index)
{
    if (floor == 4)
    {
        if (judge(trapezoid[0], trapezoid[1], trapezoid[2], trapezoid[3]))
            ans += 1;
        else if (judge(trapezoid[0], trapezoid[2], trapezoid[1], trapezoid[3]))
            ans += 1;
        else if (judge(trapezoid[0], trapezoid[3], trapezoid[1], trapezoid[2]))
            ans += 1;
        else if (judge(trapezoid[1], trapezoid[2], trapezoid[0], trapezoid[3]))
            ans += 1;
        else if (judge(trapezoid[1], trapezoid[3], trapezoid[0], trapezoid[2]))
            ans += 1;
        else if (judge(trapezoid[2], trapezoid[3], trapezoid[0], trapezoid[1]))
            ans += 1;
        return;
    }

    for (int i = index; i < N - 3 + floor; i++)
    {
        trapezoid[floor] = l[i];
        dfs(floor + 1, i + 1);
    }
}

int main()
{
    FILE *inFile = fopen("B-small-practice.in", "r");
    FILE *outFile = fopen("out.txt", "w");

    fscanf(inFile, "%d", &T);
    //scanf("%d", &T);

    for (int k = 1; k <= T; k++)
    {
        fscanf(inFile, "%d", &N);
        //scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            fscanf(inFile, "%d", &l[i]);
            //scanf("%d", &l[i]);
        }

        ans = 0;
        dfs(0, 0);

        fprintf(outFile, "Case #%d: %d\n", k, ans);
        //printf("Case #%d: %d\n", k, ans);
    }


    fclose(inFile);
    fclose(outFile);

    return 0;
}
