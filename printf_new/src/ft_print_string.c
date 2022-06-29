/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:06:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/06/23 02:12:08 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_print_string(char *str)
{
	ssize_t	ret;

	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}
