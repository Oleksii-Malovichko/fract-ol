/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:18:52 by alex              #+#    #+#             */
/*   Updated: 2024/12/13 20:26:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int	fd = open("/home/alex/something", O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		printf("\n");
		printf("Error: %s\n", strerror(errno));
	}
    return 0;
}