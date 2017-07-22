/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_datafmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 14:10:10 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/21 17:35:21 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			set_unsigned(t_printf **p, int type, va_list *ap)
{
	if (IS_OUX(type) || IS_UC(type) || IS_USH(type))
		(*p)->pid->fmt->uim = (uintmax_t)va_arg(*ap, unsigned int);
	else if (IS_UL(type))
		(*p)->pid->fmt->uim = (uintmax_t)va_arg(*ap, unsigned long);
	else if (IS_ULL(type))
		(*p)->pid->fmt->uim = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (IS_UIM(type))
		(*p)->pid->fmt->uim = (uintmax_t)va_arg(*ap, uintmax_t);
}

static void			set_signed(t_printf **p, int type, va_list *ap)
{
	if (IS_DI(type) || IS_SC(type) || IS_SH(type))
		(*p)->pid->fmt->im = (intmax_t)va_arg(*ap, int);
	else if (IS_L(type))
		(*p)->pid->fmt->im = (intmax_t)va_arg(*ap, long);
	else if (IS_LL(type))
		(*p)->pid->fmt->im = (intmax_t)va_arg(*ap, long long);
	else if (IS_IM(type))
		(*p)->pid->fmt->im = (intmax_t)va_arg(*ap, intmax_t);
}

static int			set_uniondata(t_printf **p, int type, va_list *ap)
{
	if (type == C_TYPE)
	{
		(*p)->pid->fmt->c = va_arg(*ap, int);
		(*p)->print_func = &pf_character;
	}
	else if (type == S_TYPE)
	{
		if (!((*p)->pid->fmt->s = ft_strdup(va_arg(*ap, char *))))
			return (0);
		(*p)->print_func = &pf_string;
	}
	else if (IS_SIGNED(type) || IS_UNSIGNED(type))
	{
		IS_SIGNED(type) ? set_signed(p, type, ap) : set_unsigned(p, type, ap);
		(*p)->print_func = IS_SIGNED(type) ? &pf_signedint : &pf_unsignedint;
	}
	else if (type == P_TYPE)
		(*p)->pid->fmt->p = va_arg(*ap, void *);
	else if (type == WI_TYPE || type == WC_TYPE)
		(*p)->pid->fmt->wi = va_arg(*ap, wint_t);
	return (1);
}

/*
** Stores data gotten from vaarg.
** Returns the length of data as will be printed.
*/

int					store_datafmt(t_printf **p, va_list *ap)
{
	if (!((*p)->pid->fmt = (t_datafmt *)ft_memalloc(sizeof(t_datafmt *))))
		return (-1);
	if (!(set_uniondata(p, (*p)->type, ap)))
		return (-1);
	return (1);
}
