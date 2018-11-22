/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/21 16:52:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_X	1920
# define WIN_Y	960

# define IRGB_WHITE 16777215

# define ZERO 0
# define NEG -1

# define HEX 16
# define DEC 10

# define _MSG(msg) ft_putendl(msg)
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_V(ex) if (!(ex)) return
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _NOTIS_N(ex) if (!(ex)) return (NULL)

enum	e_bool
{
	false,
	true
};

# define _BOOL typedef enum e_bool	bool

_BOOL;

#endif
