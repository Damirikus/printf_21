#include "libftprintf.h"

int	ft_print_x(t_list *list, va_list *ptr)
{
	char	arr[1024];
	long	d;
	char	*str;

	d = 0;
	str = &arr[0];
	ftt_bzero(str, 1023);
	if (list->width_star)
		ft_part_x1(list, ptr);
	if (list->precision_star)
		ft_part_x2(list, ptr);
	if (list->type == 'x' || list->type == 'X')
		d = va_arg(*ptr, unsigned int);
	else if (list->type == 'p')
		d = va_arg(*ptr, size_t);
	if (d == 0 && list->type == 'p' && list->dot)
		return (ft_p_nulll(list));
	if (d == 0 && list->type != 'p')
		return (ft_part_x3(list, d));
	ft_converter(d, str, list->type);
	ft_revers(str);
	return (ft_print_x_part(list, str));
	return (0);
}

int	ft_print_x_part(t_list *list, char *str)
{
	if ((!list->minus && !list->zero) || \
		(!list->minus && list->zero && list->dot))
		return (ft_x1(list->width, list->precision, str, list));
	if (list->minus)
		return (ft_x1_minus(list->width, list->precision, str, list));
	if (list->zero && !list->dot)
		return (ft_x1_zero(list->width, str, list->type));
	return (0);
}

void	ft_part_x1(t_list *list, va_list *ptr)
{
	list->width = va_arg(*ptr, int);
	if (list->width < 0)
	{
		list->minus = 1;
		list->width *= -1;
	}
}

void	ft_part_x2(t_list *list, va_list *ptr)
{
	list->precision = va_arg(*ptr, int);
	if (list->precision < 0)
	{
		list->precision = 0;
		list->dot = 0;
	}
}

int	ft_part_x3(t_list *list, long d)
{
	if ((!list->minus && d >= 0 && !list->zero) \
	|| (!list->minus && d >=0 && list->zero && list->dot))
		return (ft_dec(list->width, list->precision, d, list->dot));
	if (list->minus && d >= 0)
		return (ft_dec_minus(list->width, list->precision, d, list->dot));
	if (list->zero && d >= 0 && !list->dot)
		return (ft_dec_zero(list->width, d, list->dot));
	return (0);
}
