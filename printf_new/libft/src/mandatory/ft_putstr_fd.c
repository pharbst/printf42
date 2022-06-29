/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:46:39 by pharbst           #+#    #+#             */
/*   Updated: 2022/05/17 20:46:39 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

ssize_t	ft_putstr_fd(char const *s, int fd)
{
	ssize_t	ret;
	long	ret2;

	ret2 = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		ret = ft_putchar_fd(*s++, fd);
		if (ret == -1)
			return (-1);
		ret2 += ret;
	}
	return (ret2);
}
