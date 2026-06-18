# Program Design Document

## Program Name

Rock, Paper, Scissors Game Improvement
## Purpose

Briefly explain what the program does and what problem it solves.

---

## Inputs

List all inputs the program will receive.

Example:
* Welcome message with player name
* Bot’s chosen move
* Round result (win, lose, or tie)
* Updated score after each round
* Final game winner
---

## Outputs

List what the program will display or produce.

Example:

* Welcome message with player name
* Bot’s chosen move
* Round result (win, lose, or tie)
* Updated score after each round
* Final game winner

---

## Variables

| Variable     | Type   | Purpose                              |
| ------------ | ------ | ------------------------------------ |
| player_score | int    | Stores the player's score            |
| bot_score    | int    | Stores the bot's score               |
| player_move  | string | Stores the player's input            |
| bot_move     | int    | Stores random number for bot choice  |
| bot_pick     | string | Stores bot's move                    |
| name         | string | Stores player's name                 |
| rounds       | int    | Controls the number of rounds played |
---

## Key Design Choices

Explain any important decisions you made when designing the program.

* I used tolower() to convert user input to lowercase so the program is not case-sensitive and improves user experience.
* I added player name personalization to make the game more engaging.
* I displayed the bot’s move and round results to improve UI/UX and make the game clearer and more interactive.
* Why did you use an if-else statement instead of a switch statement?


---

## Program Steps (Algorithm)

1. Display a welcome message
2. Ask the user for their name
3. Start a loop for up to 3 rounds
4. Check if either player has already won 2 rounds
5. Ask the user for their move
6. Convert input to lowercase
7. Validate the input
8. Generate a random bot move
9. Display the bot’s move
10. Compare moves and determine the round winner
11. Update scores
12. Display round result and updated score
13. Repeat until the game ends
14. Display the final winner

---

## Functions

n/a
## Sample Input/Output

Input:
Name: Chris
Move: rock

Output:
Welcome Chris! Let's play!
Bot chose: paper
Bot wins this round!

---

## Testing

### Test Case 1
Input: rock, paper, scissor
Expected Result: Correct winner determined each round

### Test Case 2

Input: invalid input (scissors)
Expected Result: Program asks user to re-enter input

### Test Case 3

Input: uppercase input (ROCK)
Expected Result: Program correctly processes input due to case conversion