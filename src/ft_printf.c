/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:39:32 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/21 16:46:26 by bpierce          ###   ########.fr       */
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
			i = store_percentid(&p1, &s[i], &ap, i);
		else
			i = storechar_printlst(&p1, s[i], i);
		if (i == -1)
			return (-1);
	}
	i = print_printlst(&p2);
	return (i);
}
