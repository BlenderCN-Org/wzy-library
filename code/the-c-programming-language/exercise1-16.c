/* (The spec isn't entirely clear. The spec says, 
 * ’Revise the main routine', but the true length 
 * of an input line can only be determined by 
 * modifying getline. So that's what we'll do, 
 * getline will now return the actual length of 
 * the line rather than the number of characters 
 * read into the array passed to it.)
 */

#include <stdio.h>

#define MAXLINE 20

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main(void)
{
    char line[MAXLINE];
    char longest[MAXLINE];
    char temp[MAXLINE];
    int len, max, prevmax, getmore;
    
    max = prevmax = getmore = 0;
    while((len = getline(line, MAXLINE)) > 0)
    {
        if(line[len - 1] != '\n')
        {
            if(getmore == 0)
                copy(temp, line);
            prevmax += len;
            if(max < prevmax)
                max = prevmax;
            getmore = 1;
        }
        else
        {
            if(getmore == 1)
            {
                if(max < prevmax + len)
                {
                    max = prevmax + len;
                    copy(longest, temp);
                    longest[MAXLINE - 2] = '\n';
                }
                getmore = 0;
            }
            
            else if(max < len)
            {
                max = len;
                copy(longest, line);
            }
            prevmax = 0;
        }
    }
    if(max > 0)
    {
        printf("%s", longest);
        printf("len = %d\n", max);
    }
    
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    
    for(i = 0;
        i < lim - 1 && ((c = getchar()) != EOF && c != '\n');
        ++i)
        s[i] = c;
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    else if(c == EOF && i > 0)
    {
        /* gotta do something about no newline preceding EOF */
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
} 

/* 这里有两个 issues：
 *
 * Conflicting types for 'getline'.
 * Too few arguments to function call：
 * 16 行主函数 while 语句，判断语句中参数不足：
 * while((len=getline(line,MAXLINE))>0)
 * 第一个 conflicting types 是因为：getline（）
 * 是在 stdio.h 中定义的标准库程序，如果自己的函数
 * 使用 getline 作为函数名则会报告冲突，所以只需要
 * 简单改下函数名即可。
 */