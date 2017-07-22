/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:38:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/22 15:45:42 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns ONLY the number WITHOUT a sign character.
*/

static char	*ft_uintmax_to_ascii(uintmax_t val, int base, int xbase)
{
	int			len;
	char		*b_array;
	char		*s;
	uintmax_t	tmp_val;

	if (!(b_array = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	tmp_val = val;
	len = 1;
	while (tmp_val >= (uintmax_t)base)
	{
		tmp_val /= base;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		s[len] = b_array[val % base];
		val /= base;
	}
	if (xbase == -1)
		ft_strtolower(&s);
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

static int add_fieldwidth(char **str, char **chars, t_printf *p, char pad)
{
	char	*tmp;
	char	*tmp2;

	if (pad == '0')
	{
		tmp = ft_strsub(*str, 0, (p->pid->f_alt == 16 ? 2 : 1));
		tmp2 = ft_strsub(*str, (p->pid->f_alt == 16 ? 2 : 1),
				ft_strlen(*str) - (p->pid->f_alt == 16 ? 2 : 1));
		tmp = ft_strfjoin(&tmp, *chars);
		tmp = ft_strfjoin(&tmp, tmp2);
		ft_strdelthree(chars, &tmp2, str);
		*str = tmp;
	}
	else if (p->pid->f_ladj != -1)
	{
		*str = ft_strfjoin(str, *chars);
		ft_strdel(chars);
	}
	else
	{
		*chars = ft_strfjoin(chars, *str);
		ft_strdel(str);
		*str = *chars;
	}
	return ((int)ft_strlen(*str));
}

static int	add_precision(char **uintmax_str, int num_of_zeros)
{
	char	*tmp;

	if (!(tmp = ft_strofchars('0', num_of_zeros)))
		return (0);
	if (!(tmp = ft_strfjoin(&tmp, *uintmax_str)))
		return (0);
	ft_strdel(uintmax_str);
	*uintmax_str = tmp;
	return ((int)ft_strlen(*uintmax_str));
}

int			pf_unsignedint(t_printf *p)
{
	char		*s;
	char		*tmp;
	char		pad;
	int			len;

	if (!(s = ft_uintmax_to_ascii(PID->fmt->uim, PID->base, PID->xbase)))
		return (-1);
	pad = (p->pid->f_zero != -1 ? '0' : ' ');
	len = ft_strlen(s);
	if (p->pid->precision > len)
		if (!(len = add_precision(&s, p->pid->precision - len)))
			return (-1);
	if (p->pid->f_alt == 16 || p->pid->f_alt == 8)
		if (!(len = add_alt(&s, p, p->pid->f_alt)))
			return (-1);
	if (p->pid->field_width > len)
	{
		if (!(tmp = ft_strofchars(pad, p->pid->field_width - len)))
			return (-1);
		if (!(len = add_fieldwidth(&s, &tmp, p, pad)))
			return (-1);
	}
	ft_putstr(s);
	return (len);
}
