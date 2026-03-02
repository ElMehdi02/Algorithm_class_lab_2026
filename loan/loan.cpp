//************************************************************
// El Mehdi Bensouda
// COSC 300 – Algorithms
// Program: Loan Payoff Calculator
// Spring 2026
//
// Description:
// This program calculates how many months it will take to
// pay off a loan based on the loan amount, annual interest
// rate, and a fixed monthly payment. It also calculates
// the total interest paid over the life of the loan.
//************************************************************

#include <iostream>
#include <iomanip>
using namespace std;


int main() {

    // Declare variables for loan amount, annual interest rate, and monthly payment
    double loanAmount, annualRate, monthlyPayment;

    // Ask the user to enter the loan amount
    cout << "Enter loan amount: ";

    // Store the loan amount entered by the user
    cin >> loanAmount;

    // Ask the user to enter the annual interest rate
    cout << "Enter annual interest rate: ";

    // Store the annual interest rate entered by the user
    cin >> annualRate;

    // Ask the user to enter the monthly payment
    cout << "Enter monthly payment: ";

    // Store the monthly payment entered by the user
    cin >> monthlyPayment;

    // Declare a variable to store the monthly interest rate
    double monthlyRate;

    // Convert annual interest rate (percentage) to monthly decimal rate
    monthlyRate = (annualRate / 100.0) / 12.0;

    // Check if the monthly payment is too small to ever pay off the loan
    if (monthlyPayment <= loanAmount * monthlyRate) {

        // Display an error message if loan can never be paid off
        cout << "Monthly payment is too small to ever pay off the loan." << endl;

        // End the program early to avoid infinite loop
        return 0;
    }

    // Initialize the remaining loan balance and total interest paid
    double balance = loanAmount, totalInterest = 0;

    // Initialize a counter to track number of months
    int months = 0;

    // Loop until the loan balance becomes zero
    while (balance > 0) {

        // Declare a variable to store interest for the current month
        double interest;

        // Declare a variable to store how much principal is paid
        double principalPaid;

        // Calculate interest for the current month
        interest = balance * monthlyRate;

        // Add this month's interest to the total interest paid
        totalInterest = totalInterest + interest;

        // Calculate how much of the payment goes toward the principal
        principalPaid = monthlyPayment - interest;

        // Check if the principal payment is more than the remaining balance
        if (principalPaid > balance) {

            // Adjust the last payment to avoid overpaying
            principalPaid = balance;
        }

        // Subtract the principal paid from the loan balance
        balance = balance - principalPaid;

        // Increase the month counter by one
        months = months + 1;
    }

    // Format output to show exactly two decimal places
    cout << fixed << setprecision(2);

    // Display the total number of months needed to pay off the loan
    cout << "Months to pay off loan: " << months << endl;

    // Display the total interest paid over the life of the loan
    cout << "Total interest paid: $" << totalInterest << endl;

    return 0;
}