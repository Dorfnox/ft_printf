/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:23:30 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/31 16:23:39 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

# include <stdio.h>

/*
** Macros for saving space and general helpfulness
*/

# define PID p->pid
# define FIELD_W p->pid->field_width
# define PFT (*p)->type
# define PPID (*p)->pid
# define F_ALT (*p)->pid->f_alt
# define UIM (*p)->pid->fmt->uim
# define IM (*p)->pid->fmt->im
# define CONVERSIONS "sSpdDioOuUxXcCbB%"
# define NUM_CONVERSIONS "dDioOuUxXbB"
# define LENGTHS "hljz"

/*
** Type of argument given (int, string, etc...)
*/

# define STRING_TYPE 0
# define S_TYPE 1
# define SS_TYPE 2
# define DI_TYPE 3
# define DD_TYPE 4
# define O_TYPE 5
# define OO_TYPE 6
# define U_TYPE 7
# define UU_TYPE 8
# define X_TYPE 9
# define XX_TYPE 10
# define C_TYPE 11
# define CC_TYPE 12
# define P_TYPE 13
# define PCNT_TYPE 14
# define B_TYPE 15
# define BB_TYPE 16

/*
** Type promotion defines for length, and data type after length implementation
*/

# define L_HH 0
# define L_H 1
# define L_L 2
# define L_LL 3
# define L_J 4
# define L_Z 5

# define SC_TYPE 20
# define UC_TYPE 21
# define SH_TYPE 22
# define USH_TYPE 23
# define L_TYPE 24
# define UL_TYPE 25
# define LL_TYPE 26
# define ULL_TYPE 27
# define IM_TYPE 28
# define UIM_TYPE 29
# define ST_TYPE 30
# define WC_TYPE 31
# define WS_TYPE 32

/*
** Macros to check for signed types
*/

# define IS_DI(x) (x == DI_TYPE)
# define IS_SC(x) (x == SC_TYPE)
# define IS_SH(x) (x == SH_TYPE)
# define IS_L(x) (x == L_TYPE)
# define IS_LL(x) (x == LL_TYPE)
# define IS_IM(x) (x == IM_TYPE)
# define IS_SIGNED1(x) (IS_DI(x) || IS_SC(x) || IS_SH(x))
# define IS_SIGNED2(x) (IS_L(x) || IS_LL(x) || IS_IM(x))
# define IS_SIGNED(x) (IS_SIGNED1(x) || IS_SIGNED2(x))

/*
** Macros to check for unsigned types
*/

# define IS_P(x) (x == P_TYPE)

# define IS_O(x) (x == O_TYPE)
# define IS_OO(x) (x == OO_TYPE)
# define IS_OOO(x) (x == O_TYPE || x == OO_TYPE)
# define IS_U(x) (x == U_TYPE)
# define IS_UU(x) (x == UU_TYPE)
# define IS_UUU(x) (x == U_TYPE || x == UU_TYPE)
# define IS_X(x) (x == X_TYPE)
# define IS_XX(x) (x == XX_TYPE)
# define IS_XXX(x) (x == X_TYPE || x == XX_TYPE)
# define IS_OUX(x) (IS_OOO(x) || IS_UUU(x) || IS_XXX(x))

# define IS_ST(x) (x == ST_TYPE)
# define IS_UC(x) (x == UC_TYPE)
# define IS_USH(x) (x == USH_TYPE)
# define IS_UL(x) (x == UL_TYPE)
# define IS_ULL(x) (x == ULL_TYPE)
# define IS_UIM(x) (x == UIM_TYPE)
# define IS_UNSIGNED1(x) (IS_OUX(x) || IS_ST(x) || IS_UC(x) || IS_USH(x))
# define IS_UNSIGNED2(x) (IS_UL(x) || IS_ULL(x) || IS_UIM(x) || IS_P(x))
# define IS_UNSIGNED(x) (IS_UNSIGNED1(x) || IS_UNSIGNED2(x))

/*
** Macros to check for wide types
*/

# define IS_WI(x) (x == WI_TYPE)
# define IS_WC(x) (x == WC_TYPE)
# define IS_W(x) (IS_WI(x) || IS_WC(x))

/*
** 'u_datafmt' contains appropriate union member data.
*/

typedef union			u_datafmt
{
	int					c;
	char				*s;
	void				*p;
	wchar_t				wc;
	wchar_t				*ws;
	intmax_t			im;
	uintmax_t			uim;
}						t_datafmt;

/*
** 't_percentid' contains flag % data given by user
** 'fmt' points to the appropriate 'saved' union member
*/

typedef struct			s_percentid
{
	int					field_width;
	int					precision;
	int					len;
	int					f_alt;
	int					f_zero;
	int					f_ladj;
	int					f_space;
	int					f_sign;
	int					base;
	int					xbase;
	union u_datafmt		*fmt;
}						t_percentid;

/*
** If value == 0, use current str,
** else use id->print_func, which contains the address
** of the appropriate printer function.
*/

typedef struct			s_printf
{
	int					type;
	int					(*print_func)(struct s_printf *);
	char				*str;
	struct s_percentid	*pid;
	struct s_printf		*next;
}						t_printf;

/*
** For creating an array of function pointers in the store_percentid function
*/

typedef struct			s_setfunc
{
	int					(*f)(t_printf **, char *, int);
}						t_setfunc;

/*
** ft_printf.c
*/

int						ft_printf(char *s, ...);

/*
** manage_printlst.c
*/

t_printf				*new_printlst(void);
int						initialize_printlst(t_printf **p1, t_printf **p2);
int						storechar_printlst(t_printf **p, const char c, int i);
int						print_printlst(t_printf **p);

/*
** manage_percentid.c
*/

int						store_percentid(t_printf **p, char *s,
						va_list *ap, int i);

/*
** manage_datafmt.c
*/

int						store_datafmt(t_printf **p, va_list *ap);

/*
** set_percentid.c
*/

int						set_flags(t_printf **p, char *s, int j);
int						set_fieldwidth(t_printf **p, char *s, int j);
int						set_precision(t_printf **p, char *s, int j);
int						set_length(t_printf **p, char *s, int j);
int						set_type(t_printf **p, char *s, int j);

/*
** set_helper.c
*/

int						ft_islengthchar(int c);
int						ft_isconversionchar(int c);
int						ft_isnumericconversionchar(int c);

/*
** pf_{character, widechar, string, widestr, signedint, unsignedint,
** percent}.c
*/

int						pf_character(t_printf *p);
int						pf_widechar(t_printf *p);
int						pf_widestr(t_printf *p);
int						pf_string(t_printf *p);
int						pf_signedint(t_printf *p);
int						pf_unsignedint(t_printf *p);
int						pf_percent(t_printf *p);

/*
** free_funcs.c
*/

void					free_printf_datafmt(t_datafmt **fmt, int type);
void					free_printf_percentid(t_percentid **pid);
void					free_all_the_things(t_printf **head);

/*
** Libft functions:
** libft_{memfuncs, strfuncs1, strfuncs2, strfuncs3, strfuncs4, strfuncs5,
** wcharfuncs, wcharfuncs2}.c
*/

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);

size_t					ft_strlen(const char *s);
void					ft_putchar(const char c);
void					ft_putstr(const char *s);
void					ft_putendl(const char *s);
void					ft_putnbr(int n);

char					*ft_strnew(size_t size);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **as);
char					*ft_strfresize(char **s, size_t newsize);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);

int						ft_iswhitespace(int c);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
int						ft_isconversion(int c);
char					*ft_strdup(const char *s1);

char					*ft_strfremalloc(char **s);
size_t					ft_putchars(const char c, size_t n);
char					*ft_strofchars(const char c, size_t num);
char					*ft_strfjoin(char **s1, const char *s2);
void					ft_strtolower(char **s);

void					ft_strdeltwo(char **as, char **as2);
void					ft_strdelthree(char **as, char **as2, char **as3);
char					*ft_strffjoin(char **s1, char **s2);

size_t					ft_wstrlen(wchar_t *s);
wchar_t					*ft_wstrnew(size_t len);
wchar_t					*ft_wstrsub(wchar_t *ws,
						size_t start, size_t len);
void					ft_putwchar(wchar_t wi);

wchar_t					*ft_wstrdup(wchar_t *ws);
void					ft_putwstr(wchar_t *ws);

#endif
