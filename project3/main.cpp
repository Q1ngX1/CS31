#include <iostream>

using namespace std;

/*This function returns true if its parameter is a 
well-formed slot machine string as described above, or false otherwise.*/
bool isValidSlotMachineString(string slotstring);

/*If the parameter is a well-formed slot machine string, 
this function should return the number of bet commands that 
occurred once the string is fully processed.
If the parameter is not a valid slot machine string, return -1.*/
int howManyBets(string slotstring);

/*If the parameter is a well-formed slot machine string,
this function should return the number of deposit commands that
occurred once the string is fully processed.
If the parameter is not a valid slot machine string, return -1.*/
int howManyDeposits(string slotstring);

int howManyWins(string slotstring);

int howManyCashouts(string slotstring);

int howMuchBet(string slotstring);

int howMuchDeposited(string slotstring);

int howMuchWon(string slotstring);

int howMuchCashedout(string slotstring);


int main()
{
    return 0;
}

