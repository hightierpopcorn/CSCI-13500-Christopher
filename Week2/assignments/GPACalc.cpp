//Christopher Dorsainvil
#include <iostream>
// for to upper for the case
#include <cctype>
//for rounding
#include <iomanip>


int main() {

    std::string creditGrade;
    int counter = 0;
    double score = 0;
    int finalCredits = 0;
    double finalPoints = 0;



    // Helps continue for the counter
    while (true){
   // for user input
    std::cout << "Please enter Class & Grades, (Must be less than 10 credits)  or enter quit to exit:" ;
    std::cin >> creditGrade; 
    // ends program if user enters quit
    if (creditGrade == "quit"){
            break;
        }

    //parses the string in order to extract the 2 variables.
      int credits = creditGrade[0] - '0';
      std::string grade = creditGrade.substr(1); 
        // Checks if less than 10
      if (credits < 1 || credits > 9) {
      std::cout << "Invalid credits\n";
      continue;
}

      for (int i = 0; i < grade.size(); i++){
      grade[i] = toupper(grade[i]);
}
    
    // transitions the Grade score properly
        if (grade == "A+"){
            score = 4.0;
        }
        else if (grade == "A"){
            score = 4.0;
        }
        else if (grade == "A-"){
            score = 3.7;
        }
        else if (grade == "B+"){
            score = 3.3;
        }
        else if (grade == "B"){
            score = 3.0;
        }
        else if (grade == "B-"){
            score = 2.7;
        }
        else if (grade == "C+"){
            score = 2.3;
        }
        else if (grade == "C"){
            score = 2.0;
        }
        else if (grade == "D"){
            score = 1.0;
        }
        else if (grade == "F" || grade == "WU" || grade == "FIN" || grade == "FAB"){
            score = 0.0;
        } else {
            std::cout << "Invalid grade\n";
            continue;
        }
        // calculates for the GPA
        finalCredits += credits;
        finalPoints += credits * score;
        double gpa = finalPoints / finalCredits;
   
        // counts
        counter++;
        std::cout << "Classes taken: " << counter  << ", Semester GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;

       


}

return 0;
}