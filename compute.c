/*
   Compute.c Description:
   The "compute.c" file contains the core computation functions for evaluating the relative strengths
   of football teams and predicting the score difference between home and visiting teams.
*/
#include "header.h" // Include the header file that contains function prototypes

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

// Function to compute relative strengths and the score difference between two football teams
void computeStrengthsAndDifference(int HTO, int HTD, int HTS, int HTH, int HTC, int VTO, int VTD, int VTS, int VTR, int *difference) {
    // Parameters:
    // - HTO, HTD, HTS, HTH, HTC: Attributes for the home team
    // - VTO, VTD, VTS, VTR: Attributes for the visiting team
    // - difference: Pointer to an integer to store the computed score difference

    // Calculate the relative strengths for both teams
    double homeScoringStrength = HTO * OFFENSIVE_FACTOR - VTD;
    double visitingScoringStrength = HTD + 2 - VTO * OFFENSIVE_FACTOR;
    double specialTeamsImpact = HTS * SPECIAL_TEAMS_FACTOR - VTS;
    double homeFieldAdvantage = HTH + HTC * HOME_FIELD_ADVANTAGE - VTS;
    double visitingRoadStrength = HTO * HTD * HTH * OVERALL_FACTOR - VTO * VTD * VTR;

    // Calculate the overall score difference using the weighted strengths
    *difference = (int)(homeScoringStrength * OFFENSIVE_WEIGHT +
                        visitingScoringStrength * DEFENSIVE_WEIGHT +
                        specialTeamsImpact * SPECIAL_WEIGHT +
                        homeFieldAdvantage * HOME_WEIGHT +
                        visitingRoadStrength * OVERALL_WEIGHT);
}

