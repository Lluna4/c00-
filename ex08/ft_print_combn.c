/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luna <luna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:50:51 by lunatran          #+#    #+#             */
/*   Updated: 2024/11/20 22:00:17 by luna             ###   ########.fr       */
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

void ft_print_numbers(int *a, size_t size)
{
	
	while (size > 0)
	{
		ft_putnbr(*a);
		
		a++;
		size--;
	}
	ft_putstr(", ");
}

//state 0 is sum last number 
//state 1 is sum other numbers pointed by index2 
//state 2 is break
void ft_print_combn(int n)
{
    int 	a[10];
	int 	index;
	int		index2;
	int		prev_index;
	int		max_index;
	int 	state;

	index = 0;
	state = 0;
	prev_index = 0;
    while (index < n)
	{
		a[index] = index;
		index++;
	}
	index--;
	max_index = index;
	index2 = index - 1;
	ft_putstr("Done\n");
	while(1)
	{
		if (state == 0)
		{
			if(a[index] > 9)
			{
				state = 1;
				continue;
			}
			ft_print_numbers(a, max_index + 1);
			a[index]++;
		}
		if (state == 1)
		{
			while (1)
			{
				if (index2 == -1)
				{
					state = 2;
					break;
				}
				prev_index = index2;
				a[index2]++;
				while (index2 < max_index)
				{
					a[index2 + 1] = a[index2] + 1;
					index2++;
				}
				index2 = prev_index;
				if (a[index2] > (9 - (max_index - index2)))
				{
					index2--;
				}
				else
				{
					state = 0;
					index2 = index - 1;
					break;
				}
			}
		}
		if (state == 2)
			break;
	}	
}

int main()
{
    ft_print_combn(5);
}
