#include <iostream>
#include <random>
#include <cstdlib> // needed for rand()


int main(){
    // start game (declare variables)
    int player_score = 0;
    int bot_score = 0;
    std::string player_move = "";
    int bot_move = 0;
    std::string bot_pick = ""; 
    //personalization
    std::string name;
    //start of game / intro; More user friendly
    std::cout << "*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*\n";
    std::cout << "Let's play Rock, Paper Scissors!\n";
    std::cout << "*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*\n";

    std::cout << "What's your player name?; ";
    std::cin >> name;
    
    std::cout << "Welcome! " << name << " Let's play!\n";

    // game loop
    for (int rounds = 0; rounds < 3; rounds++){
    // check for early winner 
    if (player_score >= 2 || bot_score >= 2){
        break;
        } 
    
    // ask for user input 
    std::cout << "Choose rock, paper or scissor: ";
    std::cin >> player_move;
    //To remove the case sensitive 
    for (int i = 0; i < player_move.size(); i++){
    player_move[i] = tolower(player_move[i]);
    }    

    //input validation       
    while (player_move != "rock" && player_move != "paper" && player_move != "scissor"){
    std::cout << "Invalid input. Please enter rock, paper, or scissor: ";
    std::cin >> player_move;
    //To remove case sensitive
    for (int i = 0; i < player_move.size(); i++){
    player_move[i] = tolower(player_move[i]);
    }
      
    }

    
    // generate bot input 
    bot_move = rand() % 3;

    //edited for the case sensitivity format
    if (bot_move == 0){
        bot_pick = "rock";
    }
    else if (bot_move == 1){
        bot_pick = "paper";
    } else {
        bot_pick = "scissor";
    }
    // tells you the bots option, no more anonymous options
    std::cout << "Bot chose: " << bot_pick << std::endl;
    // figure out the score 
    if (player_move == bot_pick){
        //better for tie?
        std::cout << "tie game!" << std::endl;
        player_score += 0;
        bot_score += 0;
    }
    else if (player_move == "rock"  && bot_pick == "scissor"){
        //update
        std::cout << name << " wins this round!\n" ;
        player_score++;
        }
    else if (player_move == "paper" && bot_pick == "rock"){
        std::cout << name << " wins this round!\n" ;
        player_score++;
        }
    else if (player_move == "scissor" && bot_pick == "paper"){
        std::cout << name << " wins this round!\n" ;
            player_score++;
        }
    else{
        std::cout << "Bot wins this round!\n" ;
            bot_score++;
        }
    std::cout << "The score is\n" << name << ": " << player_score << std::endl;
    std::cout << "Robot? It got: " << bot_score << std::endl; 
    } // end loops bracket, added cause i was losing my mind messing up over and ove again


    // Declare winner or tie
    if (player_score > bot_score){
        std::cout << name << " wins! LETS GOOOO" << std::endl;
    }
    else if (bot_score > player_score){
        std::cout << "Bot wins! lol AI takeover" << std::endl;
    }
    else{
        std::cout << "Tie!" << std::endl;
    }
    
    return 0;
}