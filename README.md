# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

## Installation:

Just use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.
- *make*: Compile all.
- *make clean*: Delete temporal files.
- *make fclean*: Delete executable FdF file & libft library.
- *make re*: It's just *make fclean* and *make*.

## Usage:

```bash
./fdf test_maps/<map_name>
```

## Tips & note

### Maps file:

Something about maps for that project:

- Numbers in one line means our X-position's on map.
- Lines in file means our Y-position's on map.
- Each numbers on map means our Z-position's on map.
- `0xFFFFFF`: HEX color code for XYZ-position.

### In code:

In code i have some function prefixes for better understanding:

- `pj_*`: This is **important** functions for program work.
- `add_*`: This is *additional* functions for `pj_*`.
- `ft_*`: This is functions from libft.

About structures:

1. `s_file`: Storage file data & how much lines in it.
	- `tab`: Two dimension characters array with data from file.
	- `lines`: Lines counter in file.
2. `s_matrix`: Simple structure with two `int`'s
	- `z`: Value of Z-position
	- `rgb`: Value converted from `HEX` to `RGB Int` color of current position
	- *In code i use this struct like a two dimensional array*.

About `typedef`'s and `define`'s:	
1. `typedef`:
	- `typedef`'s used in `define` macros to get around the school42 norme. (Example: `_BOOL;` macros)
	- **string**: `char *`.
	- **cstring**: `const char *`.
	- **ustring**: `unsigned char *`.
	- **bool**: `enum e_bool` with only 2 value's(`true` and `false`).
	- **pvoid**: `void *`
2. `define`:
	- Constant's:
		- **WIN_X**: Width our window.
		- **WIN_Y**: Height our window.
		- **ZERO**: Just 0.
		- **NEG**; Just -1.
		- **HEX**: Just 16. Used for `ft_atoi_base()`.
		- **DEC**: Just 10. Used for `ft_atoi_base()`.
		- **IRGB_WHITE**: RGB Int white color.
	- Macrose's:
		- **_MSG**: (`msg`) Used for put string with newline in standart output.
		- **\_NOTIS_MSG**: (`msg`, `ex`) If `ex` isn't true - put `msg` to standart output by **_MSG**.
		- **\_NOTIS_MPE**: (`msg`, `ex`) If `ex` isn't true - put `msg` to error output by `perror()`.
		- **\_NOTIS_V**: (`ex`) If `ex` isn't true - just `return;`. Used in `void` function's.
		- **\_NOTIS_F**: (`ex`) If `ex` isn't true - just `return (false);`. Used in `bool` or `int` function's.
		- **\_NOTIS_N**: (`ex`) If `ex` isn't true - just `return (NULL);`. Used in function's where we must return pointer to something.

Global variable:

1. `g_matrix_y`: Height our `s_matrix` two dimensional array.
2. `g_matrix_x`: Width our `s_matrix` two dimensional array.

## Program usage:

In this part i'll tell how you can interact with program.
###### dont done yet...

## Code progress & structuring program:

 - [x] File reading & validating data in it.
 - [ ] Drawing all points from map.
 - [ ] Add isometric camera view.
 - [ ] Add some colored effects like a `ft_raindow()` & etc.
 - [ ] Add bonus part from subject.