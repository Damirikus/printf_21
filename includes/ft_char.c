#include "libftprintf.h"

int	ft_print_c(t_list *list, va_list *ptr)
{
	char	sym;

	if (list->width_star)
	{
		list->width = va_arg(*ptr, int);
		if (list->width < 0)
		{
			list->minus = 1;
			list->width *= -1;
		}
	}
	if (list->precision_star)
		list->precision = va_arg(*ptr, int);
	sym = va_arg(*ptr, int);
	if (!list->minus)
		return (ft_char(list->width, sym));
	if (list->minus)
		return (ft_char_minus(list->width, sym));
	return (0);
}

int	ft_char(int width, char sym)
{
	int	len;

	len = 0;
	len += ftt_putchar(' ', width - 1);
	len += ftt_putchar(sym, 1);
	return (len);
}

int	ft_char_minus(int width, char sym)
{
	int	len;

	len = 0;
	len += ftt_putchar(sym, 1);
	len += ftt_putchar(' ', width - 1);
	return (len);
}
