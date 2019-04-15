#include <cstdio>

#define MAX_K 500000LL

using namespace std;

int main()
{
    long long k12 = (MAX_K - 1) * (MAX_K - 1);
    for (int i = 0; i <= 2000; i++)
    {
        double x = i / 1000.0;

        double sum = 0;

        for (int j = 1; j < MAX_K; j++)
            sum +=  1 / (j * (j + x) * (j + 1));

        double ans = (1.0 - x) * (sum + 1.0 / (2.0 * k12)) + 1.0;

        printf("%5.3f %16.12f\n", x, ans);
    }

    return 0;
}
