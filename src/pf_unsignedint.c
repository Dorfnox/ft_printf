/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:38:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 19:34:41 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns ONLY the number WITHOUT a sign character.
*/

static char	*ft_uintmax_to_ascii(uintmax_t val, int base, int xbase)
{
	char		*s;
	size_t		len;
	char		*b_array;
	uintmax_t	tmp;

	if (!(b_array = ft_strdup(xbase != -1 ?
					"0123456789ABCDEF" : "0123456789abcdef")))
		return (NULL);
	len = 1;
	tmp = val;
	while (tmp /= 10)
		len++;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		s[len] = b_array[val % base];
		val /= base;
	}
	free(b_array);
	return (s);
}

static int	add_alt(char **uintmax_str, t_printf *p, int f_alt)
{
	char	*alt;

	if (!(alt = ft_strnew(f_alt == 16 ? 2 : 1)))
		return (0);
	alt[0] = '0';
	if (f_alt == 16)
		alt[1] = p->pid->xbase != -1 ? 'X' : 'x';
	if (!(alt = ft_strfjoin(&alt, *uintmax_str)))
		return (0);
	ft_strdel(uintmax_str);
	*uintmax_str = alt;
	return ((int)ft_strlen(*uintmax_str));
}

static char	*add_precision_hex(char **uintmax_str, int num_of_zeros)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (!(tmp = ft_strsub(*uintmax_str, 0, 2)))
		return (0);
	if (!(tmp2 = ft_strofchars('0', num_of_zeros)))
		return (0);
	if (!(tmp3 = ft_strsub(*uintmax_str, 2, ft_strlen(*uintmax_str) - 2)))
		return (0);
	tmp = ft_strfjoin(&tmp, tmp2);
	tmp = ft_strfjoin(&tmp, tmp3);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
	return (tmp);
}

static int	add_precision(char **uintmax_str, int num_of_zeros, int f_alt)
{
	char	*tmp;

	if (f_alt == 16)
	{
		if ((num_of_zeros + 2) > 0)
		{
			if (!(tmp = add_precision_hex(uintmax_str, num_of_zeros + 2)))
				return (0);
			ft_strdel(uintmax_str);
			*uintmax_str = tmp;
		}
	}
	else
	{
		if (!(tmp = ft_strofchars('0', num_of_zeros)))
			return (0);
		if (!(tmp = ft_strfjoin(&tmp, *uintmax_str)))
			return (0);
		ft_strdel(uintmax_str);
		*uintmax_str = tmp;
	}
	return ((int)ft_strlen(*uintmax_str));
}

int			pf_unsignedint(t_printf *p)
{
	char		*s;
	char		pad;
	int			s_len;
	int			f_alt;

	s = ft_uintmax_to_ascii(p->pid->fmt->im, p->pid->base, p->pid->xbase);
	pad = (p->pid->f_zero != -1 ? '0' : ' ');
	s_len = ft_strlen(s);
	f_alt = p->pid->f_alt;
	if (f_alt == 16 || f_alt == 8)
		if (!(s_len = add_alt(&s, p, f_alt)))
			return (-1);
	if (p->pid->precision > s_len || f_alt == 16)
		if (!(s_len = add_precision(&s, p->pid->precision - s_len, f_alt)))
			return (-1);
	if (p->pid->f_ladj != -1)
		ft_putstr(s);
	s_len += (s_len < FIELD_W) ? ft_putchars(pad, FIELD_W - s_len) : 0;
	if (p->pid->f_ladj == -1)
		ft_putstr(s);
	return (s_len);
}
