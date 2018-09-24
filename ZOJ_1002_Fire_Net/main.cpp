#include <cstdio>
#include <climits>

#define MAX_N 16

#define HOUSE 'O'
#define EMPTY '.'
#define WALL 'X'

using namespace std;

char cmap[MAX_N][MAX_N];

int N;
int tmp_count, max_count;

struct row_column
{
    int r, c;
};

bool check()
{
    for (int i = 1; i <= N; i++)
    {
        int hori = 0, vert = 0;
        for (int j = 1; j <= N; j++)
        {
            if (cmap[i][j] == HOUSE)
            {
                if (hori == 0)
                    hori = 1;
                else if (hori == 1)
                    return false;
            }
            else if (cmap[i][j] == WALL)
            {
                hori = 0;
            }

            if (cmap[j][i] == HOUSE)
            {
                if (vert == 0)
                    vert = 1;
                else if (vert == 1)
                    return false;
            }
            else if (cmap[j][i] == WALL)
            {
                vert = 0;
            }
        }
    }
    return true;
}

struct row_column getrc(int k)
{
    int r = k / N + 1;
    int c = k % N + 1;
    row_column rc = row_column();
    rc.r = r;
    rc.c = c;
    return rc;
};

void print_map()
{
    printf("\n");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%c", cmap[i][j]);
        printf("\n");
    }
    printf("\n");
}

void gen_j(int k)
{
    //printf("%d, %d %d\n", k, rc.r, rc.c);
    //print_map();
    if (k == N * N + 1)
    {
        //printf("\n");
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                //printf("%c", cmap[i][j]);
                if (cmap[i][j] == HOUSE)
                    cnt++;
            }
            //printf("\n");
        }
        //printf("\n");
        if (cnt > tmp_count)
            tmp_count = cnt;
        return;
    }

    if (!check())   // ºÙ÷¶
        return;

    //printf("\n%d\n", k);

    row_column rc = getrc(k);
    if (cmap[rc.r][rc.c] == WALL)
        gen_j(k + 1);
    else
    {
        cmap[rc.r][rc.c] = HOUSE;
        gen_j(k + 1);
        cmap[rc.r][rc.c] = EMPTY;
        gen_j(k + 1);
    }
}

int main()
{
    tmp_count = 0;
    max_count = INT_MIN;
    scanf("%d", &N);
    while (N != 0)
    {
        getchar();
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                scanf("%c", &cmap[i][j]);
            getchar();
        }
        //printf("%d\n", check());
        if (cmap[1][1] == WALL)
            gen_j(2);
        else
        {
            cmap[1][1] = HOUSE;
            gen_j(2);
            cmap[1][1] = EMPTY;
            gen_j(2);
        }
        printf("%d\n", tmp_count);
        scanf("%d", &N);
        tmp_count = 0;
    }
    return 0;
}
