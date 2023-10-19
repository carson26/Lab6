#include <stdio.h>

void printMatrix(int matrix[][3], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int matrixA[][3], int matrixB[][3], int rowSize, int colSize) {
    int result[rowSize][colSize];
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    printMatrix(result, rowSize, colSize);
}

void multiplyMatrices(int matrixA[][3], int matrixB[][3], int rowSize, int colSize) {
    int result[rowSize][colSize];
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colSize; k++) {
                result[i][j] += (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }
    printMatrix(result, rowSize, colSize);
    printf("\n");
}

void subtractMatrices(int matrixA[][3], int matrixB[][3], int rowSize, int colSize) {
    int result[rowSize][colSize];
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    printMatrix(result, rowSize, colSize);
    printf("\n");
}

int main() {
    FILE *input_file = fopen("matrix_input.txt", "r");
    char line[100];
    const char *ptr = strchr(line, '\0');
    while(fgets(line, sizeof(line), input_file)) {
        if (ptr != 100) {
            printf("%s ptr: %s", line, ptr);
        }
    }

    int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    fclose(input_file);
    return 0;
}

main();