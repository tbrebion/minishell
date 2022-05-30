/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:23:00 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/30 15:24:54 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void disableRawMode(void) 
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void tty_raw_mode(void)
{
	struct termios tty_attr;

	tcgetattr(0, &tty_attr);
	tcgetattr(0, &orig_termios);

	/* Set raw mode. */
	tty_attr.c_lflag &= (~(ICANON|ECHO));
	tty_attr.c_cc[VTIME] = 0;
	tty_attr.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&tty_attr);
}
