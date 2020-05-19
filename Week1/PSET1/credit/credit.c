#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    long card_number;

    //Prompts user for input and validates it as non-negative
    do
    {
        card_number = get_long("What's your credit card number? ");
    }
    while (card_number <= 0);

    //Declare variables to store CC number's length
    int count_digits = 0;
    long length = card_number;

    //Counts number of digits
    while (length > 0)
    {
        length /= 10;
        count_digits++;
    }

    //Prints INVALID if length is shorter than 13 or longer than 16
    if (count_digits != 13 && count_digits != 15 && count_digits != 16)
    {
        printf("INVALID\n");
    }
    else // Let the MAGIC START!!!
    {
        long dig1 = powl(10, count_digits - 1);
        long dig2 = powl(10, count_digits - 2);
        long card = card_number;
        long digit0 = card / dig1;
        long digit1 = card / dig2 % 10;
        int step = 1;
        int digit = 0;
        int checksum = 0;
        while (card > 0)
        {
            digit = card % 10;
            card /= 10;
            if (step % 2 == 0)
            {
                int digit_check = 0;
                if ((digit * 2) >= 10)
                {
                    digit *= 2;
                    digit_check = (digit % 10) + 1;
                }
                else
                {
                    digit_check = digit * 2;
                }
                checksum += digit_check;
            }
            else
            {
                checksum += digit;
            }
            step += 1;
        }
        if (checksum % 10 == 0)
        {
            switch (count_digits)
            {
                case 13:
                    if (digit0 == 4)
                    {
                        printf("VISA\n");
                        break;
                    }
                case 15:
                    if (digit0 == 3 && (digit1 == 4 || digit1 == 7))
                    {
                        printf("AMEX\n");
                        break;
                    }
                case 16:
                    if (digit0 == 4)
                    {
                        printf("VISA\n");
                        break;
                    }
                    else if (digit0 == 5 && (digit1 == 1 || digit1 == 2 || digit1 == 3 || digit1 == 4 || digit1 == 5))
                    {
                        printf("MASTERCARD\n");
                        break;
                    }
                default:
                    printf("INVALID\n");
                    break;
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}