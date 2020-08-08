/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/09 00:54:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# define ARRAY_SIZE 256

typedef struct	s_buf
{
	int				len;
	char			*start;
	struct s_buf	*next;
	char			str[BUFF_SIZE];
}				t_buf;

typedef struct	s_file
{
	int				fd;
	t_buf			*buffer;
	struct s_file	*next;
}				t_file;

#endif
