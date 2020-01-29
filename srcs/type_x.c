#include "ft_printf.h"

int		f_x(va_list ap, t_spec info)
{
	char *str;
	int		count;

	count = 0;
	if (ft_strequ(info.taille, "l"))
		str = ft_hex((long)va_arg(ap, long));
	else if (ft_strequ(info.taille, "h"))
		str = ft_hex((unsigned short int)va_arg(ap, unsigned int));
	else if (ft_strequ(info.taille, "hh"))
		str = ft_hex((unsigned char)(va_arg(ap, unsigned int)));
	else if (ft_strequ(info.taille, "ll"))
		str = ft_hex((long long)va_arg(ap, long long));
	else
		str = ft_hex(va_arg(ap, unsigned int));
	if (!str)
		return (-1);
	if ((ft_atoi(str) == 0 || (str[0] >= 'a' && str[0] <= 'f'))
	&& info.precision == 0)
		convert_x_bigx_zero_prec(&info, &count);
	else
		convert_x(str, &info, &count);
	free(str);
	return (count);
}

void	convert_x(char *str, t_spec *info, int *count)
{
	int len;
	int fill;

	len = ft_strlen(str);
	count = 0;
	fill = (info->f_hash) ? 2 : 0;
	if (info->width)
		get_width(info, len, fill);
	
}

void	convert_x_bigx_zero_prec(t_spec *info, int *count)
{
	char *fill;

	fill = (info->f_hash) ? "0x" : "";

}
