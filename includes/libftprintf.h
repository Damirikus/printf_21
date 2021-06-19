#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <fcntl.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *str, int ch);

typedef struct s_list
{
	int		zero;
	int		minus;
	int		width;
	int		width_star;
	int		dot;
	int		precision;
	int		precision_star;
	int		size;
	char	type;
	int		space;
}			t_list;

void	ft_bzero_list(t_list *list);
int		ftt_putchar(char c, int i);
int		ft_between(t_list *list, char *str, int i, va_list *ptr);
void	ft_pars(t_list *list, char *str, int i);
int		ftt_isalpha(int c);
int		ftt_isdigit(int c);
int		ftt_atoi(const char *str);
int		ft_distributor(t_list *list, va_list *ptr);
int		ft_print_d(t_list *list, va_list *ptr);
int		for_putchar(char *str);
int		ft_dec(int width, int precision, long d, int dot);
int		ftt_putnbr(long n);
int		ft_cast_putnbr(long n);
int		ft_dec_minus(int width, int precision, long d, int dot);
int		ft_dec_zero(int width, long d, int dot);
int		ft_dec_neg(int width, int precision, long d);
int		ft_dec_minus_neg(int width, int precision, long d);
int		ft_dec_zero_neg(int width, long d);
int		ft_print_s(t_list *list, va_list *ptr);
int		ftt_strlen(char *str);
int		ft_string(int width, int precision, char *str, int dot);
int		ftt_putstr(char *s, int len);
int		ft_string_minus(int width, int precision, char *str, int dot);
int		ft_print_c(t_list *list, va_list *ptr);
int		ft_char(int width, char sym);
int		ft_char_minus(int width, char sym);
int		ft_print_u(t_list *list, va_list *ptr);
void	ftt_bzero(void *s, size_t n);
void	ft_converter(long d, char *str, char type);
int		ft_print_x(t_list *list, va_list *ptr);
void	ft_revers(char *str);
int		ft_x1(int width, int precision, char *str, t_list *list);
int		ft_x1_minus(int width, int precision, char *str, t_list *list);
int		ft_x1_zero(int width, char *str, char type);
int		ft_print_per(t_list *list, va_list *ptr);
int		ft_per(int width);
int		ft_per_minus(int width);
int		ft_per_zero(int width);
int		ft_string_zero(int width, char *str, int dot, int precision);
int		ft_p_nulll(t_list *list);
int		ft_p1_null(int width, int precision);
int		ft_p2_null(int width, int precision);
void	ft_part_d1(t_list *list, va_list *ptr);
void	ft_part_d2(t_list *list, va_list *ptr);
void	ft_part_u1(t_list *list, va_list *ptr);
void	ft_part_u2(t_list *list, va_list *ptr);
void	ft_part_x1(t_list *list, va_list *ptr);
void	ft_part_x2(t_list *list, va_list *ptr);
int		ft_part_x3(t_list *list, long d);
int		ft_x1_minus_part(int width, int precision, char *str, t_list *list);
char	ft_converter_part(long g, char type);
void	ft_pars_part1(t_list *list);
void	ft_pars_part2(t_list *list, char *str, int i);
int		ft_print_x_part(t_list *list, char *str);
void	ft_print_s_part(t_list *list, va_list *ptr);
#endif