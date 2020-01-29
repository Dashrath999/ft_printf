#include "ft_printf.h"

int		f_c(va_list ap, t_spec info)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(ap, int);
	convert_c(c, &info, &count);
	return (count);
}

void	convert_c(char c, t_spec *info, int *count)
{
	if (info->width)
		info->width--;
	if (info->width && !info->f_minus)
		print_width(info, count);
	ft_putchar(c);
	*count = *count + 1;
	if (info->width && info->f_minus)
		print_width(info, count);
	return;
}
