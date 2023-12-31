// Abhishek Shrestha
// CSC 362 Programming Assignment 2

// Program Description:
// American Football Prediction Program

// This program predicts the outcomes of American football games based on various team strengths.
// It uses attributes like offensive strength, defensive strength, special teams strength, home strength, and crowd noise (home field advantage)
// to calculate the relative strengths of home and visiting teams.
// The program then predicts the score difference between the teams and maintains statistics on the number of games, home team wins, and total score differences.

// Program Structure and Files:
// The program is divided into multiple files:
// - main.c: Contains the main function, handles user input, file operations, and coordinates program flow.
// - compute.c: Includes computational functions for evaluating relative strengths, score differences, and statistics updating.
// - io.c: Manages input/output operations.
// - header.h: Centralizes function prototypes and constants shared across files.


#include "header.h" // Include the header file that contains function prototypes

int main(){
    int totalGames = 0; // Initialize a variable to keep track of the total number of games
    int homeWins = 0; // Initialize a variable to keep track of the total number of home team wins
    double totalDifference = 0; // Initialize a variable to keep track of the total score difference

    char filename[100]; // Declare a character array to store the input filename

    printf("Enter the input filename: "); // Prompt the user to enter the input filename
    scanf("%s", filename); // Read the user's input and store it in the 'filename' array

    FILE *inputFile = fopen(filename, "r"); // Open the specified input file for reading


    if (inputFile == NULL) { // Check if the file couldn't be opened
        printf("Error opening input file.\n"); // Print an error message
        return 1; //Return an error code (1) to indicate a problem
    }

    char homeTeam[20], visitingTeam[20]; // Declare arrays to store team names
    int HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR, difference; // Declare variables for game data
    // HTO: Home Team Offensive Strength
    // HTD: Home Team Defensive Strength
    // HTS: Home Team Special Teams Strength
    // HTH: Home Team Home Strength
    // HTC: Home Team Crowd Noise (Home Field Advantage)
    // VTO: Visiting Team Offensive Strength
    // VTD: Visiting Team Defensive Strength
    // VTS: Visiting Team Special Teams Strength
    // VTR: Visiting Team Road Strength
    // difference: Score Difference between Home and Visiting Teams

    while (getInput(inputFile, homeTeam, &HTO, &HTD, &HTS, &HTH, &HTC, visitingTeam, &VTO, &VTD, &VTS, &VTR) != EOF) {
        // Declare variables to store computed strengths and differences
        double homeStrength, visitingStrength, specialTeamsImpact, homeFieldAdvantage, visitingRoadStrength;

        // Compute the relative strengths of the home and visiting teams
        computeStrengths(HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR, &homeStrength, &visitingStrength, &specialTeamsImpact, &homeFieldAdvantage, &visitingRoadStrength);

        // Calculate the score difference between the home and visiting teams
        computeDifference(homeStrength, visitingStrength, specialTeamsImpact, homeFieldAdvantage, visitingRoadStrength, &difference);

        // Output the result of the game prediction, indicating the winner and score difference
        outputResult(homeTeam, visitingTeam, difference); // Output the result of the game

        // Update game statistics, including the total number of games, home team wins, and total score difference
        updateStats(&totalGames, &homeWins, &totalDifference, difference); // Update game statistics
    }

    fclose(inputFile); // Close the input file
    summary(totalGames, homeWins, totalDifference); // Calculate and display the summary

    return 0; // Return 0 to indicate successful execution
}



//Output of second input file:

//Enter the input filename: football1.txt
//Clemson beats Wake_Forest by 2
//Florida_St beats Virginia_Tech by 11
//Nebraska beats Illinois by 3
//Iowa_St beats TCU by 1
//Georgia beats Kentucky by 19
//Notre_Dame beats Louisville by 4
//Michigan beats Minnesota by 8
//LSU beats Missouri by 4
//Ohio_State beats Maryland by 21
//Oklahoma_St beats Kansas_St by 6
//Texas beats Oklahoma by 3
//USC beats Arizona by 8
//Wisconsin beats Rutgers by 4
//
//Percentage of home team wins is predicted as 69.23%
//Average difference in scores is predicted as 4.23