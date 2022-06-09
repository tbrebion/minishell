/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/09 15:51:09 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//////////////////////////////////////////////

//	IMPOSSIBLE CORRECTOR CAN UNSET THE ERROR_ENV

/////////////////////////////////////////////////


void	set_error_env(void)
{
	int		j;
	char	**spl;
	char	*exp;
	int		k;
	char	*err_stat;

	j = 0;
	spl = NULL;
	err_stat = ft_itoa(data.error_status);
	exp = ft_strjoin(ft_strdup("?="), err_stat);
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
			k = -1;
			while (spl[++k])
				free(spl[k]);
			free(spl);
			free(err_stat);
			free(exp);
			return ;
		}
		j++;
	}
	free(err_stat);
	data.my_env[j] = ft_strdup(exp);
	free(exp);
}
