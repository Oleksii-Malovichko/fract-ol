/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:38:11 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/09 15:03:24 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
	{
		return (1);
	}
	return (0);
}

/* int main()
{
    printf("%d\n", ft_isdigit('1'));
    printf("%d\n", isdigit('7'));
} */