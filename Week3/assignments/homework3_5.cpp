
#include <iostream>
#include <vector>
int main(){

//Delete for testing, commented out for less fluff

    /* 
//Task 1

int arr3[3][3] = {};

std::cout<<"Result for 3x3 array" << std::endl;
for (int i = 0; i < 3; i++){
        //to format the bracket alike to the PDF
        std::cout << "[";
    for (int j = 0; j < 3; j++){

        //helps us sets the proper 1 placement
        if (j+i < 3){
            arr3[i][j] = 1;
            }else{
                arr3[i][j] = 0;
            }std::cout << arr3[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "]\n";
    }
//std::cout << std::endl;

int arr6[6][6] = {};

std::cout<<"Result for 6x6 array" << std::endl;
for (int i = 0; i < 6; i++){
    //to format the bracket alike to the PDF
    std::cout << "[";
    for (int j = 0; j < 6; j++){
    
        //helps us sets the proper 1 placement

        if (j+i < 6){
            arr6[i][j] = 1;
            }else{
                arr6[i][j] = 0;
            }   std::cout << arr6[i][j];
                if (j < 5) std::cout << "|";
            
        }
        std::cout << "]\n";
    }

//Task 2

int arr3update[3][3] = {};

std::cout<<"Result for 3x3 cross X" << std::endl;
for (int i = 0; i < 3; i++){
        //to format the bracket alike to the PDF
        std::cout << "[";
    for (int j = 0; j < 3; j++){

        //helps us sets the proper 1 placement for diagonal
        if  (i == j || i + j == 2){
            arr3update[i][j] = 1;
            }else{
                arr3update[i][j] = 0;
            }std::cout << arr3update[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "]\n";
    }


int arr6update[6][6] = {};

std::cout<<"Result for 6x6 cross X" << std::endl;
for (int i = 0; i < 6; i++){
    //to format the bracket alike to the PDF
    std::cout << "[";
    for (int j = 0; j < 6; j++){
    
        //helps us sets the proper 1 placement

        if (i == j || i + j == 5){
            arr6update[i][j] = 1;
            }else{
                arr6update[i][j] = 0;
            }   std::cout << arr6update[i][j];
                if (j < 5) std::cout << "|";
            
        }
        std::cout << "]\n";
    }

//Delete for testing, commented out for less fluff
    */

    // Task 3
//presents the array
std::vector<std::vector<int>> matrix = {
    {10, 20, 30},
    {5, 15, 25},
    {35, 45, 55}
};
//creates the results of the sum
std::vector<std::vector<int>> sums(2, std::vector<int>(3, 0));

//for loop to sum up the rows
for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        sums[0][i] += matrix[i][j];
//sums up the collumns
for (int j = 0; j < 3; j++)
    for (int i = 0; i < 3; i++)
        sums[1][j] += matrix[i][j];
//prints the results
for (int i = 0; i < 2; i++){
    std::cout << "[";
    for (int j = 0; j < 3; j++){
        std::cout << sums[i][j];
        if (j < 2) std::cout << "|";
    }
    std::cout << "]\n";
}

//Task 4
//to set the values to add up
int spid1 = 0;
int spid2 = 0;
//adds the diagonals
for (int i=0; i < 3; i++){
    spid1 +=matrix[i][i];
    spid2 +=matrix[i][2-i];
}
//the center gets counted twice once in each diagonal so subtracting it once brings it back to being counted just once
int center = matrix[1][1];
int S = spid1 + spid2 - center;

std::cout << "d1 = " << spid1 << "\n";
std::cout << "d2 = " << spid2 << "\n";
std::cout << "c = " << center << "\n";
std::cout << "S = " << S << "\n";

return 0;
}
