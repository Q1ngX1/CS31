#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string CustomerName;
    double PowerUsed;
    string CustomerType;
    double total = 0;

    cout << "Customer Name: ";
    getline(cin, CustomerName);

    cout << "Power Used (in kilowatt hours): ";
    cin >> PowerUsed;

    cout << "Customer Type: ";
    cin >> CustomerType;

    cout << "---" << endl;

    if (CustomerName == "")
    {
        cout << "You must enter a customer name." << endl;
    }
    else if (PowerUsed < 0)
    {
        cout << "The power usage reading must be nonnegative." << endl;
    }
    else if (CustomerType != "Residential" && CustomerType != "Business")
    {
        cout << "The customer type is not valid." << endl;
    }
    else
    {
        if (CustomerType == "Residential")
        {
            total = 14.95;
            // Tier 1
            if (PowerUsed <= 10)
            {
                total += PowerUsed * 4.50;
            }
            // Tier 2
            else if (PowerUsed <= 20)
            {
                total += 10 * 4.50;
                total += (PowerUsed - 10) * 9.00;
            }
            // Tier 3
            else
            {
                total += 10 * 4.50;
                total += 10 * 9.00;
                total += (PowerUsed - 20) * 15.00;
            }
        }
        else
        { // Business
            total = 19.95;
            // Tier 1
            if (PowerUsed <= 10)
            {
                total += PowerUsed * 7.50;
            }
            // Tier 2
            else if (PowerUsed <= 20)
            {
                total += 10 * 7.50;
                total += (PowerUsed - 10) * 15.00;
            }
            // Tier 3
            else
            {
                total += 10 * 7.50;
                total += 10 * 15.00;
                total += (PowerUsed - 20) * 20.00;
            }
        }
        cout << fixed << setprecision(2);
        cout << "The bill for " << CustomerName << " is $" << total << endl;
    }

    return 0;
}