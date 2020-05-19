// Calculate fewest number of coins

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Variable for user input
    float owed;

    // Get user Input
    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0);

    // Convert float amount of dollars to int amount of cents
    int cents = round(owed * 100);

    int coins = 0;

    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
        coins++;
    }
    printf("%i\n", coins);
}