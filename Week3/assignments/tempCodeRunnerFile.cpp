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