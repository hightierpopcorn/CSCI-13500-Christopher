
#include <iostream>
int main (){

    int c;
    int d;
    char op;
    int results;

    std::cout << "Enter first number: " ;
    std::cin >> c;

    std::cout << "Enter second number: ";
    std::cin >> d;

    std::cout << "Choose operation (+, -, *, /, %): ";
    std::cin >> op;

    if (op == '+'){
        results = c + d;
    }
    else if (op == '-'){
        results = c - d;
    }

    else if (op == '%'){
        results = c % d;
    }

    else if (op == '*'){
        results = c * d;
    }
    
    else if (op == '/'){
        if (d == 0){
            std::cout << "Error, can't divide by 0!" ;
        } else { 
            results = c / d;
        }
    } else {
        std::cout <<"Error, not a correct operator! ";
    }

   std::cout << "Result: " << results << std::endl;



    return 0;
}
