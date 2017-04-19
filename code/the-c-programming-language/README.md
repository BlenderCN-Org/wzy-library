##C Programming Language 2nd 习题代码

习题代码（不全，而且很多 issues）


- [Exercise 1-4](exercise1-4.c) Write a program to print the corresponding Celsius to Fahrenheit table.
- [Exercise 1-5](exercise1-5.c) Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
- [Exercise 1-6](exercise1-6.c) Verify that the expression `getchar( ) != EOF` is 0 or 1.
- [Exercise 1-7](exercise1-7.c) Write a program to print the value of EOF.
- [Exercise 1-8](exercise1-8.c) Write a program to count blanks, tabs, and newlines.
- [Exercise 1-9](exercise1-9.c) Write a program to copy this input to its output, replacing each string of one or more blanks by a single blank.
- [Exercise 1-10](exercise1-10.c) Write a program to copy its input to its output, replacing each tab by `\t` , each backspace by `\b` , and each backslash by `\\` . This makes tabs and backspaces visible in an unambiguous way.

[Exercise 1-11](exercise1-11.c)
How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
The programmers should learn how to do a unit test, as following:

0. input file contains zero words
1. input file contains 1 enormous word without any newlines
2. input file contains all white space without newlines
3. input file contains 66000 newlines
4. input file contains word/{huge sequence of whitespace of different kinds}/word
5. input file contains 66000 single letter words, 66 to the line
6. input file contains 66000 words without any newlines
7. input file is /usr/dict contents (or equivalent)
8. input file is full collection of moby words
9. input file is binary (e.g. its own executable)
10. input file is /dev/nul (or equivalent)

66000 is chosen to check for integral overflow（常量溢出） on small integer machines.

- [Exercise 1-12](exercise1-12.c) Write a program that prints its input one word per line.
- [Exercise 1-13](exercise1-13.c) Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
- [Exercise 1-14](exercise1-14.c) Write a program to print a histogram of the frequencies of different characters in its input.
- [Exercise 1-15](exercise1-15.c) Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
- [Exercise 1-16](exercise1-16.c) Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.
- [Exercise 1-17](exercise1-17.c) Write a program to print all input lines that are longer than 80 characters.
- [Exercise 1-18](exercise1-18.c) Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines.
- [Exercise 1-19](exercise1-19.c) Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
- [Exercise 1-20](exercise1-20.c) Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
- [Exercise 1-21](exercise1-21.c) Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. Use the same stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
- [Exercise 1-22](exercise1-22.c) Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n -th column of input. Make sure  your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
- [Exercise 1-24](exercise1-24.c) Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments.
- [Exercise 2-1](exercise2-1.c) Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
- [Exercise 2-2](exercise2-2.c) Exercise 2-2 discusses a for loop from the text. Here it is: `for ( i=0; i<lim-1 && (c=getchar( ) != '\n' && c != EOF; ++i ) s[ i ] = c;` Write a loop equivalent to the for loop above without using `&&` or `||`.
- [Exercise 2-3](exercise2-3.c) Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
- [Exercise 2-4](exercise2-4.c) Write an alternate version of squeeze(s1, s2) that deletes each character in the string s1 that matches any character in the string s2.
- [Exercise 2-5](exercise2-5.c) Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no character from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)