#include <stdio.h>
#include <string.h>

#define COMMAND_BUF_LEN 16
#define STACK_BUFF_LEN 100

int buffer[STACK_BUFF_LEN];

void push(int number, int * i)
{
    buffer[*i] = number;
}

int pop(int * i)
{
    int result = buffer[*i];
    *i -= 1;
    return result;
}

int empty(int * i)
{
    return *i == 0;
}

int full(int * i)
{
    return *i == 100;
}

int main(void)
{
    int index, number, retval;
    char command[COMMAND_BUF_LEN];

    retval = scanf("%s %d\n", command, &number);

    index = 0;

    while(retval != EOF){

        if(strncmp(command, "PUSH", COMMAND_BUF_LEN) == 0){
            push(number, &index);
            printf("PUSHED %d\n", number);
        }

        if(strncmp(command, "POP", COMMAND_BUF_LEN) == 0)
            printf("%d\n", pop(&index));

        if(strncmp(command, "EMPTY", COMMAND_BUF_LEN) == 0)
            printf("%s\n", empty(&index) ? "YES" : "NO");

        if(strncmp(command, "FULL", COMMAND_BUF_LEN) == 0)
            printf("%s\n", full(&index) ? "YES" : "NO");

        retval = scanf("%s %d\n", command, &number);
    }

    return 0;
}
