//Cat 0 solution

#include <stdio.h>

#define MAXLINE 1000 /* max input line size */
#define TAB2SPACE 4 /* 4 spaces to a tab */

char line[MAXLINE]; /*current input line*/

int getl(void);  /* taken from the KnR book. */


int main()
{
    int i,t;
    int spacecount,len;
    
    while (( len = getl()) > 0 )
    {
        spacecount = 0;
        for( i=0; i < len; i++)
        {
            if(line[i] == ' ')
                spacecount++; /* increment counter for each space */
            if(line[i] != ' ')
                spacecount = 0; /* reset counter */
            if(spacecount == TAB2SPACE) /* Now we have enough spaces
                                         ** to replace them with a tab
                                         */
            {
                /* Because we are removing 4 spaces and
                 ** replacing them with 1 tab we move back
                 ** three chars and replace the ' ' with a \t
                 */
                i -= 3; /* same as "i = i - 3" */
                len -= 3;
                line[i] = '\t';
                /* Now move all the char's to the right into the
                 ** places we have removed.
                 */
                for(t=i+1;t<len;t++)
                    line[t]=line[t+3];
                /* Now set the counter back to zero and move the
                 ** end of line back 3 spaces
                 */
                spacecount = 0;
                line[len] = '\0';
            }
        }
        printf("%s", line);
    }
    return 0;
}


/* getline: specialized version */
int getl(void)
{
    int c, i;
    extern char line[];
    
    for ( i=0;i<MAXLINE-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n') 
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
    
}
//Cat 1 solution:

#include <stdio.h>

#define TABSTOP 4

int main(void)
{
    size_t spaces = 0;
    int ch;
    size_t x = 0;               /* position in the line */
    size_t tabstop = TABSTOP;   /* get this from the command-line
                                 * if you want to */
    
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
        {
            spaces++;
        }
        else if (spaces == 0) /* no space, just printing */
        {
            putchar(ch);
            x++;
        }
        else if (spaces == 1) /* just one space, never print a tab */
        {
            putchar(' ');
            putchar(ch);
            x += 2;
            spaces = 0;
        }
        else
        {
            while (x / tabstop != (x + spaces) / tabstop)
            /* are the spaces reaching behind the next tabstop ? */
            {
                putchar('\t');
                x++;
                spaces--;
                while (x % tabstop != 0)
                {
                    x++;
                    spaces--;
                }
            }
            
            while (spaces > 0) /* the remaining ones are real space */
            {
                putchar(' ');
                x++;
                spaces--;
            }
            putchar(ch); /* now print the non-space char */
            x++;
        }
        if (ch == '\n')
        {
            x = 0; /* reset line position */
        }
    }
    
    return 0;
}