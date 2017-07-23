/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strfuncs5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 15:44:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/22 18:27:39 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strdeltwo(char **as, char **as2)
{
	ft_strdel(as);
	ft_strdel(as2);
}

void	ft_strdelthree(char **as, char **as2, char **as3)
{
	ft_strdel(as);
	ft_strdel(as2);
	ft_strdel(as3);
}

char	*ft_strffjoin(char **s1, char **s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)*s1) + ft_strlen((char *)*s2))))
		return (NULL);
	while ((*s1)[i])
	{
		newstr[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j])
		newstr[i++] = (*s2)[j++];
	newstr[i] = '\0';
	ft_strdeltwo(s1, s2);
	return (newstr);
}
