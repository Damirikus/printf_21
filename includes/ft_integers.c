#include "libftprintf.h"

int	ft_print_d(t_list *list, va_list *ptr)
{
	long	d;

	if (list->width_star)
		ft_part_d1(list, ptr);
	if (list->precision_star)
		ft_part_d2(list, ptr);
	d = va_arg(*ptr, int);
	if ((!list->minus && d >= 0 && !list->zero) \
	|| (!list->minus && d >=0 && list->zero && list->dot))
		return (ft_dec(list->width, list->precision, d, list->dot));
	if (list->minus && d >= 0)
		return (ft_dec_minus(list->width, list->precision, d, list->dot));
	if (list->zero && d >= 0 && !list->dot)
		return (ft_dec_zero(list->width, d, list->dot));
	if ((!list->minus && d < 0 && !list->zero) \
	|| (!list->minus && d < 0 && list->zero && list->dot))
		return (ft_dec_neg(list->width, list->precision, d));
	if (list->minus && d < 0)
		return (ft_dec_minus_neg(list->width, list->precision, d));
	if (list->zero && d < 0 && !list->dot)
		return (ft_dec_zero_neg(list->width, d));
	return (0);
}

void	ft_part_d1(t_list *list, va_list *ptr)
{
	list->width = va_arg(*ptr, int);
	if (list->width < 0)
	{
		list->minus = 1;
		list->width *= -1;
	}
}

void	ft_part_d2(t_list *list, va_list *ptr)
{
	list->precision = va_arg(*ptr, int);
	if (list->precision < 0)
	{
		list->precision = 0;
		list->dot = 0;
	}
}

int	ft_dec(int width, int precision, long d, int dot)
{
	int	t;
	int	len;

	len = 0;
	t = ft_cast_putnbr(d);
	if (d == 0 && dot && !precision)
	{
		len += ftt_putchar(' ', width);
		return (len);
	}
	if (!precision || precision <= t)
		len += ftt_putchar(' ', width - t);
	else
		len += ftt_putchar(' ', (width - t - (precision - t)));
	len += ftt_putchar('0', precision - t);
	len += ftt_putnbr(d);
	return (len);
}
