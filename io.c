/*
   IO.c Description:
   The "io.c" file contains functions responsible for input and output
*/
#include "header.h" // Include the header file that contains function prototypes

int getInput(FILE *inputFile, char *homeTeam, int *HTO, int *HTD, int *HTS, int *HTH, int *HTC, char *visitingTeam, int *VTO, int *VTD, int *VTS, int *VTR) {
    // Function to read input data from the file and store it in variables
    // Takes input from the file represented by 'inputFile'
    // Parameters:
    // - homeTeam: Pointer to a character array for the home team name
    // - HTO, HTD, HTS, HTH, HTC: Pointers to integer variables for various home team attributes
    // - visitingTeam: Pointer to a character array for the visiting team name
    // - VTO, VTD, VTS, VTR: Pointers to integer variables for various visiting team attributes
    // Uses fscanf to read data from the file
    // Returns the result of fscanf
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
