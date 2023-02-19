/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:11:43 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/18 12:50:17 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_BONUS_H
# define PRIVATE_BONUS_H

# include "get_next_line_bonus.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 35
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

// get_next_line_utils.c
void	gnl_free(char **ptr);
int		gnl_strlen(const char *str);
void	*gnl_memcpy(void *dst, const void *src, int n);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char *s1, char *s2);

#endif
