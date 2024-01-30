#include <iostream>
#include <ctime>
#include <cstdlib>

// Enum to represent the three choices in the game
enum class Choice { ROCK, PAPER, SCISSORS };

// Function to get the computer's random choice
Choice getComputerChoice() {
    int randomChoice = rand() % 3;
    return static_cast<Choice>(randomChoice);
}

// Function to display the choices
void displayChoices(Choice player, Choice computer) {
    std::cout << "Your choice: ";
    switch (player) {
        case Choice::ROCK:
            std::cout << "Rock";
            break;
        case Choice::PAPER:
            std::cout << "Paper";
            break;
        case Choice::SCISSORS:
            std::cout << "Scissors";
            break;
    }

    std::cout << "\nComputer's choice: ";
    switch (computer) {
        case Choice::ROCK:
            std::cout << "Rock";
            break;
        case Choice::PAPER:
            std::cout << "Paper";
            break;
        case Choice::SCISSORS:
            std::cout << "Scissors";
            break;
    }

    std::cout << "\n";
}

// Function to determine the winner
void determineWinner(Choice player, Choice computer) {
    if (player == computer) {
        std::cout << "It's a tie!\n";
    } else if (
        (player == Choice::ROCK && computer == Choice::SCISSORS) ||
        (player == Choice::PAPER && computer == Choice::ROCK) ||
        (player == Choice::SCISSORS && computer == Choice::PAPER)
    ) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random choice

    // Game loop
    while (true) {
        std::cout << "\nRock, Paper, Scissors Game\n";
        std::cout << "1. Rock\n2. Paper\n3. Scissors\n4. Quit\n";
        std::cout << "Enter your choice (1-4): ";

        int choice;
        std::cin >> choice;

        if (choice == 4) {
            std::cout << "Goodbye!\n";
            break; // Exit the game
        }

        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please try again.\n";
            continue; // Ask for a valid choice
        }

        // Convert player's choice to enum
        Choice playerChoice = static_cast<Choice>(choice - 1);

        // Get computer's choice
        Choice computerChoice = getComputerChoice();

        // Display choices
        displayChoices(playerChoice, computerChoice);

        // Determine the winner
        determineWinner(playerChoice, computerChoice);
    }

    return 0;
}
