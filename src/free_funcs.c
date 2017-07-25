/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:30:44 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/24 18:52:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** s or ws point to same location in memory, so ft_strdel would work on either
*/

void	free_printf_datafmt(t_datafmt **fmt, int type)
{
	if (type == S_TYPE || type == WS_TYPE)
		ft_strdel(&((*fmt)->s));
	if (*fmt)
	{
		free(*fmt);
		*fmt = NULL;
	}
}

void	free_printf_percentid(t_percentid **pid)
{
	if (*pid)
	{
		free(*pid);
		*pid = NULL;
	}
}

void	free_all_the_things(t_printf **head)
{
	t_printf	*tmp;

	if (*head)
	{
		while (*head)
		{
			if ((*head)->type == STRING_TYPE)
			{
				ft_strdel(&((*head)->str));
			}
			else if ((*head)->type != -1)
			{
				free_printf_datafmt(&((*head)->pid->fmt), (*head)->type);
				free_printf_percentid(&((*head)->pid));
			}
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
}
