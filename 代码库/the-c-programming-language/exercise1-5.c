//This version uses a while loop:
#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;
 
    lower = 0;
    upper = 300;
    step = 20;
 
    printf("C     F\n\n");
    celsius = upper;
    while(celsius >= lower)
    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius - step;
    }
    return 0;
}

//This version uses a for loop:
#include <stdio.h>
 
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;
 
    lower = 0;
    upper = 300;
    step = 20;
 
    printf("C     F\n\n");
    for(celsius = upper; celsius >= lower; celsius = celsius - step)
    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
    }
    return 0;
}

//华氏-摄氏度转换表：
#include <stdio.h>

/* print Fahrenheit-Celsius table */
int
main()
{
    int fahr;
    
    printf("F     C\n\n");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    
    return 0;
}