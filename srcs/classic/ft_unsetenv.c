/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:37:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/25 11:38:15 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_unsetenv(const char *name)
{
	extern char		**environ;
	int				i;
	int				size;
	int				nb;

	if (!name)
		return (-1);
	nb = 0;
	size = ft_strlen(name);
	i = 0;
	while (environ[i])
	{
		if (ft_strnequ(environ[i], name, size) && environ[i][size] == '=')
		{
			nb = i;
			ft_strdel(&environ[i]);
			while (environ[++nb])
				environ[nb - 1] = environ[nb];
			environ[nb - 1] = environ[nb];
		}
		++i;
	}
	return (0);
}
