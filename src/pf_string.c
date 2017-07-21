/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:14:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 13:07:05 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_string(t_printf *p)
{
	char	*s;
	int		fw;
	int		s_len;

	if (p->pid->precision != -1)
	{
		s = ft_strsub(p->pid->fmt->s, 0, p->pid->precision);
		ft_strdel(&(p->pid->fmt->s));
		p->pid->fmt->s = s;
	}
	fw = 0;
	s_len = ft_strlen(p->pid->fmt->s);
	if (p->pid->f_ladj != -1)
	{
		ft_putstr(p->pid->fmt->s);
		while (++fw < (p->pid->field_width - s_len))
			ft_putchar(' ');
	}
	else
	{
		while (++fw < (p->pid->field_width - s_len))
			ft_putchar(' ');
		ft_putstr(p->pid->fmt->s);
	}
	return ((s_len >= p->pid->field_width) ? s_len : fw + s_len);
}
