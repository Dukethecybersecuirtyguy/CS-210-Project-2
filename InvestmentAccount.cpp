/*
 * Date: April 8, 2026
 * Author: Caleb Debord
 * Course: CS 210
 */

#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;

// I am setting up the constructor to grab the user's inputs
InvestmentAccount::InvestmentAccount(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_years) {
    m_initialInvestment = t_initialInvestment;
    m_monthlyDeposit = t_monthlyDeposit;
    m_interestRate = t_interestRate;
    m_years = t_years;
}

// I am building the first report (NO extra monthly deposits)
void InvestmentAccount::reportWithoutMonthlyDeposits() {
    // I set my starting balance to the initial investment
    double currentBalance = m_initialInvestment;

    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // Loop through each year
    for (int i = 1; i <= m_years; i++) {
        // Calculate the interest for the whole year
        double yearlyInterest = currentBalance * (m_interestRate / 100);
        currentBalance += yearlyInterest;

        // Print the row with nice formatting
        cout << i << "\t\t$" << fixed << setprecision(2) << currentBalance << "\t\t$" << yearlyInterest << "\n";
    }
}

// I am building the second report (WITH extra monthly deposits)
void InvestmentAccount::reportWithMonthlyDeposits() {
    // I reset my starting balance
    double currentBalance = m_initialInvestment;

    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // Loop through each year
    for (int i = 1; i <= m_years; i++) {
        double yearlyTotalInterest = 0.0;

        // I need a second loop to calculate the compound interest for all 12 months
        for (int j = 0; j < 12; j++) {
            // Add my monthly deposit first
            currentBalance += m_monthlyDeposit;

            // Calculate this specific month's interest using the rubric's exact formula
            double monthlyInterest = currentBalance * ((m_interestRate / 100) / 12);

            // Add the interest to my balance and to my yearly tracker
            currentBalance += monthlyInterest;
            yearlyTotalInterest += monthlyInterest;
        }

        // Print the row for the end of the year
        cout << i << "\t\t$" << fixed << setprecision(2) << currentBalance << "\t\t$" << yearlyTotalInterest << "\n";
    }
}