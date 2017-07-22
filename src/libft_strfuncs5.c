/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strfuncs5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 15:44:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/22 16:01:45 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strdeltwo(char **as, char **as2)
{
	ft_strdel(as);
	ft_strdel(as2);
}

void	ft_strdelthree(char **as, char **as2, char **as3)
{
	ft_strdel(as);
	ft_strdel(as2);
	ft_strdel(as3);
}
