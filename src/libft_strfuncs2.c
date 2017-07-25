/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strfuncs2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:15:34 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/24 18:36:03 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;
	int length;

	i = 0;
	length = ft_strlen(src);
	while (i != length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strfresize(char **s, size_t newsize)
{
	char	*tmp;

	if (!(tmp = ft_strnew(newsize)))
		return (NULL);
	ft_strcpy(tmp, *s);
	ft_strdel(s);
	return (tmp);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	newstr = ft_strnew(len);
	if (newstr == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		newstr[i] = s[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}
