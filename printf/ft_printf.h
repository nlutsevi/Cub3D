/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:19:06 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/07 18:56:46 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_struct
{
	int				flag_m;
	int				flag_z;
	int				flag_w;
	int				flag_p;
	va_list			args;
	char			*str;
	int				ret;
	int				i;

}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_parser(t_struct *list);
void			seek_flags(t_struct *list);
void			flags_minus_zero(t_struct *list);
void			flag_width(t_struct *list);
void			flag_precision(t_struct *list);
void			ft_printf_c(t_struct *list, int c);
void			ft_printf_s(t_struct *list, char *s);
int				ft_count(long nb);
void			ft_printf_d_i(t_struct *list, int nb);
void			ft_printf_c_width(t_struct *list, int c);
void			ft_printf_c_minus(t_struct *list, int c);
void			ft_printf_d_i_width(t_struct *list, char *d);
void			ft_printf_d_i_minus(t_struct *list, char *d);
void			ft_printf_d_i_zero(t_struct *list, char *d);
void			ft_printf_d_i_precision(t_struct *list, char *d);
void			ft_printf_s_width(t_struct *list, char *s);
void			ft_printf_s_minus(t_struct *list, char *s);
void			ft_printf_s_zero(t_struct *list, char *s);
void			ft_printf_s_precision(t_struct *list, char *s);
void			ft_printf_s_w_p(t_struct *list, char *s);
void			ft_printf_s_w_p_aux3(t_struct *list, char *s);
void			ft_printf_s_m_w_p(t_struct *list, char *s);
void			ft_printf_u(t_struct *list, unsigned int nb);
void			ft_printf_u_width(t_struct *list, char *d);
void			ft_printf_u_minus(t_struct *list, char *d);
void			ft_printf_u_zero(t_struct *list, char *d);
void			ft_printf_u_precision(t_struct *list, char *d);
void			ft_printf_d_i_prec_width(t_struct *list, char *d);
void			ft_printf_d_i_prec_width_minus(t_struct *list, char *d);
void			ft_printf_d_i_prec_width_minus_aux3\
					(t_struct *list, char *d, size_t w, size_t p);
void			ft_printf_u_prec_width(t_struct *list, char *d);
void			ft_printf_u_prec_width_minus(t_struct *list, char *d);
void			ft_printf_percent(t_struct *list, size_t p);
void			ft_printf_percent_minus(t_struct *list, size_t p);
void			ft_printf_percent_zero(t_struct *list, size_t p);
void			ft_printf_percent_width(t_struct *list, size_t p);
void			ft_printf_pointer(t_struct *list, unsigned long number);
char			*ft_hexa(int number);
void			ft_printf_hexa_upper(t_struct *list, unsigned int h);
void			ft_printf_hexa_width(t_struct *list, char *str);
void			ft_printf_hexa_minus(t_struct *list, char *str);
void			ft_printf_hexa_zero(t_struct *list, char *str);
void			ft_printf_hexa_precision(t_struct *list, char *str);
void			ft_printf_hexa_w_p(t_struct *list, char *str);
void			ft_printf_hexa_w_p_m(t_struct *list, char *str);
void			ft_printf_hexa_w_p_m_aux\
					(t_struct *list, char *str, size_t w, size_t p);
void			ft_printf_hexa_w_p_m_aux2(t_struct *list, char *str, size_t w);
void			ft_printf_hexa(t_struct *list, unsigned int h);
void			ft_printf_hexa_aux(t_struct *list, char *str);
char			*ft_lowercase(char *str);
void			ft_printf_p_width(t_struct *list, char *str);
void			ft_printf_p_minus(t_struct *list, char *str);
void			ft_printf_p_prec(t_struct *list, char *str);
void			ft_printf_p_w_p(t_struct *list, char *str);

#endif
