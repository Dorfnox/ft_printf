/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strfuncs4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:09:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 15:53:08 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** If given string such as "Hello\n\0\0\0\0\0\0\0\0"
 ** will return new string "Hello\n" and free space taken up by \0's
 */

char	*ft_strfremalloc(char **s)
{
	char	*new;

	if (!(new = ft_strdup(*s)))
		return (NULL);
	free(*s);
	*s = NULL;
	return (new);
}

size_t	ft_putchars(const char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

char	*ft_strofchars(const char c, size_t num)
{
	char	*new;
	size_t	i;

	if (!(new = ft_strnew(num)))
		return (NULL);
	i = 0;
	while (i < num)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strfjoin(char **s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)*s1) + ft_strlen((char *)s2))))
		return (NULL);
	while ((*s1)[i])
	{
		newstr[i] = (*s1)[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	ft_strdel(s1);
	return (newstr);
}
