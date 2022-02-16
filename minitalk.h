/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:54:31 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/13 16:54:32 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

void	sending_utils(int *count, int fd);
void	sending(int *count, int fd);
void	convertingbinary(int i, int fd, int *j);
void	sendingchar(char c, int fd);
void	convertingascii(char *str, int fd);
void	send(int user);

#endif