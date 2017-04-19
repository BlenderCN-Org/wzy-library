/* Exercise 1-9
 * Write a program to copy this input to its output, replacing each 
 * string of one or more blanks by a single blank.
 */

#include <stdio.h>
 
int main(void)
{
    int c;
    int inspace;
    
    inspace = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            if(inspace == 0)
            {
                inspace = 1;
                putchar(c);
            }
        }
        
        /* We haven't met 'else' yet, so we have to be a little clumsy */
        if(c != ' ')
        {
            inspace = 0;
            putchar(c);
        }
    }
    
    return 0;
}

/* Chris Sidi writes: "instead of having an "inspace" boolean, you can 
 * keep track of the previous character and see if both the current 
 * character and previous character are spaces:"
 */

#include <stdio.h>

/* count lines in input */
int main()
{
    int c, pc; /* c = character, pc = previous character */
    
    /* set pc to a value that wouldn't match any character, in case
     this program is ever modified to get rid of multiples of other
     characters */
    
    pc = EOF;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            if (pc != ' ')   /* or if (pc != c) */
                putchar(c);
        
        /* We haven't met 'else' yet, so we have to be a little clumsy */
        if (c != ' ')
            putchar(c);
        pc = c;
    }
    
    return 0;
}

/* Stig writes: "I am hiding behind the fact that break is mentioned 
 * in the introduction"!
 */

#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar(c);
            while((c = getchar()) == ' ' && c != EOF)
                ;
        }
        if (c == EOF)
            break; /* the break keyword is mentioned
                    * in the introduction...
                    * */
        
        putchar(c);
    }
    return 0;
} 