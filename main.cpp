/*
 * Date: April 8, 2026
 * Author: Caleb Debord
 * Course: CS 210
 */

#include <iostream>
#include <limits>
#include "InvestmentAccount.h"

using namespace std;

int main() {
    // Variables to hold the user's input
    double initialAmount, monthlyDeposit, interestRate;
    int years;

    // I am printing the input menu to match the rubric screenshot exactly
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initialAmount;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest: %";
    cin >> interestRate;

    cout << "Number of years: ";
    cin >> years;

    // I am pausing the program to wait for the user to press a key
    cout << "Press any key to continue . . .\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
    cin.get(); // Wait for the key press

    // I am creating my account object using the data the user just typed in
    InvestmentAccount myAccount(initialAmount, monthlyDeposit, interestRate, years);

    // I call the methods to print the two math reports
    myAccount.reportWithoutMonthlyDeposits();
    myAccount.reportWithMonthlyDeposits();

    return 0;
}