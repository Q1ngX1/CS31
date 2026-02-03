#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string CustomerName;
    string CustomerType;
    double PowerUsed;
    double total = 0;

    cout << "Customer Name: ";
    getline(cin, CustomerName);

    cout << "Power Used (in kilowatt hours): ";
    cin >> PowerUsed;
    cin.ignore();

    cout << "Customer Type: ";
    getline(cin, CustomerType);

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
            if (PowerUsed <= 10) // Tier 1
            {
                total += PowerUsed * 4.50;
            }
            else if (PowerUsed <= 20) // Tier 2
            {
                total += 10 * 4.50;
                total += (PowerUsed - 10) * 9.00;
            }
            else // Tier 3
            {
                total += 10 * 4.50;
                total += 10 * 9.00;
                total += (PowerUsed - 20) * 15.00;
            }
        }
        else
        {
            total = 19.95;
            if (PowerUsed <= 10) // Tier 1
            {
                total += PowerUsed * 7.50;
            }
            else if (PowerUsed <= 20) // Tier 2
            {
                total += 10 * 7.50;
                total += (PowerUsed - 10) * 15.00;
            }
            else // Tier 3
            {
                total += 10 * 7.50;
                total += 10 * 15.00;
                total += (PowerUsed - 20) * 20.00;
            }
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "The bill for " << CustomerName << " is $" << total << endl;
    }

    return 0;
}