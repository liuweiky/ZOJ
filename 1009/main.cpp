#include <cstdio>
#include <cstring>

#define MAX_CHAR 32

using namespace std;

int r1[MAX_CHAR];
int r2[MAX_CHAR];
int r3[MAX_CHAR];

int rb1[MAX_CHAR];
int rb2[MAX_CHAR];
int rb3[MAX_CHAR];

int tr[MAX_CHAR];
int M, N;
int rr1 = 0, rr2 = 0, rr3 = 0;
char buf[10240];

void reset()
{
    memcpy(r1, rb1, M * sizeof(int));
    memcpy(r2, rb2, M * sizeof(int));
    memcpy(r3, rb3, M * sizeof(int));
}

void r1rot()
{
    memcpy(tr, r1, M * sizeof(int));
    for (int i = 0; i < M; i++)
        r1[(i + 1) % M] = (tr[i] + 1) % M;
    rr1++;
}

void r2rot()
{
    memcpy(tr, r2, M * sizeof(int));
    for (int i = 0; i < M; i++)
        r2[(i + 1) % M] = (tr[i] + 1) % M;
    rr2++;
}

void r3rot()
{
    memcpy(tr, r3, M * sizeof(int));
    for (int i = 0; i < M; i++)
        r3[(i + 1) % M] = (tr[i] + 1) % M;
    //rr3++;
}

void rot()
{
    r1rot();
    if (rr1 == M)
    {
        rr1 = 0;
        r2rot();
        if (rr2 == M)
        {
            rr2 = 0;
            r3rot();
        }
    }
}

int main()
{
    int cnt = 1;
    while (scanf("%d", &M) && M)
    {
        if (cnt != 1)
            printf("\n");
        printf("Enigma %d:\n", cnt++);
        scanf("%s", buf);
        for (int i = 0; i < M; i++)
            r1[i] = buf[i] - 'A';
        scanf("%s", buf);
        for (int i = 0; i < M; i++)
            r2[i] = buf[i] - 'A';
        scanf("%s", buf);
        for (int i = 0; i < M; i++)
            r3[i] = buf[i] - 'A';

        memcpy(rb1, r1, M * sizeof(int));
        memcpy(rb2, r2, M * sizeof(int));
        memcpy(rb3, r3, M * sizeof(int));
        scanf("%d", &N);

        while (N--)
        {
            reset();
            rr1 = rr2 = rr3 = 0;
            scanf("%s", buf);
            int len = strlen(buf);
            for (int i = 0; i < len; i++)
            {
                int t = buf[i] - 'A';
                int j;
                for (j = 0; j < M; j++)
                {
                    if (t == r3[j])
                        break;
                }
                t = j;
                for (j = 0; j < M; j++)
                {
                    if (t == r2[j])
                        break;
                }
                t = j;
                for (j = 0; j < M; j++)
                {
                    if (t == r1[j])
                        break;
                }
                printf("%c", 'a' + j);
                rot();
            }
            printf("\n");
        }
    }


    return 0;
}
