#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>




#pset2 Caesar solution of Cs50x
#adam50.com
#twitter : https://twitter.com/turabaev69/
#github : https://github.com/turabaev69/
#reddit: https://www.reddit.com/user/odom50/


int main(void)
{
    int i, j;

    for (i = 1; i < 3; i++)
    {
        printf("%d-itearation \n", i);
        for(j = 1); j < 3; j++)
        {
            printf("%d x %d = %d \n", i,j, i * j);
            printf("%d\n",i);
        }

    }
    return 0;
}