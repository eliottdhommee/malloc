/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:33:00 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/25 11:41:55 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_getenv(char *name)
{
	extern char		**environ;
	int				i;
	int				size;

	i = 0;
	size = ft_strlen(name);
	while (environ[i] && !(ft_strnequ(environ[i], name, size) &&
				environ[i][size] == '='))
		i++;
	if (environ[i] != NULL)
		return (&(environ[i][size + 1]));
	return (NULL);
}
