/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:56:10 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/23 03:24:33 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// get_next_line_utils.c
void	gnl_free(char **ptr);
int		gnl_strlen(const char *str);
void	*gnl_memcpy(void *dst, const void *src, int n);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char *s1, char *s2);

#endif
