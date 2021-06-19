#include "libftprintf.h"

int	ft_print_s(t_list *list, va_list *ptr)
{
	char	*str;
	char	*sn;

	sn = "(null)";
	if (list->width_star)
		ft_print_s_part(list, ptr);
	if (list->precision_star)
		list->precision = va_arg(*ptr, int);
	str = va_arg(*ptr, char *);
	if (!list->minus && str == NULL)
		return (ft_string(list->width, list->precision, sn, list->dot));
	if (list->minus && str == NULL)
		return (ft_string_minus(list->width, list->precision, sn, list->dot));
	if (!list->minus && !list->zero)
		return (ft_string(list->width, list->precision, str, list->dot));
	if (list->minus)
		return (ft_string_minus(list->width, list->precision, str, list->dot));
	if (list->zero)
		return (ft_string_zero(list->width, str, list->dot, list->precision));
	return (0);
}

void	ft_print_s_part(t_list *list, va_list *ptr)
{
	list->width = va_arg(*ptr, int);
	if (list->width < 0)
	{
		list->minus = 1;
		list->width *= -1;
	}
}

int	ft_string(int width, int precision, char *str, int dot)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (t == 0)
		len += ftt_putchar(' ', width);
	else if (!dot || t < precision || precision < 0)
	{
		len += ftt_putchar(' ', width - t);
		len += ftt_putstr(str, t);
	}
	else if (dot && !precision)
		len += ftt_putchar(' ', width);
	else
	{
		len += ftt_putchar(' ', width - precision);
		len += ftt_putstr(str, precision);
	}
	return (len);
}

int	ft_string_minus(int width, int precision, char *str, int dot)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (t == 0)
		len += ftt_putchar(' ', width);
	else if (!dot || t < precision || precision < 0)
	{
		len += ftt_putstr(str, t);
		len += ftt_putchar(' ', width - t);
	}
	else if (dot && !precision)
		len += ftt_putchar(' ', width);
	else
	{
		len += ftt_putstr(str, precision);
		len += ftt_putchar(' ', width - precision);
	}
	return (len);
}

int	ft_string_zero(int width, char *str, int dot, int precision)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (dot && !precision)
		len += ftt_putchar('0', width);
	else
	{
		len += ftt_putchar('0', width - t);
		len += ftt_putstr(str, t);
	}
	return (len);
}
