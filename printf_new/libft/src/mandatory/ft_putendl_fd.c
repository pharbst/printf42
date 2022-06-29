/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:46:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/05/17 20:46:26 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	char	c;
	ssize_t	ret;
	ssize_t	ret2;

	c = '\n';
	ret = ft_putstr_fd(s, fd);
	ret2 = write(fd, &c, 1);
	if (ret == -1 || ret2 == -1)
		return (-1);
	return (ret += ret2);
}
