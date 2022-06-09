/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/09 14:07:03 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_varenv(/*t_data *data, */int i)
{
	int		j;
	char	**spl;
	char	*exp;
	int		k;
	int		t;

	j = 0;
	spl = NULL;
	if (!get_n_lst(data.Tokens, i + 1))
		return ;
	exp = get_n_lst(data.Tokens, i + 1)->content->val;
	while (data.my_env[j])
	{
		spl = ft_split(data.my_env[j], '=');
		t = 0;
		while (exp[ft_strlen(spl[0]) + t] == ' ')
			t++;
		if (exp[ft_strlen(spl[0]) + t] == '=' && t)
			return ;
		if (!ft_strncmp(spl[0], exp, ft_strlen(spl[0])) && \
			exp[ft_strlen(spl[0])] == '=')
		{
			free(data.my_env[j]);
			data.my_env[j] = ft_strdup(exp);
			k = -1;
			while (spl[++k])
				free(spl[k]);
			free(spl);
			return ;
		}
		j++;
	}
	data.my_env[j] = ft_strdup(exp);
}
