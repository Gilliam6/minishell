/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:42:06 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:42:08 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found_n(char *str)
{
	int	res;

	res = -1;
	if (str)
		while (str[++res])
			if (str[res] == '\n')
				return (res);
	return (-1);
}

static int	gnl_join_str(char **str, char *buf)
{
	int		len_str;
	int		len_buf;
	char	*new_str;

	len_str = (int)ft_strlen(*str);
	len_buf = (int)ft_strlen(buf);
	new_str = malloc(len_str + len_buf + 1);
	if (!new_str)
		return (0);
	new_str[len_str + len_buf] = 0;
	ft_memmove(new_str, *str, len_str);
	ft_memmove(new_str + len_str, buf, len_buf);
	free(*str);
	*str = new_str;
	return (1);
}

static int	sent_next_line(char **line, char **str, int pos_f)
{
	char	*new_str;
	int		len_str;

	len_str = (int)ft_strlen(*str);
	new_str = malloc(len_str - pos_f);
	*line = malloc(pos_f + 1);
	if (new_str == 0 || *line == 0)
		return (-1);
	(*line)[pos_f] = 0;
	ft_memmove(*line, *str, pos_f);
	new_str[len_str - pos_f - 1] = 0;
	ft_memmove(new_str, *str + pos_f + 1, len_str - pos_f - 1);
	free(*str);
	*str = new_str;
	return (1);
}

static int	sent_last_line(char **line, char **str)
{
	int	len_str;

	len_str = (int)ft_strlen(*str);
	*line = malloc(len_str + 1);
	if (*line == 0)
		return (-1);
	(*line)[len_str] = 0;
	ft_memmove(*line, *str, len_str);
	free(*str);
	*str = 0;
	return (0);
}

/*Так как в новой норме нельзя использовать ЗАГЛАВНЫЕ*/
/*букыв в разделе переменных заменил */
/*BUFFER в buf[(BUFFER + 1)] на 64*/
int	get_next_line(int fd, char **line)
{
	static char	*str = 0;
	char		buf[(64 + 1)];
	int			pos_f;
	int			len_buf;

	pos_f = found_n(str);
	if (pos_f > -1)
		return (sent_next_line(line, &str, pos_f));
	len_buf = read(fd, buf, BUFFER);
	while (len_buf > 0)
	{
		buf[len_buf] = 0;
		if (!gnl_join_str(&str, buf))
			return (-1);
		pos_f = found_n(str);
		if (pos_f > -1)
			return (sent_next_line(line, &str, pos_f));
		len_buf = read(fd, buf, BUFFER);
	}
	if (len_buf < 0)
		return (-1);
	else
		return (sent_last_line(line, &str));
}
