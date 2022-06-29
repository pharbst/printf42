/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:41:29 by pharbst           #+#    #+#             */
/*   Updated: 2022/06/13 20:56:47 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strlower(char *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (NULL);
	while (str[n])
	{
		str[n] = ft_tolower((int) str[n]);
		n++;
	}
	return (str);
}
