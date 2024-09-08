#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int c_letters (string  a);
int c_words (string  a);
int c_sentence (string  a);

int main(void)
{
    string text = get_string("text:");

    int letters = c_letters(text);

    int words = c_words(text);

    int sentences = c_sentence(text);

    float l = letters *100.0 / words;

    float s = sentences * 100.0 / words;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    int i = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }


}



int c_letters (string  a)
{
    int c = 0;

    for(int i = 0; i < strlen(a); i++ )
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
        {
             c++;
        }
        if(a[i] >= 'a' && a[i] <= 'z')
        {
             c++;
        }

    }

    return c;
}





int c_words (string  a)
{
    int c = 1;

    for(int i = 0; i < strlen(a) - 1; i++ )
    {
        if (a[i] == ' ' && a[i+1] != ' ')
        {
            c++;
        }
    }

    return c;
}




int c_sentence (string  a)
{
    int c = 0;

    for(int i = 0; i < strlen(a); i++ )
    {
        if (a[i] == '.'|| a[i] == '!' || a[i] == '?'  )
        {
            c++;
        }
    }
    if (c == 0)
    {
        c++;
    }
    return c;
}
