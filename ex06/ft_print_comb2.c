/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunatran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:38:39 by lunatran          #+#    #+#             */
/*   Updated: 2024/11/13 16:48:29 by lunatran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (a < 10)
		ft_putnbr(0);
	ft_putnbr(a);
	ft_putchar(' ');
	if (b < 10)
		ft_putnbr(0);
	ft_putnbr(b);
}


void ft_print_comb2(void)
{
    int a; 
    a = 0;
    int b; 
    b = 1;

    while (a < 98)
    {
        while (b <= 99)
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
        if (a + b != 98 + 99)
            ft_putstr(", ");
    }
}

/*int main()
{
    ft_print_comb2();
}*/
