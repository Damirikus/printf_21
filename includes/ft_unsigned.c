#include "libftprintf.h"

int	ft_print_u(t_list *list, va_list *ptr)
{
	long	d;

	if (list->width_star)
		ft_part_u1(list, ptr);
	if (list->precision_star)
		ft_part_u2(list, ptr);
	d = va_arg(*ptr, unsigned int);
	if ((!list->minus && d >= 0 && !list->zero) || \
		(!list->minus && d >=0 && list->zero && list->dot))
		return (ft_dec(list->width, list->precision, d, list->dot));
	if (list->minus && d >= 0)
		return (ft_dec_minus(list->width, list->precision, d, list->dot));
	if (list->zero && d >= 0 && !list->dot)
		return (ft_dec_zero(list->width, d, list->dot));
	if ((!list->minus && d < 0 && !list->zero) || \
		(!list->minus && d < 0 && list->zero && list->dot))
		return (ft_dec_neg(list->width, list->precision, d));
	if (list->minus && d < 0)
		return (ft_dec_minus_neg(list->width, list->precision, d));
	if (list->zero && d < 0 && !list->dot)
		return (ft_dec_zero_neg(list->width, d));
	return (0);
}

void	ft_part_u1(t_list *list, va_list *ptr)
{
	list->width = va_arg(*ptr, int);
	if (list->width < 0)
	{
		list->minus = 1;
		list->width *= -1;
	}
}

void	ft_part_u2(t_list *list, va_list *ptr)
{
	list->precision = va_arg(*ptr, int);
	if (list->precision < 0)
	{
		list->precision = 0;
		list->dot = 0;
	}
}
