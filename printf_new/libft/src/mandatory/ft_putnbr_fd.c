/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:46:32 by pharbst           #+#    #+#             */
/*   Updated: 2022/05/17 20:46:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	ssize_t	ret;

	str = ft_itoa(n);
	ret = ft_putstr_fd(str, fd);
	return (free(str), ret);
}
