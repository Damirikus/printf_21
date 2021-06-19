#include "libftprintf.h"

int	ft_x1_minus(int width, int precision, char *str, t_list *list)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (!precision || precision <= t)
	{
		if (list->type == 'p')
		{
			len += ftt_putstr("0x", 2);
			len += ftt_putstr(str, t);
			len += ftt_putchar(' ', width - t - 2);
		}
		else
		{
			len += ftt_putstr(str, t);
			len += ftt_putchar(' ', width - t);
		}
	}
	else
		len += ft_x1_minus_part(width, precision, str, list);
	return (len);
}

int	ft_x1_minus_part(int width, int precision, char *str, t_list *list)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (list->type == 'p')
	{
		len += ftt_putstr("0x", 2);
		len += ftt_putchar('0', precision - t);
		len += ftt_putstr(str, t);
		len += ftt_putchar(' ', (width - t - 2 - (precision - t)));
	}
	else
	{
		len += ftt_putchar('0', precision - t);
		len += ftt_putstr(str, t);
		len += ftt_putchar(' ', (width - t - (precision - t)));
	}
	return (len);
}

int	ft_x1_zero(int width, char *str, char type)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (type == 'p')
	{
		len += ftt_putstr("0x", 2);
		len += ftt_putchar('0', width - t - 2);
	}
	else
		len += ftt_putchar('0', width - t);
	len += ftt_putstr(str, t);
	return (len);
}

int	ft_p1_null(int width, int precision)
{
	int	len;

	len = 0;
	if (!precision)
	{
		len += ftt_putchar(' ', width - 2);
		len += ftt_putstr("0x", 2);
	}
	else
	{
		len += ftt_putstr("0x", 2);
		len += ftt_putchar(' ', (width - 2 - precision));
		len += ftt_putchar('0', precision);
	}
	return (len);
}

int	ft_p2_null(int width, int precision)
{
	int	len;

	len = 0;
	if (!precision)
	{
		len += ftt_putstr("0x", 2);
		len += ftt_putchar(' ', width - 2);
	}
	else
	{
		len += ftt_putstr("0x", 2);
		len += ftt_putchar('0', precision);
		len += ftt_putchar(' ', (width - 2 - precision));
	}
	return (len);
}
