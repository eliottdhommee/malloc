/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:36:03 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/25 11:41:08 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_setenv(const char *name, const char *value, int ov)
{
	extern char		**environ;
	int				i;
	int				size;
	char			*tmp;

	i = 0;
	size = ft_strlen(name);
	while (environ[i] && !(ft_strnequ(environ[i], name, size) &&
			environ[i][size] == '='))
		i++;
	if (!environ[i] || ov > 0)
	{
		if (value)
			tmp = ft_strcjoin(name, value, '=');
		else
			tmp = ft_strjoin(name, "=");
		if (!tmp)
			return (-1);
		return (ft_putenv(tmp));
	}
	return (0);
}
