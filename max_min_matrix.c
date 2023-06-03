

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

typedef struct array_double_int array_double_int;
struct array_double_int
{
    int **data;
    int row;
    int col;
};

/*
 * matrix, represents the elements of the matrix of size N*M.
 */
void funcMatrix(array_double_int matrix)
{
    int rowMax = 0, colIndx = 0;
    int colMin = 0;
    int result = -1;
    for (int row = 0; row < matrix.row; row++)
    {
        rowMax = *matrix.data[row, 0];
        for (int col = 0; col < matrix.col; col++)
        {
            if (rowMax < *matrix.data[row, col])
            {
                rowMax = *matrix.data[row, col];
                colMin = rowMax;
                colIndx = col;
            }
        }
        for (int newRow = 0; newRow < matrix.row; newRow++)
        {
            if (colMin > *matrix.data[newRow, colIndx])
            {
                colMin = *matrix.data[newRow, colIndx];
            }
        }
        if (rowMax == colMin)
        {
            result = rowMax;
            break;
        }
    }

    printf("%d", result);
}

int main()
{
    array_double_int matrix;

    // input for matrix
    scanf("%d", &matrix.row);
    scanf("%d", &matrix.col);
    matrix.data = (int **)malloc(sizeof(int *) * matrix.row);
    for (int idx = 0; idx < matrix.row; idx++)
    {
        matrix.data[idx] = (int *)malloc(sizeof(int) * matrix.col);
        for (int jdx = 0; jdx < matrix.col; jdx++)
        {
            scanf("%d", &matrix.data[idx][jdx]);
        }
    }

    funcMatrix(matrix);
    return 0;
}