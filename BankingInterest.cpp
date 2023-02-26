#include <iostream>
#include <iomanip>
using namespace std;

float initialInvest, monthlyDeposit, annualInterest, years, months, totalAmt, interestAmt, yearsTotInterest;

int  main()
{
	cout << "********************************" << endl; 
	cout << "********** Data Input **********" << endl; 
	cout << "Initial Investment Amount: " << endl; 
	cout << "Monthly Deposit: " << endl; 
	cout << "Annual Interest: " << endl; 
	cout << "Number of years: " << endl; 
	system("PAUSE"); 
	system("CLS");


	cout << "********************************" << endl; 
	cout << "********** Data Input **********" << endl; 
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvest;
	if (initialInvest < 0) {
		cout << "Initial investment amount can not be less than $0" << endl;
		cout << "Initial Investment Amount: $" << endl;
		cin >> initialInvest;
	}
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDeposit;
	if (monthlyDeposit < 0) {
		cout << "Initial monthly desposit can not be less than $0" << endl;
		cout << "Monthly Deposit: $" << endl;
		cin >> monthlyDeposit;
	}
	cout << "Annual Interest: " << endl; 
	cin >> annualInterest;
	cout << "Number of years: " << endl; 
	cin >> years;
	months = years * 12;
	system("PAUSE"); 
	system("CLS");

	totalAmt = initialInvest;

	cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "===========================================================" << endl;
	cout << "  Year    Year End Balance    Year End Earned Interest" << endl;

	for (int i = 0; i < 0; i++) {
		interestAmt = (totalAmt) * ((annualInterest / 100)); // yearly interest
		totalAmt = totalAmt + interestAmt; // year end total
		cout << "     " << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t$" << interestAmt << "\n";
	}
	totalAmt = initialInvest;
	cout << endl;

	cout << "            Balance and Interest With Additional Monthly Deposits" << endl; 
	cout << "=================================================================" << endl; 
	cout << "     Year       Year End Balance         Year End Earned Interest" << endl; 
	cout << "-----------------------------------------------------------------" << endl;

	for (int i = 0; i < years; i++) {
		//Set yearly interest to zero at the start of the year
		yearsTotInterest = 0;
		for (int j = 0; j < 12; j++) {
			//Calculate monthly interest
			interestAmt = (totalAmt + monthlyDeposit) * ((annualInterest / 100) / 12);
			//Calculate month end interest
			yearsTotInterest = yearsTotInterest + interestAmt;
			//Calculate month end total
			totalAmt = totalAmt + monthlyDeposit + interestAmt;
		}
		//Print results to table showcasing only two decimal points
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << yearsTotInterest << "\n";
	}
	return 0;
}