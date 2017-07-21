/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:14:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 13:07:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_character(t_printf *p)
{
	char	pad;
	int		fw;

	pad = ' ';
	fw = 0;
	if (p->pid->f_ladj != -1)
	{
		ft_putchar(p->pid->fmt->c);
		while (++fw < p->pid->field_width)
			ft_putchar(pad);
	}
	else
	{
		while (++fw < p->pid->field_width)
			ft_putchar(pad);
		ft_putchar(p->pid->fmt->c);
	}
	return (fw);
}
