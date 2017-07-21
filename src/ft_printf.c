/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:39:32 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 18:47:44 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *s, ...)
{
	va_list		ap;
	t_printf	*p1;
	t_printf	*p2;
	int			i;

	va_start(ap, s);
	if (!(initialize_printlst(&p1, &p2)))
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i = (storechar_printlst(&p1, s[i], i) != -1 ? i + 2 : -1);
		else if (s[i] == '%')
		{
			i = store_percentid(&p1, &s[i], &ap, i);
			//ft_putnbr(p1->type);
			//ft_putchar(' ');
			//ft_putnbr(((int)p1->print_func));
			//ft_putchar(' ');
			//ft_putnbr(i);
			//ft_putchar('\n');
		}
		else
			i = storechar_printlst(&p1, s[i], i);
		if (i == -1) // Remember to print error messages.
			return (-1); // Try to free memory before returning -1.
	}
	va_end(ap);
	i = print_printlst(&p2);
	//SOMETHING_TO_FREE_MEMORY(&p2);
	return (i);
}
/*
int		main(void)//int argc, char **argv)
{
	//argc = 1;
	long i = -6543444;
	int a, b;

	a = printf("Real: %+.10li hahaha", i);
	b = ft_printf("Mine: %+.10li hahaha", i);
	ft_putstr("\n^ len: ");
	ft_putnbr(b);
	ft_putstr("\nv len: ");
	ft_putnbr(a);
	ft_putchar('\n');
	return (1);
}
*/
