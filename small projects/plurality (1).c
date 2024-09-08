#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define max 9

typedef struct
{
    string name;
    int vote;
}candidate;

candidate candidates[max];

bool vote(string a);

int main(int argc,string argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./plurality [candidate]\n");

        return 1;
    }
    if(argc > 10)
    {
        printf("Maximum number of candidates is %i\n", max);

        return 1;
        }

 //-----------------------------------------------------------

    for (int i = 0; i < max; i++)
    {

        if(i < argc -1)
        {
            candidates[i].name = argv[i+1];
        }
        else
        {
            candidates[i].name = "z";
        }
        candidates[i].vote = 0;
    }

    int n = get_int("Number of voters: ");
    
    for (int i = 0; i < n; i++)
    {
        string name = get_string("vote: ");
        vote(name);
    }

    int a = 0;

    for(int i = 0; i < argc -1; i++)
    {
        if(candidates[i].vote > a)
        {
            a = candidates[i].vote;
        }
    }
    for(int i = 0; i < argc -1; i++)
    {
        if(candidates[i].vote == a)
        {
            printf("%s\n",candidates[i].name);
        }
    }
}

bool vote(string a)
{ int c = 0;
    for(int i = 0; i < max; i++)
    {
        if(strcmp(candidates[i].name, a) == 0)
        {
            candidates[i].vote++;
            return true;
            c++;
        }
    }
    if (c == 0)
    {
        printf("Invalid vote.\n");
    }
    return true;
}
