/*
   Header File Description:
   The "header.h" file contains function prototypes and constants used in the American football prediction program.
   It serves as an interface for sharing declarations across multiple source code files.
*/

#include <stdio.h> // Include the standard input-output library

// Function prototypes
int main(); // Declare the main function prototype
int getInput(FILE *inputFile, char *homeTeam, int *HTO, int *HTD, int *HTS, int *HTH, int *HTC, char *visitingTeam, int *VTO, int *VTD, int *VTS, int *VTR); // Declare the getInput function prototype with parameter descriptions
void computeStrengthsAndDifference(int HTO, int HTD, int HTS, int HTH, int HTC, int VTO, int VTD, int VTS, int VTR, int *difference); // Declare the computeStrengthsAndDifference function prototype with parameter descriptions
void outputResult(char *homeTeam, char *visitingTeam, int difference); // Declare the outputResult function prototype with parameter descriptions
void updateStats(int *totalGames, int *homeWins, double *totalDifference, int difference); // Declare the updateStats function prototype with parameter descriptions
void summary(int totalGames, int homeWins, double totalDifference); // Declare the summary function prototype with parameter descriptions

