/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_widestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:41:37 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/24 15:27:24 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*adjust_precision(wchar_t **ws, int precision)
{
	wchar_t	*tmp;

	tmp = ft_wstrsub(*ws, 0, precision);
	free(*ws);
	*ws = NULL;
	return (tmp);
}

int			pf_widestr(t_printf *p)
{
	char	*fw;
	int		wstr_len;
	int		nsp;
	int		i;

	wstr_len = ft_wstrlen(p->pid->fmt->ws);
	if (p->pid->precision != -1)
		if (!(PID->fmt->ws = adjust_precision(&(PID->fmt->ws), PID->precision)))
			return (-1);
	nsp = PID->field_width - ft_wstrlen(PID->fmt->ws);
	if (nsp > 0)
		if (!(fw = ft_strofchars(' ', nsp)))
			return (-1);
	i = 0;
	if (PID->f_ladj != -1)
	{
		while (i < wstr_len)
			ft_putwchar(PID->fmt->ws[i++]);
		nsp > 0 ? ft_putstr(fw) : 0;
	}
	else
	{
		nsp > 0 ? ft_putstr(fw) : 0;
		while (i < wstr_len)
			ft_putwchar(PID->fmt->ws[i++]);
	}
	return (ft_wstrlen(PID->fmt->ws) + (nsp > 0 ? ft_strlen(fw) : 0));
}
