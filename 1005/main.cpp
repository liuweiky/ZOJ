#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int Ca, Cb, N;

    while (scanf("%d %d %d", &Ca, &Cb, &N) != EOF)
    {
        int a = 0, b = 0;
        while (b != N)
        {
            //printf("%d %d\n", a, b);
            //system("pause");
            if (b == Cb)
            {
                printf("empty B\n");
                b = 0;
            }
            else if (a != 0)
            {
                printf("pour A B\n");
                if (a <= Cb - b)
                {
                    b += a;
                    a = 0;
                }
                else
                {
                    a -= (Cb - b);
                    b = Cb;
                }
            }
            else
            {
                printf("fill A\n");
                a = Ca;
            }
        }
        printf("success\n");

    }

    return 0;
}
