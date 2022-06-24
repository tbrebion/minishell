/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/24 15:26:03 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_error_env(void)
{
	int		j;
	char	**spl;
	char	*exp;
	int		k;
	char	*err_stat;
	char	*err_var;

	j = 0;
	spl = NULL;
	err_var = ft_strdup("?=");
	err_stat = ft_itoa(data.error_status);
	exp = ft_strjoin(/*ft_strdup("?=")*/err_var, err_stat);
	/////////////////////////////////////////
	// ft_printf("-------\nexp = %s\n-------\n", exp);
	/////////////////////////////////////////
	while (data.my_env[j])
	{
		spl = ft_split(data.my_env[j], '=');
		if (!ft_strncmp(spl[0], exp, ft_strlen(spl[0])) && \
			exp[ft_strlen(spl[0])] == '=')
		{
			free(data.my_env[j]);
			data.my_env[j] = ft_strdup(exp);
			k = 0;
			while (spl[k])
			{
				free(spl[k]);
				// spl[k] = NULL;
				k++;
			}
			free(spl);
			spl = NULL;
			free(err_stat);
			free(exp);
			return ;
		}
		else
		{
			k = 0;
			while (spl[k])
			{
				free(spl[k]);
				// spl[k] = NULL;
				k++;
			}
			free(spl);
			spl = NULL;
		}
		j++;
	}
	free(err_stat);
	data.my_env[j] = ft_strdup(exp);
	free(spl);
	free(exp);
}
