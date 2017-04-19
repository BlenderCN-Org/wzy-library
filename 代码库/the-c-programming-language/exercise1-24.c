//Category 0 solution:

/*****************************
   Write a program to check the syntax of a C program
   for matching {} () "" '' []
******************************/
#include <stdio.h>

#define MAXLINE 1000 /* max input line size */
char line[MAXLINE]; /*current input line*/

int getl(void);  /* taken from the KnR book. */


int
main()
{
    int len=0;
    int t=0;
    int brace=0, bracket=0, parenthesis=0;
    int s_quote=1, d_quote=1;
    
    
    while ((len = getl()) > 0 )
    {
        t=0;
        while(t < len)
        {
            if( line[t] == '[')
            {
                brace++;
            }
            if( line[t] == ']')
            {
                brace--;
            }
            if( line[t] == '(')
            {
                parenthesis++;
            }
            if( line[t] == ')')
            {
                parenthesis--;
            }
            if( line[t] == '\'')
            {
                s_quote *= -1;
            }
            if( line[t] == '"')
            {
                d_quote *= -1;
            }
            t++;
        }
    }
    if(d_quote !=1)
        printf ("Mismatching double quote mark\n");
    if(s_quote !=1)
        printf ("Mismatching single quote mark\n");
    if(parenthesis != 0)
        printf ("Mismatching parenthesis\n");
    if(brace != 0)
        printf ("Mismatching brace mark\n");
    if(bracket != 0)
        printf ("Mismatching bracket mark\n");
    if( bracket==0 && brace==0 && parenthesis==0 && s_quote == 1 && d_quote == 1)
        printf ("Syntax appears to be correct.\n");
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
//Category 1 solution:

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 1024

enum
{
    CODE,       /* nothing of the following */
    COMMENT,    /* inside a comment */
    QUOTE1,     /* inside '' */
    QUOTE2      /* inside "" */
};

int main(void)
{
    int ch;
    int state = CODE;
    char stack[MAX_STACK];
    size_t top = 0; /* points to the top of the stack :-) */
    size_t line = 1;
    int error = 0;  /* for ok-message */
    
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            line++;
        }
        
        switch (state)
        {
            case CODE:
                if (ch == '\'')
                {
                    state = QUOTE1;
                }
                else if (ch == '"')
                {
                    state = QUOTE2;
                }
                else if (ch == '/')
                {
                    int second = getchar();
                    
                    if (second == '*')
                    {
                        state = COMMENT;
                    }
                    else
                    {
                        ungetc(second, stdin);
                    }
                }
                else if (ch == '(' || ch == '[' || ch == '{')
                {
                    if (top < MAX_STACK)
                    {
                        stack[top++] = ch;
                    }
                    else
                    {
                        printf("Stack too small!\n");
                        return EXIT_FAILURE; /* exit gracefully :-) */
                    }
                }
                else if (ch == ')' || ch == ']' || ch == '}')
                {
                    if (top == 0) /* found closing brace but stack is empty */
                    {
                        printf("Line %lu: Closing '%c' found without "
                               "counterpart.\n", (unsigned long)line, ch);
                        error = 1;
                    }
                    else
                    {
                        char open = stack[--top];
                        
                        if ((ch == ')' && open != '(') ||
                            (ch == ']' && open != '[') ||
                            (ch == '}' && open != '{'))
                        {
                            printf("Line %lu: Closing '%c' does not match "
                                   "opening '%c'.\n", (unsigned long)line, ch, open);
                            error = 1;
                        }
                    }
                }
                break;
            case COMMENT:
                if (ch == '*')
                {
                    int second = getchar();
                    
                    if (second == '/')
                    {
                        state = CODE;
                    }
                    else
                    {
                        ungetc(second, stdin);
                    }
                }
                break;
            case QUOTE1:
                if (ch == '\\')
                {
                    (void)getchar(); /* an escaped char inside '' throw it away */
                }
                else if (ch == '\'')
                {
                    state = CODE;
                }
                break;
            case QUOTE2:
                if (ch == '\\')
                {
                    (void)getchar(); /* an escaped char inside "" throw it away */
                }
                else if (ch == '"')
                {
                    state = CODE;
                }
                break;
        }
    }
    
    if (state == COMMENT)
    {
        printf("Code ends inside comment!\n");
    }
    else if (state == QUOTE1)
    {
        printf("Code ends inside single quotes!\n");
    }
    else if (state == QUOTE2)
    {
        printf("Code ends inside double quotes!\n");
    }
    else if (top == 0 && error == 0)
    {
        printf("Code seems to be ok.\n");
    }
    if (top > 0) /* still something in the stack */
    {
        size_t i;
        for (i = 0; i < top; i++)
        {
            printf("Opening '%c' found without counterpart.\n", stack[i]);
        }
    }
    
    return 0;
}
//Category 1 version 2 solution:

#include <stdio.h>

#define MAXVAL 1000
#define MAXLINE 1000

typedef struct {
    int top;
    int val[MAXVAL];
    int pos[MAXVAL];
} stackstr;

/* very simple stack push function */
int push(stackstr *stk, int foo, int bar)
{
    if (stk->top == MAXVAL) {
        printf("stack overflow. NOT putting more values on the stack.\n");
        return 1;
    }
    stk->val[stk->top] = foo;
    stk->pos[stk->top] = bar;
    stk->top++;
    
    return 0;
}

/* very simple function to pop values off a stack */
int pop(stackstr *stk, int *foo, int *bar)
{
    if (stk->top == 0) {
        return 1;
    }
    stk->top--;
    *foo = stk->val[stk->top];
    *bar = stk->pos[stk->top];
    
    return 0;
}

/* we go through the input one line at a time, and this function
 * gets the line to test
 */
int getl(char *s, int lim)
{
    int i, c;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        *(s + i) = c;
    
    if (c == '\n')
        *(s + i++) = c;
    *(s + i) = '\0';
    
    return i;
}

void scanline(stackstr *stk, stackstr *errstk, char *s, int len)
{
    int i, c, d, foo;
    static int string = 0, comment = 0, isconst = 0, escape = 0;
    
    for (i = 0; i < len; i++) {
        c = *(s + i);
        
        if (!comment) {
            if (c == '\\') { /* we have an escape */
                /* test for a valid escape sequence */
                if ((d = *(s + ++i)) == '\\' || d == 'n' || d == '0' || d == 'r' || d == '?'
                    || d == 't' || d == '\'' || d == '\"' || d == 'b' || d == 'x') {
                    continue; /* ok, valid escape sequence -- don't bother about it */
                } else {
                    push(errstk, 5, i); /* illigal escape sequence */
                }
            } else if (c == '\"') { /* is it a text string then? */
                if (!string)
                    string = 1;
                else
                    string = 0;
            } else if (c == '\'') { /* is it a constant? */
                if (!isconst)
                    isconst = 1;
                else
                    isconst = 0;
            }
        }
        
        if (!isconst && !string && !comment && c == '/') {
            if ((d = *(s + ++i)) == '*')
                comment = 1;
        } else if (comment && c == '*') {
            if ((d = *(s + ++i)) == '/') {
                comment = 0;
                continue; /* done with the comment stuff -- start over */
            }
        }
        
        /* only bother about ({[ ]})'s that's not in
         * a string, constant or comment
         */
        if (!isconst && !string && !comment) {
            if (c == '(' || c == '{' || c == '[') {
                push(stk, c, 0);
            } else if (c == ']' || c == '}' || c == ')') {
                if (pop(stk, &d, &foo)) {
                    push(errstk, 4, i);
                }
                if (c == ')' && d != '(') {
                    push(stk, d, 0);
                    push(errstk, 1, i);
                } else if (c == ']' && d != '[') {
                    push(stk, d, 0);
                    push(errstk, 2, i);
                } else if (c == '}' && d != '{') {
                    push(stk, d, 0);
                    push(errstk, 3, i);
                }
            }
        }
    }
}


/* print errors on the line (if there were any) */
void print_err(stackstr *errstk, int lineno)
{
    int errno, pos;
    
    /* yes I know... this way the errors come "backwards" :) */
    while (!pop(errstk, &errno, &pos)) {
        printf("on line number %d: ", lineno);
        switch(errno) {
            case 1:
                printf("closing unopened parantheses, column %d\n", pos+1);
                break;
            case 2:
                printf("closing unopened square bracket, column %d\n", pos+1);
                break;
            case 3:
                printf("closing unopened curly braces, column %d\n", pos+1);
                break;
            case 4:
                printf("trying to close unopened block/control structure, column %d\n", pos+1);
                break;
            case 5:
                printf("illigal escape sequence, column %d\n", pos+1);
                break;
            default:
                printf("undeterminable error\n");
                break;
        }
    }
}

int main(void)
{
    stackstr errstk = {0}, stk = {0};
    int c, linenbr = 0, errcount = 0, linelen;
    char line[MAXLINE];
    
    while ((linelen = getl(line, MAXLINE)) > 0) {
        linenbr++;
        scanline(&stk, &errstk, line, linelen);
        if (errstk.top) {
            print_err(&errstk, linenbr);
            errcount++;
        }
    }
    
    if (errcount) 
        printf("%d lines contained error(s)\n", errcount);
    else
        printf("Well, *I* didn't find any syntax errors, but don't take my word for it...:)\n");
    
    return 0;
}