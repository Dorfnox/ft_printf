/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strfuncs3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 17:57:10 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/24 16:16:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		sign;
	int		total;

	sign = 1;
	total = 0;
	while (ft_iswhitespace(*str) == 1)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		total = (total * 10) + (*str - '0');
		str++;
	}
	return (sign * total);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	if (!s1)
		return (NULL);
	if (!(s = ft_strnew(ft_strlen(s1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = s1[i];
	return (s);
}
