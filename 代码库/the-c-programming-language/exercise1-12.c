/* Exercise 1-12 */

#include <stdio.h>

int main(void)
{
    int c;
    int inspace;
    
    inspace = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(inspace == 0)
            {
                inspace = 1;    /* 这里为什么要 inspace=1? mark 一下 */
                putchar('\n');
            }
            /* else, don't print anything */
        }
        else
        {
            inspace = 0;
            putchar(c);
        }
    }
    return 0;
}