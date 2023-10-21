#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;
void readMatrixFromFile(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize);
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;

    std::cout << "Carson Abbott" << std::endl << "Lab #6: Matrix Manipulation" << std::endl;
    readMatrixFromFile(matrixA, matrixB, size, "matrix_input.txt");
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size, size);
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    addMatrices(matrixA, matrixB, result, size, size);
    std::cout << "Matrix Prdouct (A * B):" << std::endl;
    multiplyMatrices(matrixA, matrixB, result, size, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    subtractMatrices(matrixA, matrixB, result, size, size);

    return 0;
}

void readMatrixFromFile(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename) {
    std::ifstream MyFile(filename); // Opens the file
    if (!MyFile) { // If the file cannot be opened
        std::cerr << "Error opening file: " << filename << std::endl; // Then throw an error
        exit(1); // Exit the program with a value of 1
    }
    MyFile >> size; // Stores the first character read in the size variable
    for (int i = 0; i < size; i++) { // Loops through the next character. Starting at Line 2 and ending at Line 4.
        for (int j = 0; j < size; j++) {
            MyFile >> matrix1[i][j]; // Assigns the current character to it's corresponding spot in matrix1. This also edits matrixA in main() because they share the same address.
        }
    }

    for (int i = 0; i < size; i++) { // Loops through the next character. Starting at Line 5 and ending at Line 7.
        for (int j = 0; j < size; j++) {
            MyFile >> matrix2[i][j];
        }
    }
    MyFile.close();
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    printMatrix(resultMatrix, rowSize, colSize);
    std::cout << std::endl;
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < colSize; k++) {
                resultMatrix[i][j] += (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }
    printMatrix(resultMatrix, rowSize, colSize);
    std::cout << std::endl;
}

void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    printMatrix(resultMatrix, rowSize, colSize);
    std::cout << std::endl;
}
