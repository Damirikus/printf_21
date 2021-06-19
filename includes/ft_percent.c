#include "libftprintf.h"

int	ft_print_per(t_list *list, va_list *ptr)
{
	if (list->width_star)
	{
		list->width = va_arg(*ptr, int);
		if (list->width < 0)
		{
			list->minus = 1;
			list->width *= -1;
		}
	}
	if (!list->minus && !list->zero)
		return (ft_per(list->width));
	if (list->minus)
		return (ft_per_minus(list->width));
	if (list->zero)
		return (ft_per_zero(list->width));
	return (0);
}

int	ft_per(int width)
{
	int	len;

	len = 0;
	len += ftt_putchar(' ', (width - 1));
	len += ftt_putchar('%', 1);
	return (len);
}

int	ft_per_minus(int width)
{
	int	len;

	len = 0;
	len += ftt_putchar('%', 1);
	len += ftt_putchar(' ', (width - 1));
	return (len);
}

int	ft_per_zero(int width)
{
	int	len;

	len = 0;
	len += ftt_putchar('0', width - 1);
	len += ftt_putchar('%', 1);
	return (len);
}
