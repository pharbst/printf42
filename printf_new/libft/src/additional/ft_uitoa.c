/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:41:41 by pharbst           #+#    #+#             */
/*   Updated: 2022/05/20 21:54:58 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_reverse(char *a)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(a);
	str = malloc((len) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
		str[i++] = a[len];
	str[i] = '\0';
	return (str);
}

static char	*ft_420(unsigned int n)
{
	char	a[11];
	char	digit;
	int		i;

	i = 0;
	while (n > 0)
	{
		digit = n % 10;
		n /= 10;
		a[i++] = digit + '0';
	}
	a[i] = '\0';
	return (ft_reverse(a));
}

char	*ft_uitoa(unsigned int n)
{
	char	*retstr;

	if (n == 0)
		return (ft_strdup("0"));
	retstr = ft_420(n);
	return (retstr);
}
