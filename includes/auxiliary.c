#include "libftprintf.h"

int	for_putchar(char *str)
{
	int	j;

	j = 0;
	while (!ftt_isalpha(str[j]))
	{
		j++;
		if (str[j] == '%')
			break ;
	}
	return (j);
}

int	ft_between(t_list *list, char *str, int i, va_list *ptr)
{
	ft_bzero_list(list);
	while (!(ftt_isalpha(str[i])))
	{
		if (str[i] == '\0')
			return (-1);
		if (str[i] == '%')
			break ;
		ft_pars(&(*list), str, i);
		i++;
	}
	ft_pars(list, str, i);
	return (ft_distributor(list, ptr));
}

int	ft_distributor(t_list *list, va_list *ptr)
{
	int	len_print;

	len_print = 0;
	if (list->type == 'd' || list->type == 'i')
		len_print = ft_print_d(list, ptr);
	else if (list->type == 's')
		len_print = ft_print_s(list, ptr);
	else if (list->type == 'c')
		len_print = ft_print_c(list, ptr);
	else if (list->type == 'u')
		len_print = ft_print_u(list, ptr);
	else if (list->type == 'x' || list->type == 'p' || list->type == 'X')
		len_print = ft_print_x(list, ptr);
	else if (list->type == '%')
		len_print = ft_print_per(list, ptr);
	else
		return (-1);
	return (len_print);
}
