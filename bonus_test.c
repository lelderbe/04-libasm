/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:25:28 by lelderbe          #+#    #+#             */
/*   Updated: 2021/03/15 22:19:28 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <string.h>
#include <stdio.h>
#include <sys/errno.h>

static void	test_ft_list_size(t_list *lst)
{
	printf("count: %d\n", ft_list_size(lst));
}

static void	test_ft_list_push_front(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (lst)
	{
		printf("count before: %d\n", ft_list_size(*lst));
		tmp = *lst;
		printf(".");
		while(tmp)
		{
			printf("-> %s ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
	else
	{
		printf("count before: 0\n");
	}
	ft_list_push_front(lst, new);
	if (lst)
	{
		printf("count after: %d\n", ft_list_size(*lst));
		tmp = *lst;
		printf(".");
		while(tmp)
		{
			printf("-> %s ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n\n");
	}
	else
	{
		printf("count after: 0\n\n");
	}
}

int			main(int argc, char **argv)
{
	t_list	*head;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	t_list	*elem6;
	t_list	*elem7;

	elem1 = malloc(sizeof(t_list));
	elem2 = malloc(sizeof(t_list));
	elem3 = malloc(sizeof(t_list));
	elem4 = malloc(sizeof(t_list));
	elem5 = malloc(sizeof(t_list));
	elem6 = malloc(sizeof(t_list));
	elem1->data = strdup("111");
	elem2->data = strdup("222");
	elem3->data = strdup("333");
	elem4->data = strdup("444");
	elem5->data = strdup("555");
	elem6->data = strdup("666");
	elem7 = ft_list_create_elem(ft_strdup("777"));

	head = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = 0;
	elem4->next = 0;
	elem5->next = 0;
	elem6->next = 0;

	if (argc == 1)
	{
		printf("No argument given. Usage: test.out <ft_test>\n");
		return (0);
	}
	if (strcmp("ft_list_size", argv[1]) == 0)
	{
		test_ft_list_size(head);
		elem3->next = elem4;
		elem4->next = elem5;
		test_ft_list_size(head);
		elem2->next = 0;
		test_ft_list_size(head);
	}
	else if (strcmp("ft_list_push_front", argv[1]) == 0)
	{
		test_ft_list_push_front(&head, elem4);
		test_ft_list_push_front(&head, elem5);
		test_ft_list_push_front(&head, 0);
		test_ft_list_push_front(0, elem6);
		head = 0;
		test_ft_list_push_front(&head, elem6);
		test_ft_list_push_front(&head, elem7);
	}

	return (0);
}
