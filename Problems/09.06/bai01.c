/* 8_1.c -- Dùng cấu trúc Stack
 * chuyển đổi biểu thức số học từ dạng trung tố sang dạng hậu tố */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
    int top;
    int capacity;
    char* array;
}Stack;

Stack* createStack(unsigned capacity);
void push(Stack* stack, char item);
char pop(Stack* stack);
int priority(char c);
void printStack(Stack* stack);


int main(void)
{
    Stack* stack = createStack(100);
    char* trungto = "((A+B)*(C-D)/E)";
    int n = strlen(trungto);
    char hauto[n];
    int i, j = 0;
    char c, headInfo;

    for (i = 0; i < n; i++)
    {
        c = trungto[i];

        if (isalnum(c) != 0)
            hauto[j++] = c;
        else
        {
            if (c == '(')
                push(stack, c);
            else
            {
                headInfo = stack->array[stack->top];
                if (c == ')')
                {
                    while (headInfo != '(')
                    {
                        headInfo = stack->array[stack->top];
                        if (headInfo != '(')
                            hauto[j++] = headInfo;
                        pop(stack);
                    }
                }
                else
                {
                    while (priority(headInfo) >= priority(c) && stack->top != 0)
                    {
                        headInfo = stack->array[stack->top];
                        if (headInfo != '(')
                            hauto[j++] = headInfo;
                        pop(stack);
                    }
                    push(stack, c);
                }
            }
        }

    }

    printf("Trung tố: ");
    printf("%s\n", trungto);

    printf("Hậu tố: ");
    for (i = 0; i < j; i++)
        printf("%c", hauto[i]);
    putchar('\n');

    return 0;
}

Stack* createStack(unsigned capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(Stack* stack, char item)
{
    if (stack->top == stack->capacity-1)
        return;
    stack->array[++stack->top] = item;
    //printf("%c pushed to stack\n", item);
}

char pop(Stack* stack)
{
    if (stack->top == -1)
        return CHAR_MIN;
    return stack->array[stack->top--];
}

void printStack(Stack* stack)
{
    int i;
    
    printf("Stack:\n");
    for (i = stack->top; i >= 0; i--)
        printf("\t%c\n", stack->array[i]);
}

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}
