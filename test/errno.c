/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:38:14 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/15 17:02:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	malloc(999999999999);
	perror("error");
	printf("%i\n", errno);
	errno = 41;
	perror("error");
	printf("%i\n", errno);
	return (0);
}
