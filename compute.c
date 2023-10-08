/*
   Compute.c Description:
   The "compute.c" file contains the core computation functions for computing strengths, differences and updating game statistics
*/
 #include "header.h" // Include the header file that contains function prototypes

// Function to compute relative strengths
void computeStrengths(int HTO, int HTD, int HTS, int HTH, int HTC, int VTO, int VTD, int VTS, int VTR, double *homeStrength, double *visitingStrength, double *specialTeamsImpact, double *homeFieldAdvantage, double *visitingRoadStrength) {
    *homeStrength = HTO * OFFENSIVE_FACTOR - VTD;
    *visitingStrength = HTD + 2 - VTO * OFFENSIVE_FACTOR;
    *specialTeamsImpact = HTS * SPECIAL_TEAMS_FACTOR - VTS;
    *homeFieldAdvantage = HTH + HTC * HOME_FIELD_ADVANTAGE -VTS;
    *visitingRoadStrength = HTO * HTD * HTH * OVERALL_FACTOR - VTO * VTD * VTR;
}

// Function to calculate the overall score difference using the weighted strengths
void computeDifference(double homeStrength, double visitingStrength, double specialTeamsImpact, double homeFieldAdvantage, double visitingRoadStrength, int *difference) {
    *difference = (int)(homeStrength * OFFENSIVE_WEIGHT +
                        visitingStrength * DEFENSIVE_WEIGHT +
                        specialTeamsImpact * SPECIAL_WEIGHT +
                        homeFieldAdvantage * HOME_WEIGHT +
                        visitingRoadStrength * OVERALL_WEIGHT);
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
