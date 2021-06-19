#include "libftprintf.h"

void	ft_pars(t_list *list, char *str, int i)
{
	if (str[i] == '-' && !list->dot)
		list->minus = 1;
	if (str[i] == '0' && !ftt_isdigit(str[i - 1]) && !list->dot && !list->minus)
		list->zero = 1;
	if (str[i] == '*' && !list->dot)
		ft_pars_part1(list);
	if (ftt_isdigit(str[i]) && !list->dot && (str[i - 1] == '%'\
	|| str[i - 1] == '-' || str[i - 1] == '*') && ftt_atoi(str + i) > 0)
		ft_pars_part2(list, str, i);
	if (str[i] == '.')
		list->dot = 1;
	if (ftt_isdigit(str[i]) && list->dot && str[i - 1] == '.')
		list->precision = ftt_atoi(str + i);
	if (ftt_isdigit(str[i]) && list->dot && (str[i - 1] == '-' || \
		str[i - 1] == '*'))
		ft_pars_part2(list, str, i);
	if (str[i] == '*' && list->dot && str[i - 1] == '.')
		list->precision_star = 1;
	if ((ftt_isalpha(str[i])) || str[i] == '%')
		list->type = str[i];
	if (list->minus == 1)
		list->zero = 0;
}

void	ft_pars_part1(t_list *list)
{
	if (list->width)
		list->width = 0;
	list->width_star = 1;
}

void	ft_pars_part2(t_list *list, char *str, int i)
{
	list->width = ftt_atoi(str + i);
	if (list->width_star)
		list->width_star = 0;
}

void	ft_bzero_list(t_list *list)
{
	list->zero = 0;
	list->minus = 0;
	list->width = 0;
	list->width_star = 0;
	list->dot = 0;
	list->precision = 0;
	list->precision_star = 0;
	list->size = 0;
	list->type = 0;
	list->space = 0;
}
