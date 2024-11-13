/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunatran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:50:51 by lunatran          #+#    #+#             */
/*   Updated: 2024/11/13 19:28:32 by lunatran         ###   ########.fr       */
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

void ft_print_numbers(int *a)
{
	while (*a != 0)
	{
		if (*a < 10)
			ft_putnbr(0);
		ft_putnbr(*a);
		a++;
	}
}


void ft_print_combn(int n)
{
    	int 	a[10];
	int 	index;
	int	max_index;

	index = 0;
    	while (index < n)
	{
		a[index] = index;
		index++;
	}
	max_index = index;
	ft_putstr("Done");
	while(1)
	{
		if (index - 1 < 9 - (max_index - index))
		{
			ft_print_numbers(a);
			a[index]++;
		}
		else
		{
			index--;
		}
		if (index < 0)
			break;
	}	

}

int main()
{
    ft_print_combn(2);
}
