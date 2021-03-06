/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_widestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:41:37 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/26 14:46:30 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*adjust_precision(wchar_t **ws, int precision)
{
	wchar_t	*tmp;

	if (!(tmp = ft_wstrsub(*ws, 0, precision)))
		return (NULL);
	free(*ws);
	*ws = NULL;
	return (tmp);
}

int				pf_widestr(t_printf *p)
{
	char	*fw;
	int		wstr_len;
	int		nsp;

	wstr_len = ft_wstrlen(p->pid->fmt->ws);
	if (p->pid->precision != -1)
		if (!(PID->fmt->ws = adjust_precision(&(PID->fmt->ws), PID->precision)))
			return (-1);
	nsp = PID->field_width - ft_wstrlen(PID->fmt->ws);
	if (nsp > 0)
		if (!(fw = ft_strofchars(' ', nsp)))
			return (-1);
	if (PID->f_ladj != -1)
		ft_putwstr(PID->fmt->ws);
	nsp > 0 ? ft_putstr(fw) : 0;
	if (PID->f_ladj == -1)
		ft_putwstr(PID->fmt->ws);
	return (ft_wstrlen(PID->fmt->ws) + (nsp > 0 ? ft_strlen(fw) : 0));
}
