#include "libftprintf.h"

int	ft_dec_minus(int width, int precision, long d, int dot)
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
	{
		len += ftt_putnbr(d);
		len += ftt_putchar(' ', width - t);
	}
	else
	{
		len += ftt_putchar('0', precision - t);
		len += ftt_putnbr(d);
		len += ftt_putchar(' ', (width - t - (precision - t)));
	}
	return (len);
}

int	ft_dec_zero(int width, long d, int dot)
{
	int	t;
	int	len;

	len = 0;
	t = ft_cast_putnbr(d);
	if (d == 0 && !dot && width)
	{
		ftt_putchar('0', width);
		return (width);
	}
	len += ftt_putchar('0', width - t);
	len += ftt_putnbr(d);
	return (len);
}

int	ft_dec_neg(int width, int precision, long d)
{
	int	t;
	int	len;

	d *= -1;
	len = 0;
	t = ft_cast_putnbr(d);
	if (!precision || precision <= t)
		len += ftt_putchar(' ', width - t - 1);
	else
		len += ftt_putchar(' ', (width - t - 1 - (precision - t)));
	len += ftt_putchar('-', 1);
	len += ftt_putchar('0', precision - t);
	len += ftt_putnbr(d);
	return (len);
}

int	ft_dec_minus_neg(int width, int precision, long d)
{
	int	t;
	int	len;

	d *= -1;
	len = 0;
	t = ft_cast_putnbr(d);
	if (!precision || precision <= t)
	{
		len += ftt_putchar('-', 1);
		len += ftt_putnbr(d);
		len += ftt_putchar(' ', width - t - 1);
	}
	else
	{
		len += ftt_putchar('-', 1);
		len += ftt_putchar('0', precision - t);
		len += ftt_putnbr(d);
		len += ftt_putchar(' ', (width - t - 1 - (precision - t)));
	}
	return (len);
}

int	ft_dec_zero_neg(int width, long d)
{
	int	t;
	int	len;

	d *= -1;
	len = 0;
	t = ft_cast_putnbr(d);
	len += ftt_putchar('-', 1);
	len += ftt_putchar('0', width - t - 1);
	len += ftt_putnbr(d);
	return (len);
}
