/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:52:27 by pharbst           #+#    #+#             */
/*   Updated: 2022/06/23 02:44:05 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// int	ft_check(const char **format)
// {
// 	if (format[0][1] == 'X' || format[0][1] == 'x' || format[0][1] == 'd'
// 		|| format[0][1] == 'i' || format[0][1] == 'p' || format[0][1] == 'u'
// 		|| format[0][1] == '%' || format[0][1] == 'c' || format[0][1] == 's')
// 	{
// 		return (0);
// 	}
// 	*format = *format + 1;
// 	return (1);
// }

static ssize_t	ft_strhelp(char *str)
{
	ssize_t	i;

	if (!str)
		i = ft_putstr_fd("(null)", 1);
	else
		i = ft_putstr_fd(str, 1);
	return (i);
}

static ssize_t	ft_ptrhelp(char *str)
{
	char	*ret;
	ssize_t	i;

	ret = ft_strjoin("0x", str);
	i = ft_print_string(ret);
	free(str);
	return (i);
}

static ssize_t	ft_check_parameter(va_list args, const char **format)
{
	if (**format == '%')
		return (ft_putchar_fd('%', 1));
	if (**format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (**format == 's')
		return (ft_strhelp(va_arg(args, char *)));
	if (**format == 'd' || **format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (**format == 'u')
		return (ft_print_string(ft_uitoa(va_arg(args, unsigned int))));
	if (**format == 'p')
		return (ft_ptrhelp(ft_itohex(
					(unsigned long)va_arg(args, void *))));
	if (**format == 'x')
		return (ft_print_string(ft_itohex(va_arg(args, unsigned int))));
	if (**format == 'X')
		return (ft_print_string(ft_strupper(ft_itohex(va_arg(args,
							unsigned int)))));
	return (0);
}

ssize_t	ft_print(const char *format, ssize_t ret, va_list args)
{
	ssize_t	i;

	while (*format)
	{
		if (*format == '%' && format[1] != '\0'
			&& ft_strchr("idupscxX%", format[1]))
		{
			format++;
			i = ft_check_parameter(args, &format);
		}
		else if (*format != '%')
			i = ft_putchar_fd(*format, 1);
		if (i == -1)
			return (-1);
		ret += i;
		format++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	ssize_t	ret;
	va_list	args;

	va_start(args, format);
	ret = 0;
	if (*format == '\0')
		return (0);
	ret = ft_print(format, ret, args);
	return (((int)ret));
}
