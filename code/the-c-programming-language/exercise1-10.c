/* Exercise 1-10
 * Category 0
 */

#include <stdio.h>
 
int main()
{
    int c, d;
 
    while ( (c=getchar()) != EOF) {
        d = 0;
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            d = 1;
        }
        if (c == '\t') {
            putchar('\\');
            putchar('t');
            d = 1;
        }
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            d = 1;
        }
        if (d == 0)
            putchar(c);        
    }
    return 0;
}

/* Category 1
 * （使用 #define 定义了明显常量，另外通过 switch 语句判断，而不是 category 中的 if 语句）
 */

#include <stdio.h>
 
#define ESC_CHAR '\\'
 
int main(void)
{
  int c;
 
  while((c = getchar()) != EOF)
  {
    switch(c)
    {
      case '\b':
        /* The OS on which I tested this (NT) intercepts \b characters. */
        putchar(ESC_CHAR);
        putchar('b');
        break;
      case '\t':
        putchar(ESC_CHAR);
        putchar('t');
        break;
      case ESC_CHAR:
        putchar(ESC_CHAR);
        putchar(ESC_CHAR);
        break;
      default:
        putchar(c);
        break;
    }
  }
  return 0;
}