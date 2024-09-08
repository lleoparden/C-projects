#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);

    int c = 0;
    while (n >= 25)
    {
        c++;
        n -= 25;
    }
    while (n >= 10)
    {
        c++;
        n -= 10;
    }
    while (n >= 5)
    {
        c++;
        n -= 5;
    }
    while (n >= 1)
    {
        c++;
        n -= 1;
    }

    printf("%i\n", c);
}
