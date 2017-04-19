#include <stdio.h>
#include <limits.h>

int
main ()
{
    printf("Size of Char %d\n", CHAR_BIT);
    printf("Size of Char Max %d\n", CHAR_MAX);
    printf("Size of Char Min %d\n", CHAR_MIN);
    printf("Size of int min %d\n", INT_MIN);
    printf("Size of int max %d\n", INT_MAX);
    printf("Size of long min %ld\n", LONG_MIN);       /* RB */
    printf("Size of long max %ld\n", LONG_MAX);       /* RB */
    printf("Size of short min %d\n", SHRT_MIN);
    printf("Size of short max %d\n", SHRT_MAX);
    printf("Size of unsigned char %u\n", UCHAR_MAX);  /* SF */
    printf("Size of unsigned long %lu\n", ULONG_MAX); /* RB */
    printf("Size of unsigned int %u\n", UINT_MAX);    /* RB */
    printf("Size of unsigned short %u\n", USHRT_MAX); /* SF */
    
    return 0;
}

/****************** Output ***********************************/
Size of Char 8
Size of Char Max 127
Size of Char Min -128
Size of int min -2147483648
Size of int max 2147483647
Size of long min -9223372036854775808
Size of long max 9223372036854775807
Size of short min -32768
Size of short max 32767
Size of unsigned char 255
Size of unsigned long 18446744073709551615
Size of unsigned int 4294967295
Size of unsigned short 65535