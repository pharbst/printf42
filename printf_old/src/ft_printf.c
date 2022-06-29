/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:06 by pharbst           #+#    #+#             */
/*   Updated: 2022/06/23 06:15:26 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_check(const char **format)
{
	if (format[0][1] == 'X' || format[0][1] == 'x' || format[0][1] == 'd'
		|| format[0][1] == 'i' || format[0][1] == 'p' || format[0][1] == 'u'
		|| format[0][1] == '%' || format[0][1] == 'c' || format[0][1] == 's')
	{
		return (0);
	}
	(*format)++;
	//*format = *format + 1;
	return (1);
}

static char	*ft_strhelp(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

static char	*ft_ptrhelp(char *str)
{
	char	*ret;

	ret = ft_strjoin("0x", str);
	free(str);
	return (ret);
}

int	ft_check_parameter(va_list args, const char **format, char **buff,
	int buff_len)
{
	if (**format == '%')
		return (ft_bufferjoin(buff, ft_strdup("%"), buff_len, 1));
	if (**format == 'c')
		return (ft_bufferjoin(buff, ft_chartostr(va_arg(args, int)),
				buff_len, 1));
	if (**format == 's')
		return (ft_bufferjoin(buff, ft_strhelp(va_arg(args, char *)),
				buff_len, 0));
	if (**format == 'd' || **format == 'i')
		return (ft_bufferjoin(buff, ft_itoa(va_arg(args, int)), buff_len, 0));
	if (**format == 'u')
		return (ft_bufferjoin(buff, ft_uitoa(va_arg(args, unsigned int)),
				buff_len, 0));
	if (**format == 'p')
		return (ft_bufferjoin(buff, ft_ptrhelp(ft_itohex(
						(unsigned long)va_arg(args, void *))), buff_len, 0));
	if (**format == 'x')
		return (ft_bufferjoin(buff, ft_itohex(va_arg(args, unsigned int)),
				buff_len, 0));
	if (**format == 'X')
		return (ft_bufferjoin(buff, ft_strupper(ft_itohex(va_arg(args,
							unsigned int))), buff_len, 0));
	return (buff_len);
}

int	ft_printf(const char *format, ...)
{
	char	*buff;
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = 0;
	buff = NULL;
	if (*format == '\0')
		return (0);
	while (*format)
	{
		if (*format == '%' && format[1] != '\0' && ft_check(&format) == 0)
		{
			format++;
			ret = ft_check_parameter(args, &format, &buff, ret);
		}
		else if (*format != '%')
			ret = ft_bufferjoin(&buff, ft_chartostr(*format), ret, 1);
		format++;
	}
	write(1, buff, ret);
	free(buff);
	return (ret);
}
