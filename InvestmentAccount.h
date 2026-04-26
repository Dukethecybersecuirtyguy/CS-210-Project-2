/*
 * Date: April 8, 2026
 * Author: Caleb Debord
 * Course: CS 210
 */

#pragma once
#ifndef INVESTMENT_ACCOUNT_H
#define INVESTMENT_ACCOUNT_H

class InvestmentAccount {
public:
    // Constructor to set up my initial values
    InvestmentAccount(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_years);

    // Methods to print my two required reports
    void reportWithoutMonthlyDeposits();
    void reportWithMonthlyDeposits();

private:
    // Variables to hold the data the user types in
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_years;
};

#endif