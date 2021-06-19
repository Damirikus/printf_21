#include "libftprintf.h"

int	ft_p_nulll(t_list *list)
{
	if (!list->minus)
		return (ft_p1_null(list->width, list->precision));
	return (ft_p2_null(list->width, list->precision));
}

void	ft_converter(long d, char *str, char type)
{
	char	c;
	long	g;
	int		i;

	i = 0;
	while (d / 16)
	{
		g = d % 16;
		if (g > 9 && g < 16)
			c = ft_converter_part(g, type);
		else
			c = g + 48;
		str[i] = c;
		d /= 16;
		i++;
	}
	g = d % 16;
	if (g > 9 && g < 16)
		c = ft_converter_part(g, type);
	else
		c = g + 48;
	str[i] = c;
}

char	ft_converter_part(long g, char type)
{
	char	c;

	if (type == 'x' || type == 'p')
		c = g + 87;
	else
		c = g + 55;
	return (c);
}

void	ft_revers(char *str)
{
	int		len;
	char	temp;
	int		i;

	i = 0;
	len = ftt_strlen(str);
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

int	ft_x1(int width, int precision, char *str, t_list *list)
{
	int	t;
	int	len;

	len = 0;
	t = ftt_strlen(str);
	if (!precision || precision <= t)
	{
		if (list->type == 'p')
			len += ftt_putchar(' ', width - t - 2);
		else
			len += ftt_putchar(' ', width - t);
	}
	else
		len += ftt_putchar(' ', (width - t - (precision - t)));
	if (list->type == 'p')
		len += ftt_putstr("0x", 2);
	len += ftt_putchar('0', precision - t);
	len += ftt_putstr(str, t);
	return (len);
}
