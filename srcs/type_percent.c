#include "ft_printf.h"

int		f_percent(va_list ap, t_spec info)
{
	(void)ap;
	int		count;

	count = 1;
	if (info.width)
		info.width -= 1;
	if (!info.f_minus && info.width > 0)
		print_width(&info, &count);
	ft_putchar('%');
	if (info.f_minus && info.width > 0)
		print_width(&info, &count);
	return (count);
}
