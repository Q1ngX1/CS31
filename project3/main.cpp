#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// D: Deposite (+)
// C: Cash out (-)
// B: Bet (-)
// W: Win (+)

// To check if a character is a valid command
bool isCommand(char c)
{
    return (c == 'D' || c == 'B' || c == 'C' || c == 'W');
}

// Helper function to parse a number starting at position pos
// Returns the number parsed, and updates pos to point after the number
// Returns -1 if invalid (no digits, leading zeros, or zero value)
int parseNumber(const string &s, size_t &pos)
{
    if (pos >= s.length() || !isdigit(s[pos]))
    {
        return -1; // No number found
    }

    // Check for leading zeros: if first digit is '0' and there are more digits
    if (s[pos] == '0')
    {
        // '0' alone would be invalid (zero not allowed)
        // '0' followed by more digits is leading zero (invalid)
        return -1;
    }

    int num = 0;
    while (pos < s.length() && isdigit(s[pos]))
    {
        num = num * 10 + (s[pos] - '0');
        pos++;
    }

    // Zero is not allowed as an amount
    if (num == 0)
    {
        return -1;
    }

    return num;
}

bool isValidSlotMachineString(string slotstring)
{
    if (slotstring.empty())
    {
        return false;
    }

    if (slotstring[0] != 'D')
    {
        return false;
    }

    for (size_t k = 0; k < slotstring.length(); k++)
    {
        char c = slotstring[k];
        if (!isCommand(c) && !isdigit(c))
        {
            return false;
        }
    }

    int balance = 0;
    bool lastWasBet = false; // Track if last command was a bet (for win validation)
    size_t pos = 0;
    while (pos < slotstring.length())
    {
        char cmd = slotstring[pos];

        if (!isCommand(cmd))
        {
            return false; // Expected a command character
        }

        pos++; // Move past the command character

        int amount = parseNumber(slotstring, pos);
        if (amount == -1)
        {
            return false; // Invalid number
        }

        switch (cmd)
        {
        case 'D':
            // Deposit: add to balance
            balance += amount;
            lastWasBet = false;
            break;

        case 'B':
            // Bet: must not exceed balance
            if (amount > balance)
            {
                return false;
            }
            balance -= amount;
            lastWasBet = true;
            break;

        case 'W':
            // Win: must follow a bet
            if (!lastWasBet)
            {
                return false;
            }
            balance += amount;
            lastWasBet = false; // Win consumes the bet, next win needs another bet
            break;

        case 'C':
            // Cashout: must exactly match balance
            if (amount != balance)
            {
                return false;
            }
            balance = 0;
            lastWasBet = false;
            break;

        default:
            return false;
        }

        // Balance can never be negative
        if (balance < 0)
        {
            return false;
        }
    }

    return true;
}

int howManyBets(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int count = 0;
    for (size_t i = 0; i < slotstring.length(); i++)
    {
        if (slotstring[i] == 'B')
        {
            count++;
        }
    }
    return count;
}

int howManyDeposits(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int count = 0;
    for (size_t i = 0; i < slotstring.length(); i++)
    {
        if (slotstring[i] == 'D')
        {
            count++;
        }
    }
    return count;
}

int howManyWins(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int count = 0;
    for (size_t i = 0; i < slotstring.length(); i++)
    {
        if (slotstring[i] == 'W')
        {
            count++;
        }
    }
    return count;
}

int howManyCashouts(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int count = 0;
    for (size_t i = 0; i < slotstring.length(); i++)
    {
        if (slotstring[i] == 'C')
        {
            count++;
        }
    }
    return count;
}

int howMuchBet(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int total = 0;
    size_t pos = 0;

    while (pos < slotstring.length())
    {
        char cmd = slotstring[pos];
        pos++;
        int amount = parseNumber(slotstring, pos);

        if (cmd == 'B')
        {
            total += amount;
        }
    }
    return total;
}

int howMuchDeposited(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int total = 0;
    size_t pos = 0;

    while (pos < slotstring.length())
    {
        char cmd = slotstring[pos];
        pos++;
        int amount = parseNumber(slotstring, pos);

        if (cmd == 'D')
        {
            total += amount;
        }
    }
    return total;
}

int howMuchWon(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int total = 0;
    size_t pos = 0;

    while (pos < slotstring.length())
    {
        char cmd = slotstring[pos];
        pos++;
        int amount = parseNumber(slotstring, pos);

        if (cmd == 'W')
        {
            total += amount;
        }
    }
    return total;
}

int howMuchCashedout(string slotstring)
{
    if (!isValidSlotMachineString(slotstring))
    {
        return -1;
    }

    int total = 0;
    size_t pos = 0;

    while (pos < slotstring.length())
    {
        char cmd = slotstring[pos];
        pos++;
        int amount = parseNumber(slotstring, pos);

        if (cmd == 'C')
        {
            total += amount;
        }
    }
    return total;
}

int main()
{
    // Test cases
    cout << "Testing isValidSlotMachineString:" << endl;
    cout << "D10C10: " << (isValidSlotMachineString("D10C10") ? "valid" : "invalid") << endl;
    cout << "D10B5: " << (isValidSlotMachineString("D10B5") ? "valid" : "invalid") << endl;
    cout << "D10B5C5: " << (isValidSlotMachineString("D10B5C5") ? "valid" : "invalid") << endl;
    cout << "D10B5W1C6: " << (isValidSlotMachineString("D10B5W1C6") ? "valid" : "invalid") << endl;
    cout << "D10B10W50: " << (isValidSlotMachineString("D10B10W50") ? "valid" : "invalid") << endl;
    cout << "D10B10W50C50: " << (isValidSlotMachineString("D10B10W50C50") ? "valid" : "invalid") << endl;

    cout << "\nTesting invalid strings:" << endl;
    cout << "asdf1ABC000:2-55: " << (isValidSlotMachineString("asdf1ABC000:2-55") ? "valid" : "invalid") << endl;
    cout << "D10    D10: " << (isValidSlotMachineString("D10    D10") ? "valid" : "invalid") << endl;
    cout << "C10: " << (isValidSlotMachineString("C10") ? "valid" : "invalid") << endl;
    cout << "B10W20: " << (isValidSlotMachineString("B10W20") ? "valid" : "invalid") << endl;
    cout << "D10B0: " << (isValidSlotMachineString("D10B0") ? "valid" : "invalid") << endl;
    cout << "D0D10: " << (isValidSlotMachineString("D0D10") ? "valid" : "invalid") << endl;
    cout << "D10B10W0: " << (isValidSlotMachineString("D10B10W0") ? "valid" : "invalid") << endl;
    cout << "D10B10W10C0: " << (isValidSlotMachineString("D10B10W10C0") ? "valid" : "invalid") << endl;
    cout << "D10B10W10C1: " << (isValidSlotMachineString("D10B10W10C1") ? "valid" : "invalid") << endl;
    cout << "D000010B1W1: " << (isValidSlotMachineString("D000010B1W1") ? "valid" : "invalid") << endl;
    cout << "D10B0000010W1: " << (isValidSlotMachineString("D10B0000010W1") ? "valid" : "invalid") << endl;
    cout << "D10B5W2W3B5: " << (isValidSlotMachineString("D10B5W2W3B5") ? "valid" : "invalid") << endl;

    cout << "\nTesting count functions with D10B5W1C6:" << endl;
    cout << "howManyDeposits: " << howManyDeposits("D10B5W1C6") << endl;
    cout << "howManyBets: " << howManyBets("D10B5W1C6") << endl;
    cout << "howManyWins: " << howManyWins("D10B5W1C6") << endl;
    cout << "howManyCashouts: " << howManyCashouts("D10B5W1C6") << endl;

    cout << "\nTesting amount functions with D10B5W1C6:" << endl;
    cout << "howMuchDeposited: " << howMuchDeposited("D10B5W1C6") << endl;
    cout << "howMuchBet: " << howMuchBet("D10B5W1C6") << endl;
    cout << "howMuchWon: " << howMuchWon("D10B5W1C6") << endl;
    cout << "howMuchCashedout: " << howMuchCashedout("D10B5W1C6") << endl;

    cout << "\nTesting invalid string returns -1:" << endl;
    cout << "howManyBets(\"invalid\"): " << howManyBets("invalid") << endl;

    return 0;
}
