//
//  Code for Project 1 - Compile Error Version
//  This program has 2 compilation errors

#include <iostream>
using namespace std;

int main()
{
    int daysReviewed;
    int daysWithRain;
    int daysBelow50Degrees;

    cout << "How days were reviewed? ";
    cin >> daysReviewed;
    cout << "How many of these days were rainy? ";
    cin >> daysWithRain;
    cout << "How many of these days were colder than 50 degrees? ";
    cin >> daysBelow50Degrees;

    double pctRainy = 100.0 * daysWithRain / daysReviewed;
    double pctCold = 100.0 * daysBelow50Degrees / daysReviewed;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << endl;
    // Missing semicolon at end of statement
    cout << pctRainy << "% were rainy." cout << endl;
    cout << pctCold << "% were cold.";
    cout << endl;

    if (pctRainy > pctCold)
    {
        cout << "It was rainy more often than it was cold.";
        cout << endl;
    }
    else
    {
        // Using a variable that was never declared
        cout << "It was " << var << " more often than it rained.";
        cout << endl;
    }

    if (daysReviewed < 0 || daysWithRain < 0 || daysBelow50Degrees < 0)
    {
        cout << "Something looks awry with the numbers...";
        cout << endl;
    }

    if (daysReviewed < daysWithRain + daysBelow50Degrees)
    {
        cout << "These numbers don't add up...";
        cout << endl;
    }

    return (0);
}
