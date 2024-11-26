#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char you, char computer) {
    // If it's a tie
    if (you == computer)
        return -1;

    // You lose conditions
    if (you == 'S' && computer == 'P')
        return 0;
    else if (you == 'P' && computer == 'S')
        return 1;

    if (you == 'P' && computer == 'Z') 
        return 0;
    else if (you == 'Z' && computer == 'P') 
        return 1;

    if (you == 'S' && computer == 'Z') 
        return 1;
    else if (you == 'Z' && computer == 'S') 
        return 0;
    
    return -1; // Default case, should never be reached.
}

int main() {
    char you, computer;
    int n;
    
    srand(time(NULL));
    n = rand() % 100; // Random number between 0 and 99
    
    // Assign computer's choice based on random number
    if (n < 33) {
        computer = 'S'; // Stone
    } else if (n >= 33 && n < 66) {
        computer = 'P'; // Paper
    } else {
        computer = 'Z'; // Scissors
    }
    
    // Get user input
    printf("Enter Stone for S, Paper for P, Scissors for Z: ");
    scanf(" %c", &you); // Notice the space before %c to skip any leftover newline character

    // Call game function and print result
    int result = game(you, computer);
    if (result == -1) {
        printf("Draw\n");
    } else if (result == 1) {
        printf("You Win\n");
    } else {
        printf("Computer Won\n");
    }
    
    return 0;
}
