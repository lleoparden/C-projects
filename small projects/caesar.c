#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(string a);
string cipher(int a, string b);


int main(int argc , string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    int c = check(argv[1]);

    if(c == 0)
    {

        printf("Usage: ./caesar key\n");

        return 1;
    }
    else
    {
        int n = atoi(argv[1]);

        string plain = get_string("plaintext:  ");

        string ciphertext = cipher(n,plain);

        printf("ciphertext: %s\n", ciphertext);
    }


}

int check(string a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (!isdigit(a[i]))
        {
            return 0;
        }
    }
    return 1;
}

string cipher(int a, string b)
{

    for(int i = 0; i < strlen(b) ; i++)
    {
        if(b[i] >= 'A' && b[i] <= 'Z')
        {
            b[i] -= 'A';

            b[i] = (b[i] + a) % 26;

            b[i] += 'A';
        }
        else if(b[i] >= 'a' && b[i] <= 'z')
        {
            b[i] -= 'a';

            b[i] = (b[i] + a) % 26;

            b[i] += 'a';
        }

    }

    return b;
}
