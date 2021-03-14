/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:05:30 by lelderbe          #+#    #+#             */
/*   Updated: 2021/03/14 19:04:07 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <stdio.h>

static void	test_strlen(const char *s)
{
	printf("   strlen(\"%s\"): %zu\n", s, strlen(s));
	printf("ft_strlen(\"%s\"): %zu\n", s, ft_strlen(s));
}

static void	test_strcmp(const char *s1, const char *s2)
{
	printf("   strcmp(\"%s\", \"%s\"): %d\n", s1, s2, strcmp(s1, s2));
	printf("ft_strcmp(\"%s\", \"%s\"): %d\n", s1, s2, ft_strcmp(s1, s2));
}

static void	test_strcpy(char *dst, const char *src)
{
	char	*expect;
	char	*result;
	
	expect = strdup(dst);
	result = strdup(dst);
	strcpy(expect, src);
	printf("   strcpy(\"%s\", \"%s\"): \"%s\"\n", dst, src, expect);
	ft_strcpy(result, src);
	printf("ft_strcpy(\"%s\", \"%s\"): \"%s\"\n", dst, src, result);
}

int			main(void)
{
	test_strlen("abc");
	test_strlen("");
	test_strcmp("abc", "abc");
	test_strcmp("Abc", "abc");
	test_strcmp("abc", "abc123");
	test_strcmp("abc", "abC");
	test_strcpy("123456789", "abc");
	test_strcpy("123456789", "");
	test_strcpy("123456789", "AAA");
	test_strcpy("12", "ZZZ");
	return (0);
}
