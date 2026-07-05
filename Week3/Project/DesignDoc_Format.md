# Program Design Document

## Program Name

matrixmain
## Purpose

This program performs several operations on 2D matrices.

## Inputs

List all inputs the program will receive.

Example:

* Matrix 1 (3×3 integer array)
* Matrix 2 (3×3 integer array)
* Target value for the search function
---

## Outputs

List what the program will display or produce.

Example:

* Printed matrix
* Matrix addition result
* Transposed matrix
* Determinant value
* Search result (found or not found)
* Matrix multiplication result

---

## Variables

| Variable   | Type    | Purpose                                      |
| ---------- | ------- | -------------------------------------------- |
| matrix_one | int[][] | Stores the first matrix                      |
| matrix_two | int[][] | Stores the second matrix                     |
| result     | int[][] | Stores the resulting matrix for operations   |
| i          | int     | Row loop counter                             |
| j          | int     | Column loop counter                          |
| k          | int     | Loop counter for matrix multiplication       |
| sum        | int     | Stores the sum during multiplication         |
| target     | int     | Value being searched for                     |
| found      | bool    | Indicates whether the target value was found |
| size       | int     | Stores the matrix dimension                  |

---

## Key Design Choices

Explain any important decisions you made when designing the program.

Examples:

* Why did you use a loop instead of repeating code?
* Why did you choose a function for a task?
* Why did you use an array/vector instead of separate variables?
* Why did you use an if-else statement instead of a switch statement?

Example:
"I used a loop to process multiple scores because it reduces code duplication and makes the program easier to modify if the number of scores changes."


* I used nested loops to traverse the rows and columns of the matrices because every element must be processed.
---

## Program Steps (Algorithm)

1. Create two 3×3 matrices.
2. Display the matrices.
3. Add the two matrices.
4. Transpose a matrix.
5. Calculate the determinant.
6. earch for a target value.
7. Multiply the two matrices.
8. Display the results of each operation
---

## Functions
Function: Print2DArray()

Purpose: Displays a 2D matrix.

Function: MatrixAddition()

Purpose: Adds two matrices and displays the result.

Function: TransposeMatrix()

Purpose: Swaps rows and columns of a matrix.

Function: Determinant()

Purpose: Calculates the determinant of a 2×2 or 3×3 matrix.

Function: SearchValue()

Purpose: Searches for a value in the matrix and reports whether it was found.

Function: MatrixMultiplication()

Purpose: Multiplies two matrices and displays the resulting matrix.
---

## Sample Input/Output

Input:
Matrix 1
[1|2|3]
[4|5|6]
[7|8|9]

Matrix 2
[12|65|82]
[83|2|8]
[10|96|67]

Target: 5

Output:
Addition:
[13|67|85]
[87|7|14]
[17|104|76]

Search Result:
Found 5 at [1][1]
---

## Testing

### Test Case 1

Input: Two valid 3×3 matrices

Expected Result: Correct addition, transpose, determinant, search, and multiplication.


### AI Overview
I used AI for the [] placements on the output and help properly constructing my nested loops (especially towards later functions as I had some difficulties). I used AI also to understand a bit more of the matrix concept to help better understand what I was doing, giving me ideas on what to put and helping me on my misplaced colon brackets as it is apparent this is an issue I need to fix.

Determinant was the one I struggled the most and I definitley needed help