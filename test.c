/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:05:30 by lelderbe          #+#    #+#             */
/*   Updated: 2021/03/12 15:16:57 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <stdio.h>

int		main(void)
{
	printf("%zu\n", strlen("abc"));
	printf("%zu\n", ft_strlen("abc"));

	return (0);
}
