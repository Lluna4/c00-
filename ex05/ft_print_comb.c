#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while(*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        return ;
    }

    if (nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }

    if (nb >= 10)
    {
        ft_putnbr(nb/10);
        nb %= 10;
    }

    ft_putchar(nb + '0');
}

void ft_print_numbers(int a, int b, int c)
{
    ft_putnbr(a);
    ft_putnbr(b);
    ft_putnbr(c);
}

void ft_print_comb(void)
{
    int a = 0;
    int b = 1;
    int c = 2;

    while (a < 7)
    {
        while (b < 8)
        {
            while (c < 9)
            {
                if (c > b && b > a)
                {
                    ft_print_numbers(a, b, c);
                    ft_putstr(", ");
                }
                c++;
            }
            if (b < 9)
            {
                b++;
                c = b + 1;
            }
        }
        a++;
        b = a + 1;
        ft_print_numbers(a, b, c);
        if (a + b + c != 7 + 8 + 9)
            ft_putstr(", ");
    }
}