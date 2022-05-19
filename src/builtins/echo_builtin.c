/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:26:03 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/19 12:24:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
echo function takes *str as the string to output
and n so n = 1 -> print w/ \n (n = 0 -> print w/o \n)
*/

int	echo_builtin(t_data *data, int i)
{
	char	*nl;
	char	*ret;
	int		n;

	if ((ft_strncmp(get_n_lst(data->Tokens, i + 1)->content->val, "-n", 2) == 0))
	{
		n = 0;
		i += 2;
	}
	else
	{
		n = 1;
		i += 1;
	}
	if (n)
		nl = "\n";
	else
		nl = "";
	ret = catch_env_var(get_n_lst(data->Tokens, i)->content->val, data->my_env);
	if (ret != NULL)
		ft_printf("%s%s", ret, nl);
	else
		ft_printf("%s%s", get_n_lst(data->Tokens, i)->content->val, nl);
	i = -1;
	return (0);
}
