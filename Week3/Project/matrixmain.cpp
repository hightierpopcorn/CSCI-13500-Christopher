#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){

    // Function_Start message to terminal
std::cout << "start of the function Print2DArray START!" << std::endl;
    // Body of the function. Do your magic!

    //NESTED LOOP FOR 2d ARRAY
for (int i = 0; i < matrix_local_rows_total; i++){
    std::cout << "[";
    for (int j = 0; j < 3; j++){
            std::cout << matrix_local[i][j];
            if (j < 2){
                std::cout << "|";
            }
        }
        std::cout << "]" << std::endl;
    }

    // Function_End message to terminal
    std::cout << "End of Function Print2DArray, FAREWELL!"<< std::endl;

}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
    {
        // Function_Start message to terminal
    std::cout << "Function MatrixAddition START!" << std::endl;
    // Create a new matrix to store the result
    int result[3][3];

    // Add corresponding elements
    for (int i = 0; i < matrix_one_rows_total; i++){
        for (int j = 0; j < 3; j++){
            result[i][j] = matrix_one[i][j] + matrix_two[i][j];
        }
    }

    // Print the resulting matrix
    for (int i = 0; i < matrix_one_rows_total; i++){
        std::cout << "[";
        for (int j = 0; j < 3; j++){
            std::cout << result[i][j];
            if (j < 2){
                std::cout << "|";
            }
        }
        std::cout << "]" << std::endl;
    }
 // Function_End message to terminal
    std::cout << "End of Function MatrixAddition FAREWELL" << std::endl;

    }

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    // Function_Start message to terminal
    std::cout << "Function TransposeMatrix START!" << std::endl;

    // body of the function
    //pre starting the array
    int result[3][3];
    // display resulting matrix
    for (int i = 0; i < matrix_local_rows_total; i++){
        for (int j = 0; j < 3; j++){
            result[j][i] = matrix_local[i][j];
        } 
    }
    // if the dimension of the resulting matrix doesn't match the print function, you could do it manually here
    // or modify the parameter of the print function so it doesn't cause errors

    // Function_End message to terminal 
    std::cout << "End of Function TransposeMatrix, FAREWELL!" << std::endl;
}
//Needed help on this one -- marked for assistance...
void Determinant(const int matrix_local[][3], const int size){
    // Function_Start message to terminal
    std::cout << "Function Determinant START!" << std::endl;

    // check for valid dimensions
    // body of the function 
    // The determinant is only being calculated for 2x2 and 3x3 matrices
    // in this project, per the spec's scope.
    if (size == 2){
        // 2x2: (a*d) - (b*c)
        // where the matrix looks like:
        // [a b]
        // [c d]
        int det = matrix_local[0][0] * matrix_local[1][1] -
                 matrix_local[0][1] * matrix_local[1][0];

        // print the determinant value on the terminal
        std::cout << "Determinant: " << det << std::endl;
    }
    else if (size == 3){
        // body of the function 
        // 3x3 determinant via cofactor expansion along the first row.
        // Each term multiplies a top-row element by the determinant
        // of the 2x2 matrix that remains after removing its row and column.
        int det = matrix_local[0][0] * (matrix_local[1][1] * matrix_local[2][2] - matrix_local[1][2] * matrix_local[2][1])
                 - matrix_local[0][1] * (matrix_local[1][0] * matrix_local[2][2] - matrix_local[1][2] * matrix_local[2][0])
                 + matrix_local[0][2] * (matrix_local[1][0] * matrix_local[2][1] - matrix_local[1][1] * matrix_local[2][0]);
        //^^ that sucked btw

         std::cout << "Determinant: " << det << std::endl;
    }
    else{
        // Any size outside 2x2 or 3x3 is considered invalid for this project.
        std::cout << "Invalid matrix size for determinant." << std::endl;
    }

    // Function_End message to terminal
    std::cout << "End of Function Determinant, FAREWELL!" << std::endl;
}


void SearchValue(const int matrix_local[][3], const int rows, const int target){
    // Function_Start message to terminal 
    std::cout << "Function SearchValue START!" << std::endl;
    // body of the function
        // found  or not
        // found or nor signifies T or F
        bool found = false;
        // Loop through every element in the matrix, row by row, column by column.
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < 3; j++){
                // Check if the current element matches the target.
                if (matrix_local[i][j] == target){
                    std::cout << "Found " << target << " at [" << i << "]" << "[" << j << "]" << std::endl;
                    found = true;
                }
            }
        }
        if (!found){
        std::cout << target << " was not found!" << std::endl;
        }
    // Function_End message to terminal
    std::cout << "End of Function SearchValue, FAREWELL!" << std::endl;
    }


void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    
    // Function_Start message to terminal
    std::cout << "Function MatrixMultiplication START!" << std::endl;


    // check for valid arrays
    //to match the colummns and rows
    if (cols_a != rows_b){
        std::cout << "Invalid dimensions for matrix multiplication." << std::endl;
        std::cout << "End of Function MatrixMultiplication, FAREWELL!" << std::endl;
        return;
    }
    // Body of the function
    int result[3][3];
    for (int i = 0; i < rows_a; i++){
        for (int j = 0; j < cols_b; j++){
            int sum = 0;
            for (int k = 0; k < cols_a; k++){
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            result[i][j] = sum;
        }
     }
    // Print resulting matrix
    Print2DArray(result, rows_a);
    // Function_End message to terminal
       std::cout << "End of Function MatrixMultiplication, FAREWELL!" << std::endl;
   
}

int main(){
    // Use these two matrices for basic testing.

    int testing_matrix_one[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int testing_matrix_two[3][3] = {
        {12,65,82},
        {83,2,8},
        {10,96,67}
    };


// Not used in this class, but it is nice to know other ways to find the size of primitive array.
// This method below is similar to how you will find the size of vectors (future material)
    // DO NOT USE IN THIS PROJECT FUNCTION, but you could test it yourselves.
    // int size_row_one = std::size(testing_matrix_one);
    // int size_col_one = std::size(testing_matrix_one[0]);


    // This is a way to find the dimensions of an array without hardcoding values.
    // It dynamically reflects the array's actual declared size, so if you change
    // the array dimensions, the calculation updates automatically.
    //
    // How it works:
    //
    // To find the number of ROWS:
    //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4 = 108 bytes
    //   sizeof(testing_matrix_one[0])   = total bytes of one row         = 1*9*4 =  36 bytes
    //   108 / 36 = 3 rows
    
    int size_row_one = sizeof(testing_matrix_one)/sizeof(testing_matrix_one[0]);

    // To find the number of COLUMNS:
    //   sizeof(testing_matrix_one[0])      = total bytes of one row          = 1*9*4 = 36 bytes
    //   sizeof(testing_matrix_one[0][0])   = total bytes of one element(int) = 1*4   =  4 bytes
    //   36 / 4 = 9 cols
    
    int size_col_one = sizeof(testing_matrix_one[0])/sizeof(testing_matrix_one[0][0]);

    std::cout << "row: " << size_row_one<< " col: " << size_col_one<< std::endl << std::endl;

    Print2DArray(testing_matrix_one, size_row_one);

    return 0; 
}