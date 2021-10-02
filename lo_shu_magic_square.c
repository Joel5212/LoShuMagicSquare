#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int sameNumRows(int arr[][3])
// {
//     int rowSum = 0;
//     for (int row = 0; row < 3; row++)
//     {
//         if (row == 0)
//         {
//             rowSum = getRow(arr, row);
//         }
//         else if (rowSum != getRow(arr, row))
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

int getRow(int arr[][3], int row)
{
    int colRow = 0;
    for (int col = 0; col < 3; col++)
    {
        colRow += arr[row][col];
    }
    return colRow;
}

int getCol(int arr[][3], int col)
{
    int colSum = 0;
    for (int row = 0; row < 3; row++)
    {
        colSum += arr[row][col];
    }
    return colSum;
}

int sumDiagonalTopRightToBottomLeft(int arr[][3])
{
    int totalDiagonal;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (row + col == 2)
            {
                totalDiagonal += arr[row][col];
            }
        }
    }
    return totalDiagonal;
}

int sumDiagonalTopLeftToBottomRight(int arr[][3])
{
    int totalDiagonal = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (row == col)
            {
                totalDiagonal += arr[row][col];
            }
        }
    }
    return totalDiagonal;
}

int sameNumAndColumns(int arr[][3])
{
    int totalDiagonal;
    int colSum = 0;
    int rowSum = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            rowSum = getRow(arr, row);
            printf("%d\n", rowSum);
            colSum = getCol(arr, col);
            printf("%d\n", colSum);
            if (rowSum != colSum)
            {
                return 0;
            }
        }
    }
    if (sumDiagonalTopRightToBottomLeft(arr) != colSum || sumDiagonalTopLeftToBottomRight(arr) != colSum)
    {
        return 0;
    }

    return 1;
}

int duplicatesCount(int arr[][3], int val)
{
    int count = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (arr[row][col] == val)
            {
                count++;
            }
        }
    }
    return count;
}

int noDuplicates(int arr[][3])
{

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (duplicatesCount(arr, arr[row][col]) > 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int generateRanNum()
{
    // printf("%d", (rand() % 9) + 1);
    return (rand() % 9) + 1;
}

void main()
{
    srand(time(0));
    int loShuMagicArray[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    int notLoShuMagicArray[3][3] = {{3, 4, 9}, {6, 9, 10}, {3, 2, 1}};

    //#1
    //#Array is a Lo Shu Magic Array
    if (sameNumAndColumns(loShuMagicArray) == 1)
    {
        printf("Array is a Lo Shu Magic Square!!\n");
    }
    else
    {
        printf("Array is not a Lo Shu Magic Square\n");
    }

    //#Array is not a Lo Shu Magic Array
    if (sameNumAndColumns(notLoShuMagicArray) == 1)
    {
        printf("Array is a Lo Shu Magic Square!!\n");
    }
    else
    {
        printf("Array is not a Lo Shu Magic Square\n");
    }

    //#2
    int isLoShuMagicSquare = 0;
    int numLoShuMagicSquares = 0;
    int twoDimRanArray[3][3];
    int row = 0;
    int col = 0;

    while (isLoShuMagicSquare == 0)
    {
        numLoShuMagicSquares++;
        for (row = 0; row < 3; row++)
        {
            for (col = 0; col < 3; col++)
            {
                twoDimRanArray[row][col] = generateRanNum();
                printf("%d ", twoDimRanArray[row][col]);
            }
        }

        if (sameNumAndColumns(twoDimRanArray) == 1)
        {
            printf("Random Array is a Lo Shu Magic Square\n");
            isLoShuMagicSquare = 1;
            printf("Generated and Tested: %d Squares before success\n", numLoShuMagicSquares);
            for (row = 0; row < 3; row++)
            {
                printf("[");
                for (col = 0; col < 3; col++)
                {
                    printf(" %d ", twoDimRanArray[row][col]);
                }
                printf("]\n");
            }
        }
    }
    // int isLoShuMagicSquare = 0;
    // int numLoShuMagicSquares;
    // int twoDimRanArray[3][3];
    // int loShuMagicArray[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    // int notLoShuMagicArray[3][3] = {{3, 4, 9}, {6, 9, 10}, {3, 2, 1}};
    // int singleRow;
    // int singleColumn;
    // int diagonalTopLeftToBottomRight;
    // int diagonalTopRightToBottomLeft;
    // //#1
    // //Lo Shu Array
    // singleRow = sumAllRows(loShuMagicArray) / 3;
    // printf("%d/n", singleRow);
    // singleColumn = sumAllColumns(loShuMagicArray) / 3;
    // printf("%d/n", singleColumn);
    // diagonalTopLeftToBottomRight = sumDiagonalTopLeftToBottomRight(loShuMagicArray);
    // printf("%d/n", diagonalTopLeftToBottomRight);
    // diagonalTopRightToBottomLeft = sumDiagonalTopRightToBottomLeft(loShuMagicArray);
    // printf("%d/n", diagonalTopRightToBottomLeft);

    // if (singleRow == singleColumn && singleColumn == diagonalTopLeftToBottomRight && diagonalTopLeftToBottomRight == diagonalTopRightToBottomLeft)
    // {
    //     printf("Array is a Lo Shu Magic Square!!\n");
    // }
    // else
    // {
    //     printf("Array is not a Lo Shu Magic Square");
    // }

    // //Not a Lo Shu Array
    // singleRow = sumAllRows(notLoShuMagicArray) / 3;
    // printf("%d/n", singleRow);
    // singleColumn = sumAllColumns(notLoShuMagicArray) / 3;
    // printf("%d/n", singleColumn);
    // diagonalTopLeftToBottomRight = sumDiagonalTopLeftToBottomRight(notLuShuMagicArray);
    // printf("%d/n", diagonalTopLeftToBottomRight);
    // diagonalTopRightToBottomLeft = sumDiagonalTopRightToBottomLeft(notLuShuMagicArray);
    // printf("%d/n", diagonalTopRightToBottomLeft);
    // if (singleRow == singleColumn && singleColumn == diagonalTopLeftToBottomRight && diagonalTopLeftToBottomRight == diagonalTopRightToBottomLeft)
    // {
    //     printf("Array is a Lo Shu Magic Square!!\n");
    // }
    // else
    // {
    //     printf("Array is not a Lo Shu Magic Square");
    // }

    // while (isLoShuMagicSquare == 0)
    // {
    //     numLoShuMagicSquares++;
    //     for (int row = 0; row < 3; row++)
    //     {
    //         for (int col = 0; col < 3; col++)
    //         {
    //             twoDimRanArray[row][col] = generateRanNum();
    //         }
    //     }
    //     int totalRows = sumAllRows(twoDimArray);
    //     int totalColumns = sumAllColumns(twoDimArray);
    //     int diagonalTopLeftToBottomRight = sumDiagonalTopLeftToBottomRight(twoDimArray);
    //     int diagonalTopRightToBottomLeft = sumDiagonalTopRightToBottomLeft(twoDimArray);
    //     if (totalRows == totalColumns && totalColumns == diagonalTopLeftToBottomRight && diagonalTopLeftToBottomRight == diagonalTopRightToBottomLeft)
    //     {
    //         isLoShuMagicSquare = 1;
    //         printf("Generated and Tested: %d", numLoShuMagicSquares);
    //     }
    // }
}