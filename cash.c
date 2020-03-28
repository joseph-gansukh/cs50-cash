#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int change_in_cents;
    int number_of_coins = 0;

    // Promps for the change amount

    do
    {
        change = get_float("Change owed: ");
        change_in_cents = round(change * 100);
    }
    while (change < 0);

    // Adds max quarters to number_of_coins

    if (change_in_cents > 25)
    {
        int quarters = floor(change_in_cents / 25);
        change_in_cents = change_in_cents % 25;
        number_of_coins = quarters;
    }

    // Adds max dimes to number_of_coins

    if (change_in_cents >= 10 && change_in_cents < 25)
    {
        int dime = floor(change_in_cents / 10);
        change_in_cents = change_in_cents % 10;
        number_of_coins = number_of_coins + dime;
    }

    // Adds max nickels to number_of_coins

    if (change_in_cents >= 5 && change_in_cents < 10)
    {
        int nickel = floor(change_in_cents / 5);
        change_in_cents = change_in_cents % 5;
        number_of_coins = number_of_coins + nickel;
    }

    // Adds max pennies to number_of_coins

    if (change_in_cents >= 1 && change_in_cents < 5)
    {
        number_of_coins = number_of_coins + change_in_cents;
    }
    
    printf("%i\n", number_of_coins);
}
