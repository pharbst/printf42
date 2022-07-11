/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:20:09 by peter             #+#    #+#             */
/*   Updated: 2022/07/01 03:20:41 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int		ft_printf(const char *format, ...);
t_buff	ft_printc(int c, t_buff buff);
t_buff	ft_prints(char *str, t_buff buff);
t_buff	ft_printi(int nbr, t_buff buff);
t_buff	ft_printu(unsigned int nbr, t_buff buff);
t_buff	ft_printx(unsigned long nbr, t_buff buff);
t_buff	ft_printux(unsigned long nbr, t_buff buff);
t_buff	ft_printp(unsigned long ptr, t_buff buff);

#endif
