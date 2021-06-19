#include "./includes/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	t_list	list;
	int		lenght;

	lenght = 0;
	va_start(ptr, str);
	i = 1;
	while (str[i - 1] != '\0')
	{
		if (str[i - 1] == '%' && str[i] == '%' && i++)
			lenght += ftt_putchar('%', 1);
		else if (str[i - 1] == '%' && str[i] != '%')
		{
			lenght += ft_between(&list, (char *)str, i, &ptr);
			if (lenght == -1)
				return (-1);
			i += for_putchar((char *)str + i - 1);
		}
		else
			lenght += ftt_putchar(str[i - 1], 1);
		i++;
	}
	va_end(ptr);
	return (lenght);
}
