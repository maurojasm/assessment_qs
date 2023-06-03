
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
                str = realloc(str, sizeof(char) * actual_size);
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
                str = realloc(str, sizeof(char) * actual_size);
            }
        }
    }
    actual_size++;
    str = realloc(str, sizeof(char) * actual_size);
    str[actual_size - 1] = '\0';
    return str;
}
/* only used in string related operations */

typedef struct array_single_string array_single_string;
struct array_single_string
{
    string *data;
    int size;
};

/*
 * inputStr, represents the given string containing substring of latitude/longitude pairs.
 */
array_single_string funcValidPairs(array_single_string inputStr)
{
    array_single_string answer;
    char invalid[8] = "Invalid";
    char valid[6] = "Valid";
    int commaIndx = 0;

    for (int coordIndx = 0; coordIndx < inputStr.size; coordIndx++)
    {
        string coord = inputStr.data[coordIndx];
        for (int i = 0; i < strlen(coord.str); i++)
        {
            if (coord.str[i] == ',')
            {
                commaIndx = i;
            }
        }
        if (coord.str[0] != '(' || coord.str[strlen(coord.str) - 1] != ')')
        {
            answer.data[coordIndx].str = invalid;
        }
        else if (coord.str[1] == ' ' || coord.str[strlen(coord.str) - 2] == ' ')
        {
            answer.data[coordIndx].str = invalid;
        }
        else if (coord.str[commaIndx - 1] == ' ' || coord.str[commaIndx + 1] == ' ')
        {
            answer.data[coordIndx].str = invalid;
        }
        else if (coord.str[1] == '0' || coord.str[commaIndx + 1] != '0')
        {
            answer.data[coordIndx].str = invalid;
        }
        else if (coord.str[1] == '+' || coord.str[1] == '-')
        {
            answer.data[coordIndx].str = valid;
        }
        else if (coord.str[commaIndx + 1] == '+' || coord.str[commaIndx + 1] == '-')
        {
            answer.data[coordIndx].str = valid;
        }
        else
        {
            answer.data[coordIndx].str = valid;
        }
    }

    return answer;
}

int main()
{
    array_single_string inputStr;

    // input for inputStr
    scanf("%d", &inputStr.size);
    inputStr.data = (string *)malloc(sizeof(string) * inputStr.size);
    for (int idx = 0; idx < inputStr.size; idx++)
    {
        inputStr.data[idx].str = input(stdin, 100, 0);
    }

    array_single_string result = funcValidPairs(inputStr);
    for (int idx = 0; idx < result.size - 1; idx++)
    {
        printf("%s ", result.data[idx].str);
    }
    printf("%s", result.data[result.size - 1].str);

    return 0;
}