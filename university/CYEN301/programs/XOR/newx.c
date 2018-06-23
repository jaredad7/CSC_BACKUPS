#include <stdio.h>
 
int xor (int x, int y);
 
int main()
{
    int x;
    int y;
    printf ("Please enter the first number you'd like to XOR:\n");
    scanf ("%x", &x);
    getchar();
    printf ("Please enter the second number you'd like to XOR:\n");
    scanf ("%x", &y);
    getchar();
    printf ("The XOR value of the 2 numbers is: %x\n" ,xor (x,y));
    getchar();
}
 
int xor (int x, int y)
{
    return x ^ y;
}
