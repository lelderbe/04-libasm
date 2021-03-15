/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:17:03 by lelderbe          #+#    #+#             */
/*   Updated: 2021/03/15 22:38:51 by lelderbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char * dst, const char * src);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t				ft_read(int fildes, void *buf, size_t nbyte);
char				*ft_strdup(const char *s1);
t_list				*ft_list_create_elem(void *data);
int					ft_list_size(t_list *lst);
//void				ft_list_push_front(t_list **lst, t_list *new);
void				ft_list_push_front(t_list **lst, void *data);

#endif
