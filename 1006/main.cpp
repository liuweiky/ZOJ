#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int k, n;
    char ciphertext[128];
    int ciphercode[128];
    int plaincode[128];
    char plaintext[128];

    while (scanf("%d", &k) && k != 0)
    {
        scanf("%s", ciphertext);
        n = strlen(ciphertext);
        for (int i = 0; i < n; i++)
        {
            if (ciphertext[i] == '_')
                ciphercode[i] = 0;
            else if (ciphertext[i] == '.')
                ciphercode[i] = 27;
            else
                ciphercode[i] = ciphertext[i] - 'a' + 1;
        }

        for (int i = 0; i < n; i++)
            plaincode[(k * i) % n] = (ciphercode[i] + i) % 28;
        for (int i = 0; i < n; i++)
        {
            if (plaincode[i] == 0)
                plaintext[i] = '_';
            else if (plaincode[i] == 27)
                plaintext[i] = '.';
            else
                plaintext[i] = plaincode[i] + 'a' - 1;
        }
        plaintext[n] = '\0';
        printf("%s\n", plaintext);
    }

    return 0;
}
