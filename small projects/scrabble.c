#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string lower(string a);

int main(void){
     int num[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    string x = get_string("Player 1:");
    string y = get_string("Player 2:");
    x = lower(x);
    y = lower(y);
    int c_x = 0;
    int c_y = 0;
    for(int i = 0; i > strlen(x);i++)
        {
        c_x += num['a'-x[i]];
        }
    for(int i = 0; i > strlen(y);i++)
        {
        c_y += num['a'-y[i]];
        }
    if(c_x > c_y)
        {
            printf("Player 1 wins!");
        }
    else if(c_x < c_y)
        {
            printf("Player 2 wins!");
        }
    else
        {
            printf("Tie!");
        }

}

string lower(string a){
        for(int i = 0; i < strlen(a); i++)
        {
          if( a[i] >= 'a' && a[i] <= 'z')
            {
              a[i] = tolower(a[i]);
            }
            else
            {
                a[i] = 0;
            }
    }
    return a;
}
