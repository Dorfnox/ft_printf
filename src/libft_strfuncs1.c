/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strfuncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:21:01 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/13 19:21:17 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putendl(const char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putnbr(int n)
{
	int flag;

	flag = 0;
	if (n == -2147483648)
	{
		flag = 1;
		n += 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		if (flag == 1)
			ft_putchar('8');
		else
			ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
