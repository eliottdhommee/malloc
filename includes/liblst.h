/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:08:39 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/14 18:28:27 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H

# include <stdlib.h>

typedef	struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

/*
**	CLASSIC
*/
t_list				*ft_lstnew(void *data);
void				ft_lstadd(t_list **begin_list, void *data);
void				ft_lstaddback(t_list **begin_list, void *data);
void				ft_lstinsert(t_list **lst, void *data,
		int (*cmp)(void*, void*));
int					ft_lstsize(t_list *begin_list);
t_list				*ft_tabtolst(char **tab);
t_list				*ft_lstcpy(t_list *list);
t_list				*ft_lstsplit(t_list *lst, void *dataref,
		int (*cmp)(void*, void*), void (*del)(void*));

/*
** EXTRACT
*/
t_list				*ft_lstsub(t_list **list, int i);
t_list				*ft_lstsubn(t_list **list, int i, int len);

/*
**	DELETION
*/
void				ft_lstdelone(t_list **lst, void (*del)(void*));
void				ft_lstdel(t_list **begin_list, void (*del_item)(void*));
void				ft_deli(t_list **list, unsigned int i, void (*del)(void*));
void				ft_delie(t_list **list, unsigned int i, void (*del)(void*));
void				ft_lstdelif(t_list **lst, void *dataref,
		int (*cmp)(void*, void*), void (*del)(void*));

/*
**	FIND
*/
t_list				*ft_lstlast(t_list *begin_list);
t_list				*ft_lstat(t_list *begin_list, unsigned int nb);
t_list				*ft_lstfind(t_list *begin, void *dataref,
		int (*cmp)(void*, void*));
t_list				*ft_lstfindnext(t_list *begin, void *dataref,
		int (*cmp)(void*, void*));
int					ft_lstfindi(t_list *begin, void *dataref,
		int (*cmp)(void*, void*));

/*
**	SORT
*/
void				ft_lstsort(t_list **lst, int (*cmp)(void*, void*));
void				ft_lstrev(t_list **begin_list);
void				ft_lstiter(t_list *begin_list, void (*f)(t_list *elem));

#endif
