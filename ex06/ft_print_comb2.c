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

void ft_print_numbers(int a, int b)
{
    ft_putnbr(a);
    ft_putnbr(b);
}


void ft_print_comb2(void)
{
    int a = 0;
    int b = 1;

    while (a < 8)
    {
        while (b < 9)
        {
            if (b > a)
            {
                ft_print_numbers(a, b);
                ft_putstr(", ");
            }
            b++;
        }
        a++;
        b = a + 1;
        ft_print_numbers(a, b);
        if (a + b != 8 + 9)
            ft_putstr(", ");
    }
}

int main()
{
    ft_print_comb2();
}