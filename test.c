/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:05:30 by lelderbe          #+#    #+#             */
/*   Updated: 2021/03/15 22:22:11 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <stdio.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <limits.h>

static void	test_strlen(const char *s)
{
	printf("ft_strlen(\"%s\"): %zu\n", s, ft_strlen(s));
	printf("   strlen(\"%s\"): %zu\n", s, strlen(s));
}

static void	test_strcmp(const char *s1, const char *s2)
{
	printf("ft_strcmp(\"%s\", \"%s\"): %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("   strcmp(\"%s\", \"%s\"): %d\n", s1, s2, strcmp(s1, s2));
}

static void	test_strcpy(char *dst, const char *src)
{
	char	*expect;
	char	*result;
	
	expect = strdup(dst);
	result = strdup(dst);
	ft_strcpy(result, src);
	printf("ft_strcpy(\"%s\", \"%s\"): \"%s\"\n", dst, src, result);
	strcpy(expect, src);
	printf("   strcpy(\"%s\", \"%s\"): \"%s\"\n", dst, src, expect);
}

static void	test_write(int fd, const char *s)
{
	ssize_t result;

	errno = 0;
	printf("-------ft_write---------------------\n");
	printf("ft_write(fd = %d, \"%s\"):\n", fd, s);
	result = ft_write(fd, s, ft_strlen(s));
	printf("\n Result: %zd, errno: %d, err msg: %s\n", result, errno, strerror(errno));
	errno = 0;
	printf("-------write------------------------\n");
	printf("   write(fd = %d, \"%s\"):\n", fd, s);
	result = write(fd, s, strlen(s));
	printf("\n Result: %zd, errno: %d, err msg: %s\n\n", result, errno, strerror(errno));
}

static void test_read(int fd, char *buf, int count)
{
	ssize_t result;

	errno = 0;
	printf("-------read--------------------------\n");
	printf("   read(fd = %d, count = %d):\n", fd, count);
	result = read(fd, buf, count);
	printf("data: %s\n", buf);
	printf("Result: %zd, errno: %d, err msg: %s\n\n", result, errno, strerror(errno));
}

static void test_ft_read(int fd, char *buf, int count)
{
	ssize_t result;

	errno = 0;
	printf("-------ft_read----------------------\n");
	printf("ft_read(fd = %d, count = %d):\n", fd, count);
	result = ft_read(fd, buf, count);
	printf("data: %s\n", buf);
	printf("Result: %zd, errno: %d, err msg: %s\n", result, errno, strerror(errno));
}

static void	test_strdup(const char *s)
{
	char	*expect;
	char	*result;

	printf("source: '%s', addr: %p\n", s, s);
	errno = 0;
	printf("-------ft_strdup--------------------\n");
	result = ft_strdup(s);
	printf("result: '%s', addr: %p\n", result, result);
	printf("errno: %d, err msg: %s\n", errno, strerror(errno));

	errno = 0;
	printf("-------strdup-----------------------\n");
	expect = strdup(s);
	printf("expect: '%s', addr: %p\n", expect, expect);
	printf("errno: %d, err msg: %s\n\n", errno, strerror(errno));
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[21] = {0};

	if (argc == 1)
	{
		printf("No argument given. Usage: test.out <ft_test>\n");
		return (0);
	}
	if (strcmp("ft_strlen", argv[1]) == 0)
	{
		test_strlen("abc");
		test_strlen("");
		test_strlen("A value of AUE_NULL means no auditing, but it also means that there is no audit event for the call at this time. For the case where the event exists, but we don't want auditing, the event should be #defined to AUE_NULL in audit_kevents.h.");
	}
	else if (strcmp("ft_strcmp", argv[1]) == 0)
	{
		test_strcmp("", "");
		test_strcmp("", "abc");
		test_strcmp("abc", "");
		test_strcmp("abc", "abc");
		test_strcmp("Abc", "abc");
		test_strcmp("abc", "abc123");
		test_strcmp("abc", "abC");
	}
	else if (strcmp("ft_strcpy", argv[1]) == 0)
	{
		test_strcpy("", "");
		test_strcpy("123456789", "abc");
		test_strcpy("123456789", "");
		test_strcpy("123456789", "AAA");
		test_strcpy("12", "ZZZ");
		test_strcpy("A value of AUE_NULL means no auditing, but it also means that there is no audit event for the call at this time. For the case where the event exists, but we don't want auditing, the event should be #defined to AUE_NULL in audit_kevents.h.", "**************************************************************************#*");
	}
	else if (strcmp("ft_write", argv[1]) == 0)
	{
		test_write(1, "abc12345");
		test_write(-2, "abc12345");
		test_write(1, "abc12345");
		fd = open("test.txt", O_WRONLY);
		test_write(fd, "**********#*");

	}
	else if (strcmp("ft_read", argv[1]) == 0)
	{
		fd = open("test.txt", O_RDONLY);
		test_ft_read(fd, buf, 5);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_read(fd, buf, 5);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_ft_read(fd, buf, 0);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_read(fd, buf, 0);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_ft_read(-2, buf, 5);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_read(-2, buf, 5);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_ft_read(fd, buf, 20);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_read(fd, buf, 20);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_ft_read(fd, buf, -5);
		close(fd);
		bzero(buf, 20);

		fd = open("test.txt", O_RDONLY);
		test_read(fd, buf, -5);
		close(fd);
		bzero(buf, 20);

		test_ft_read(0, buf, 5);
		test_read(0, buf, 5);
	}
	else if (strcmp("ft_strdup", argv[1]) == 0)
	{
		//char *b = malloc(-1);
		//printf("b: %p\n", b);
		//printf("errno: %d, err msg: %s\n", errno, strerror(errno));

		test_strdup("abc");
		test_strdup("A value of AUE_NULL means no auditing, but it also means that there is no audit event for the call at this time. For the case where the event exists, but we don't want auditing, the event should be #defined to AUE_NULL in audit_kevents.h.");
		test_strdup("");
	}

	return (0);
}
