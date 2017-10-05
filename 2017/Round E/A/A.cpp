#include <cstdio>
#include <cstring>

using namespace std;

int T, N, c;
int i, j, k, l, m, x, y;
char *p, *tp;
char ts[105];

int f[101][101][101];
int b[101];

char s[105];

int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    FILE *inFile = fopen("A-large-practice.in", "r");
    FILE *outFile = fopen("out.txt", "w");

    fscanf(inFile, "%d", &T);

    for (c = 1; c <= T; c++)
    {
        fscanf(inFile, "%s", s);
        printf("%s\n", s);

        memset(f, 0x7f, sizeof(f));
        memset(b, 0x7f, sizeof(b));

        b[0] = 0;
        f[0][0][0] = 1;

        N = strlen(s);

        for (k = 1; k <= N; k++)
        {
            b[k] = k;
            for (l = 0; l < k; l++)
            {
                for (i = 0; i < k - l; i++)
                {
                    j = i + l;


                    for (m = 1; m < k; m++)
                    {
                        x = 0;
                        y = 0;

                        strncpy(ts, s + m, k - m);
                        ts[k-m] = '\0';
                        p = strstr(s, ts);

                        if (p != nullptr)
                        {
                            x = p - s;
                            y = x + k - m - 1;
                            if (y < m && x == i && y == j)
                                f[k][i][j] = min(f[k][i][j], f[m][x][y] + 1);
                        }
                    }


                    f[k][i][j] = min(f[k][i][j], b[k - 1] + 2);

                    f[k][i][j] = min(f[k][i][j], f[k - 1][i][j] + 1);

                    b[k] = min(b[k], f[k][i][j]);

                }
            }

            for (l = 0; l < k; l++)
            {
                for (i = 0; i < k - l; i++)
                {
                    j = i + l;
                    f[k][i][j] = min(f[k][i][j], b[k] + 1);
                }
            }
        }

        fprintf(outFile, "Case #%d: %d\n", c, b[N]);

    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}
