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

/*
**	All info about that's macroses and constants include in README.
*/

# define WIN_X 2000
# define WIN_Y 1000

# define IRGB_WHITE 16777215

# define NEG -1
# define ZERO 0
# define POS 1

# define HEX 16
# define DEC 10

# define _MSG(msg) ft_putendl(msg)
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_V(ex) if (!(ex)) return
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _SWAP(a, b) { (a) ^= (b); (b) ^= (a); (a) ^= (b); }
# define _DIGITS_IN_NUMBER(var) while ((var)) {(var) /= DEC; ++digits;}
# define _ABS(var) ((var) < 0) ? -(var) : (var);

enum	e_bool
{
	false,
	true
};

# define _BOOL typedef enum e_bool	bool

_BOOL;

#endif
