/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memfuncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:47:55 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/13 17:15:00 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	int				i;

	i = 0;
	a = b;
	while (len > 0)
	{
		a[i] = c;
		i++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void *)malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, size);
	return (memory);
}
