/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:37:00 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/25 11:37:29 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_putenv(char *str)
{
	extern char		**environ;
	char			**tmp;
	int				i;

	i = 0;
	while (environ[i] && ft_strncmp(str, environ[i], ft_strchr(str, '=') - str))
		i++;
	if (!environ[i])
	{
		if (!(tmp = ft_tabnew(i + 1)))
			return (-1);
		tmp[i + 1] = NULL;
		tmp[i] = str;
		while (--i >= 0)
			if (!(tmp[i] = ft_strdup(environ[i])))
				return (-1);
		ft_tabdel(&environ);
		environ = tmp;
	}
	else
	{
		ft_strdel(&environ[i]);
		environ[i] = str;
	}
	return (0);
}
