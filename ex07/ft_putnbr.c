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
