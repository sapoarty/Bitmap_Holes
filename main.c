#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **get_matrix(char *strArr[], int widht, int height)
{
    int x, y;
    int **matrix;

    matrix = (int**) malloc(sizeof(int*) * widht);
    for (x = 0; x < widht; x++)
    {
        matrix[x] = (int*) malloc(sizeof(int) * widht);
    }

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < widht; x++)
        {
            matrix[x][y] = *(strArr[y] + x) - '0';
        }
    }
    return (matrix);
}

void fill_region(int **matrix, int x, int y, int width, int height)
{
    if (x + 1 < width && matrix[x + 1][y] == 0)
    {
        matrix[x + 1][y] = 1;
        fill_region(matrix, x + 1, y, width, height);
    }
    else if (x - 1 >= 0 && matrix[x - 1][y] == 0)
    {
        matrix[x - 1][y] = 1;
        fill_region(matrix, x - 1, y, width, height);
    }
    else if (y + 1 < height && matrix[x][y + 1] == 0)
    {
        matrix[x][y + 1] = 1;
        fill_region(matrix, x, y + 1, width, height);
    }
    else if (y - 1 >= 0 && matrix[x][y - 1] == 0)
    {
        matrix[x][y - 1] = 1;
        fill_region(matrix, x, y - 1, width, height);
    }
    else
    {
        matrix[x][y] = 1;
        return;
    }
}

void BitmapHoles(char * strArr[], int arrLength) {
    int **matrix;
    int width;
    int x, y;
    int region_num;

    region_num = 0;
    width = strlen(strArr[0]);

    matrix = get_matrix(strArr, width, arrLength);
    for (y = 0; y < arrLength; y++)
    {
        for (x = 0; x < width; x++)
        {
            if (matrix[x][y] == 0)
            {
                fill_region(matrix, x, y, width, arrLength);
                region_num++;
            }
        }
    }
    printf("%d", region_num);

}

int main(void) {

    // keep this function call here
    char * A[] = {"01111", "01101", "00011", "11110"} ;
    int arrLength = sizeof(A) / sizeof(*A);
    BitmapHoles(A, arrLength);
    return 0;

}