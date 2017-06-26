/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:36:50 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 18:06:54 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_print
{
	int					minus;
	int					plus;
	int					mn_pl;
	int					resh;
	int					nolik;
	int					prob;
	int					to4;
	char				type;
	char				sss;
	int					mod;
	void				*arg;
	char				*ret;
	int					is_s;
	int					is_c_n;
	int					is_s_n;
	int					e;
	int					count;
}						t_print;

int						ft_printf(char *str, ...);
void					read_flag(char c, t_print **my);
int						ft_atoi(char *str, int *i);
void					add_char(t_print **my, char c);
void					init_my(t_print **my);
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlen(const char *s);
char					*ft_put_nbr(int n);
char					*ft_put_lnbr(long n);
char					*ft_strnew(size_t size);
int						read_args(t_print **my, va_list args);
char					*ft_get_hex(unsigned int nb, char c, int base);
char					*ft_put_unbr(unsigned int n);
void					take_mod(char *str, t_print **my);
int						is_mod(char c);
int						is_digit(char c);
int						is_type(char c);
int						is_flag(char c);
char					*ft_get_lhex(unsigned long nb, char c, int base);
char					*ft_put_ulnbr(unsigned long n);
void					use_flag(t_print **my);
char					*ft_strdup(const char *s);
void					make_p(t_print **my);
void					cut_str(t_print **my);
void					make_resh(t_print **my);
void					make_prob(t_print **my);
void					last_if(t_print **my, int m, char *buff);
void					if_c(va_list args, t_print **my, int *b, char **str);
void					make_b(t_print **my, char **str);

#endif
