/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:06 by pharbst           #+#    #+#             */
/*   Updated: 2022/05/24 23:17:10 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <printf.h>

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
	return (0);
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
		if (*format == '%')
		{
			format++;
			ret = ft_check_parameter(args, &format, &buff, ret);
		}
		else
			ret = ft_bufferjoin(&buff, ft_chartostr(*format), ret, 1);
		format++;
	}
	write(1, buff, ret);
	free(buff);
	return (ret);
}
