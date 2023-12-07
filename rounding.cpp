// Copyright (c) 2023 Zak Goneau All rights reserved.
//
// Created by: Zak Goneau
// Date Created: Dec. 6, 2023
// This program rounds numbers and uses pass by reference.

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

void RoundDecimal(float &numOne, int numPlaces) {
    // calculations to round decimal
    numOne = (numOne * pow(10, numPlaces)) + 0.5;
    numOne = static_cast<int>(numOne);
    numOne = numOne / pow(10, numPlaces);
}

int main() {
    // declare variables
    std::string userNumOne, roundNumber;
    float numOneFloat, roundDecimalFloat;
    int numOneInt, roundDecimal;

    // introduce program to user
    std::cout << "Hello, this program rounds numbers to the";
    std::cout << "nearest inputted number " << std::endl;

    // get inputs from user
    std::cout << "Please enter a decimal: ";
    std::cin >> userNumOne;
    std::cout << "Please enter the number of places you want to round to: ";
    std::cin >> roundNumber;

    // try casting first input to a float
    try {
        numOneFloat = std::stof(userNumOne);

        // cast first input to integer as well
        numOneInt = std::stoi(userNumOne);

        // try casting second input to an integer
        try {
            roundDecimal = std::stoi(roundNumber);

            // cast second input to float as well
            roundDecimalFloat = std::stof(roundNumber);

            // check if first input is decimal and if other is integer
            if (numOneInt != numOneFloat && roundDecimal == roundDecimalFloat) {

                // call function
                RoundDecimal(numOneFloat, roundDecimal);

                // display answer
                std::cout << "The decimals rounded to " << roundDecimal << " places equals: " << numOneFloat << std::endl;
                } else {

                    // tell user if invalid numbers
                    std::cout << "The first input must be a decimal and the second must be an integer." << std::endl;
                }

        // catch invalid inputs
        } catch (std::invalid_argument) {
            std::cout << "You must input a positive integer which " << roundNumber << " is not." << std::endl;
        }

    // catch invalid inputs
    } catch (std::invalid_argument) {
        std::cout << "" << userNumOne << " is not a decimal number." << std::endl;
    }
}
