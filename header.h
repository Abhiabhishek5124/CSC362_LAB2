/*
   Header File Description:
   The "header.h" file contains function prototypes and constants used in the American football prediction program.
   It serves as an interface for sharing declarations across multiple source code files.
*/

#include <stdio.h> // Include the standard input-output library
#include <stdlib.h> // Include the standard library for additional functions
#include <math.h> // Include the math library for the abs function


// Define constants
#define OFFENSIVE_FACTOR 1.15
#define SPECIAL_TEAMS_FACTOR 1.22
#define HOME_FIELD_ADVANTAGE 1.2
#define OVERALL_FACTOR 1.15
#define OFFENSIVE_WEIGHT 0.30
#define DEFENSIVE_WEIGHT 0.24
#define SPECIAL_WEIGHT 0.17
#define HOME_WEIGHT 0.11
#define OVERALL_WEIGHT 0.13

// Function prototypes
int main(); // Declare the main function prototype
int getInput(FILE *inputFile, char *homeTeam, int *HTO, int *HTD, int *HTS, int *HTH, int *HTC, char *visitingTeam, int *VTO, int *VTD, int *VTS, int *VTR); // Declare the getInput function with parameter descriptions
void computeStrengths(int HTO, int HTD, int HTS, int HTH, int HTC, int VTO, int VTD, int VTS, int VTR, double *homeStrength, double *visitingStrength, double *specialTeamsImpact, double *homeFieldAdvantage, double *visitingRoadStrength); // Declare the computeStrengths function
void computeDifference(double homeStrength, double visitingStrength, double specialTeamsImpact, double homeFieldAdvantage, double visitingRoadStrength, int *difference); // Declare the computeDifference function with parameter descriptions
void outputResult(char *homeTeam, char *visitingTeam, int difference); // Declare the outputResult function prototype with parameter descriptions
void updateStats(int *totalGames, int *homeWins, double *totalDifference, int difference); // Declare the updateStats function prototype with parameter descriptions
void summary(int totalGames, int homeWins, double totalDifference); // Declare the summary function prototype with parameter descriptions

