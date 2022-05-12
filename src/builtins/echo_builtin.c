/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:26:03 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/12 11:02:15 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
echo function takes *str as the string to output
and n so n = 1 -> print w/ \n (n = 0 -> print w/o \n)
*/

int	echo_builtin(char *input/*, int n*/)
{
	char	**str;
	char	*nl;
	int		i;
	int		n;

	str = ft_split(input, ' ');
	if ((ft_strncmp(str[1], "-n", 2) == 0))
	{
		n = 0;
		i = 2;
	}
	else
	{
		n = 1;
		i = 1;
	}
	if (n)
		nl = "\n";
	else
		nl = "";
	ft_printf("%s%s", str[i], nl);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}
