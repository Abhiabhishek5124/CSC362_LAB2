/*
   IO.c Description:
   The "io.c" file contains functions responsible for input, output, and statistics updating in the football game prediction program.
*/
#include "header.h" // Include the header file that contains function prototypes
#include <math.h> // Include the math library for the abs function
#include <stdlib.h> // Include the standard library for additional functions

int getInput(FILE *inputFile, char *homeTeam, int *HTO, int *HTD, int *HTS, int *HTH, int *HTC, char *visitingTeam, int *VTO, int *VTD, int *VTS, int *VTR) {
    // Function to read input data from the file and store it in variables
    // Takes input from the file represented by 'inputFile'
    // Parameters:
    // - homeTeam: Pointer to a character array for the home team name
    // - HTO, HTD, HTS, HTH, HTC: Pointers to integer variables for various home team attributes
    // - visitingTeam: Pointer to a character array for the visiting team name
    // - VTO, VTD, VTS, VTR: Pointers to integer variables for various visiting team attributes
    // Uses fscanf to read data from the file
    // Returns the result of fscanf (number of items read or EOF)
    return fscanf(inputFile, "%19s %d %d %d %d %d %19s %d %d %d %d", homeTeam, HTO, HTD, HTS, HTH, HTC, visitingTeam, VTO, VTD, VTS, VTR);
}

// Function to output the result of a game prediction
void outputResult(char *homeTeam, char *visitingTeam, int difference) {
    // Parameters:
    // - homeTeam: Pointer to a character array for the home team name
    // - visitingTeam: Pointer to a character array for the visiting team name
    // - difference: The score difference between the home and visiting teams

    // Outputs the result based on the value of 'difference':
    // - If 'difference' is positive, home team beats visiting team by 'difference' points
    if (difference > 0) {
        printf("%s beats %s by %d\n", homeTeam, visitingTeam, difference);
    } else if (difference < 0) {
        // - If 'difference' is negative, visiting team beats home team by the absolute value of 'difference' point
        printf("%s beats %s by %d\n", visitingTeam, homeTeam, abs(difference));
    } else {
        // - If 'difference' is zero, home team wins by 1 point
        printf("%s beats %s by 1\n", homeTeam, visitingTeam);
    }
}

// Function to update game statistics
void updateStats(int *totalGames, int *homeWins, double *totalDifference, int difference) {
    // Parameters:
    // - totalGames: Pointer to an integer variable storing the total number of games
    // - homeWins: Pointer to an integer variable storing the total number of home team wins
    // - totalDifference: Pointer to a double variable storing the total score difference
    // - difference: The score difference of the current game
    // Updates the statistics by incrementing 'totalGames', 'homeWins' (if the home team wins or ties),
    // and adds 'difference' to 'totalDifference'

    (*totalGames)++; // Increment the total number of games
    if (difference >= 0) {
        (*homeWins)++; // Increment home team wins if the difference is non-negative
    }
    *totalDifference += difference; // Add the current game's difference to the total difference
}

// Function to calculate and display the summary of game predictions
void summary(int totalGames, int homeWins, double totalDifference) {
    // Parameters:
    // - totalGames: The total number of games predicted
    // - homeWins: The total number of home team wins
    // - totalDifference: The total score difference of all games


    double percentage = ((double)homeWins / totalGames) * 100; // Calculate the percentage of home team wins
    double averageDifference = totalDifference / totalGames; // Calculate the average score difference

    // Output the summary with formatting
    printf("\nPercentage of home team wins is predicted as %.2lf%%\n", percentage);
    printf("Average difference in scores is predicted as %.2lf\n", averageDifference);
}
