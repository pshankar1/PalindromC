#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* s;
int tLayer = -1;
  
/*************
push()
will input values onto stack 
checks length of stack size and layers it
until length is fulfilled
****************/
void push(char val)
{
    s[++tLayer] = val;
}
  
/****************
Pop()
Removes values from top of the stack   
When stack has elements it will take off the top 
and adjust the length of the stack by -1 
 and readjust values to new length value/stack
***************/
char pop()
{
    return s[tLayer--];
}


/*********
palindrome()
shows if value is palindrome of character
Finding the middle values (p) and setting it to half 
the size of the stack and pushes palindrome to value
and if there is no even size there is no middle so it disregards
any middle value
checks if strings are equal 
******/
int palindrome(char e[])
{
    int size = strlen(e);
      s = (char*)malloc(size * sizeof(char));
      int i, p = size / 2;
    for (i = 0; i < p; i++) {
        push(e[i]);
    }
  
    if (size % 2 != 0) {
        i++;
    }
      while (e[i] != '\0') {
        char val = pop();
        if (val != e[i])
            return 0;
        i++;
    }
  
    return 1;
}
  //saippuakivikauppias IS A PALINDROME I PROMISE GOOGLE IT
int main()
{
    char e[] = "saippuakivikauppias";
  
    if (palindrome(e)) {
        printf("The Word is a Palindrome");
    }else {
        printf("The Word is NOT a Palindrome");
    }
  
    return 0;
}