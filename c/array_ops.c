// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* only used in string related operations */
typedef struct String string;
struct String
{
    char *str;
};

char *input(FILE *fp, int size, int has_space)
{
    int actual_size = 0;
    char *str = (char *)malloc(sizeof(char) * (size + actual_size));
    char ch;
    if (has_space == 1)
    {
        while (EOF != (ch = fgetc(fp)) && ch != '\n')
        {
            str[actual_size] = ch;
            actual_size++;
            if (actual_size >= size)
            {
                str = (char *)realloc(str, sizeof(char) * actual_size);
            }
        }
    }
    else
    {
        while (EOF != (ch = fgetc(fp)) && ch != '\n' && ch != ' ')
        {
            str[actual_size] = ch;
            actual_size++;
            if (actual_size >= size)
            {
                str = (char *)realloc(str, sizeof(char) * actual_size);
            }
        }
    }
    actual_size++;
    str = (char *)realloc(str, sizeof(char) * actual_size);
    str[actual_size - 1] = '\0';
    return str;
}
/* only used in string related operations */

typedef struct array_single_int array_single_int;
struct array_single_int
{
    int *data;
    int size;
};

/*
 * inputArr, represents the given array of element of size inputArr_size.
 */
void funcTwins(array_single_int inputArr)
{
    for (int i = 0; i < inputArr.size; i++)
    {
        if (inputArr.data[i] != inputArr.data[i + 1])
        {
            printf("%d", i); // print position of non twin pair
            return;
        }
        i++;
    }

    printf("%d", -1);
}

int main()
{
    array_single_int inputArr;

    // input for inputArr
    scanf("%d", &inputArr.size);
    inputArr.data = (int *)malloc(sizeof(int) * inputArr.size);
    for (int idx = 0; idx < inputArr.size; idx++)
    {
        scanf("%d", &inputArr.data[idx]);
    }

    funcTwins(inputArr);
    return 0;
}