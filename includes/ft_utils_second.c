#include "libftprintf.h"

int	ftt_putnbr(long n)
{
	int		len;
	char	r;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 10)
		len += ftt_putnbr(nb / 10);
	r = nb % 10 + 48;
	len += ftt_putchar(r, 1);
	return (len);
}

int	ft_cast_putnbr(long n)
{
	int	h;

	h = 0;
	while (n >= 10)
	{
		n = (n / 10);
		h++;
	}
	h++;
	return (h);
}

int	ftt_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ftt_putstr(char *s, int len)
{
	int	i;

	i = 0;
	if (s)
	{
		while (len > 0)
		{
			write(1, &s[i], 1);
			i++;
			len--;
		}
	}
	return (i);
}
