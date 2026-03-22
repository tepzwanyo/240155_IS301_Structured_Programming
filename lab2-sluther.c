/*
Name: Sandrick Luther
Student ID: 240155
Date: 21/03/2024
Program: Guessing Game using Functions, Selection & Loop
Algorithm: The program generates a random number between 1 and 20, allows the user up to five attempts to guess it by comparing each input and giving feedback whether it is too high or too low, stops immediately if the correct number is guessed, and displays the correct number with a failure message if all attempts are used without success
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int getGuess();
void printSuccess();
void printHint(int guess, int number);
void printSorry(int number);

int main() {
    int number, guess;
    int i;

    // Generate random number
    srand(time(0));
    number = rand() % 20 + 1;

    printf("I am thinking of a number between 1 and 20.\n");

    // Loop for 5 attempts
    for(i = 1; i <= 5; i++) {
        guess = getGuess();

        if(guess == number) {
            printSuccess();
            return 0; // terminate immediately
        } else {
            printHint(guess, number);
        }
    }

    // If user fails after 5 tries
    printSorry(number);

    return 0;
}

// Function to get user guess
int getGuess() {
    int guess;
    printf("Can you guess what it is? ");
    scanf("%d", &guess);
    return guess;
}

// Function to print success message
void printSuccess() {
    printf("Congratulations! You did it.\n");
}

// Function to print hints
void printHint(int guess, int number) {
    if(guess < number) {
        printf("Your guess is low. Try again.\n");
    } else {
        printf("Your guess is high. Try again.\n");
    }
}

// Function to print failure message
void printSorry(int number) {
    printf("Sorry. The number was %d.\n", number);
    printf("You should have gotten it by now.\n");
    printf("Better luck next time.\n");
}