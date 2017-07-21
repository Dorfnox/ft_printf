/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_signedint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:38:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 18:30:15 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Get the number of characters in intmax_t number NOT INCLUDING sign character
*/

static int	intmax_num_length(intmax_t n)
{
	size_t i;

	i = 1;
	if (n == INTMAX_MIN)
		n = (INTMAX_MIN + 1) * -1;
	n *= (n < 0) ? -1 : 1;
	while (n /= 10)
		i++;
	return (i);
}

/*
** Returns ONLY the number WITHOUT a sign character.
*/

static char	*ft_intmax_to_ascii(intmax_t val, int base, char *b)
{
	char		*s;
	size_t		len;
	int			flag;

	len = intmax_num_length(val);
	flag = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (val == INTMAX_MIN)
	{
		val = (INTMAX_MIN + 1) * -1;
		flag = 1;
	}
	val *= (val < 0) ? -1 : 1;
	while (len--)
	{
		s[len] = (flag ? b[((INTMAX_MIN % base) * -1)] : b[val % base]);
		flag = 0;
		val /= base;
	}
	return (s);
}

/*
** pf_signedint for all signed data types
*/

static int add_sign(char **intmax_str, t_printf *p)
{
	char	*sign;

	if (!(sign = ft_strnew(1)))
		return (0);
	if (p->pid->fmt->im < 0)
	{
		sign[0] = '-';
	}
	else
		sign[0] = p->pid->f_sign != -1 ? '+' : ' ';
	if (!(sign = ft_strfjoin(&sign, *intmax_str)))
		return (0);
	ft_strdel(intmax_str);
	*intmax_str = sign;
	return ((int)ft_strlen(*intmax_str));
}

static int	add_precision(char **intmax_str, size_t num_of_zeros)
{
	char	*tmp;

	if (!(tmp = ft_strofchars('0', num_of_zeros)))
		return (0);
	if (!(tmp = ft_strfjoin(&tmp, *intmax_str)))
		return (0);
	ft_strdel(intmax_str);
	*intmax_str = tmp;
	return ((int)ft_strlen(*intmax_str));
}

int			pf_signedint(t_printf *p)
{
	char		*s;
	char		*barray;
	char		pad;
	int			s_len;

	if (!(barray = ft_strdup(p->pid->xbase != -1 ?
					"0123456789ABCDEF" : "0123456789abcdef")))
		return (-1); // Don't need this for signed
	s = ft_intmax_to_ascii(p->pid->fmt->im, p->pid->base, barray);
	pad = (p->pid->f_zero != -1 ? '0' : ' ');
	s_len = ft_strlen(s);
	if (p->pid->precision > s_len)
		if (!(s_len = add_precision(&s, (size_t)(p->pid->precision - s_len))))
			return (-1);
	if (p->pid->f_sign != -1 || p->pid->f_space != -1 || p->pid->fmt->im < 0)
		if (!(s_len = add_sign(&s, p)))
			return (-1);
	if (p->pid->f_ladj != -1)
		ft_putstr(s);
	s_len += (s_len < FIELD_W) ? ft_putchars(pad, FIELD_W - s_len) : 0;
	if (p->pid->f_ladj == -1)
		ft_putstr(s);
	free(barray);
	return (s_len);
}
