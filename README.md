# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

## Installation:

Just use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.
- *make*: Compile all.
- *make clean*: Delete temporal files.
- *make fclean*: Delete executable FdF file & libft library.
- *make re*: It's rules - *make fclean* & *make*.

## Usage:

```bash
./fdf test_maps/<map_name>
```



## Tips & notes

### Maps file:

#### Something about maps for that project:

- Numbers in one line means our X-positions on map.
- Lines in file means our Y-positions on map.
- Each numbers on map means our Z-positions on map.
- `0xFFFFFF`: HEX color code for XYZ-position.

### In code:

#### In code i have some function prefixes for better understanding:
- `pj_*`: This is **important** functions for program work.
- `add_*`: This is *additional* functions for `pj_*`.
- `ft_*`: This is functions from libft.

#### About structures:
1. `s_file`: Storage file data & how much lines in it.
	- `tab`: Two dimensional character array with data from file.
	- `lines`: Lines counter in file.
2. `s_matrix`: Simple structure with two `int`'s
	- `z`: Value of Z-position
	- `rgb`: Value converted from `HEX` to `RGB Int` color of current position
	- *In code i use this struct like a two dimensional array*.

#### About `typedef`'s and `define`'s:	
1. `typedef`: *(used in `define` macroses to get around the school42 norme. (Example: `_BOOL;` macros))*
	- **string**: `char *`.
	- **cstring**: `const char *`.
	- **ustring**: `unsigned char *`.
	- **bool**: `enum e_bool` with only 2 values(`true` and `false`).
	- **pvoid**: `void *`.
2. `define`:
	- Constants:
		- **WIN_Y**: Height our window.
		- **WIN_X**: Width our window.
		- **ZERO**: Value - 0.
		- **NEG**: Value - -1.
		- **HEX**: Value - 16. Used for `ft_atoi_base()`.
		- **DEC**: Value - 10. Used for `ft_atoi_base()`.
		- **IRGB_WHITE**: RGB Int white color. Default `s_matrix.rgb` value.
	- Macroses:
		- **\_MSG**:
			- *Arguments*: `msg`.
			- *Behavior*: Prints string with newline character in standard output.
			- *Used*: Usually - used in `_NOTIS_MSG`.
		- **\_NOTIS_MSG**:
			- *Arguments*: `msg`, `ex`.
			- *Behavior*: If `ex` isn't true - prints `msg` to standart output by **\_MSG**.
			- *Used*: Usually - in main function for errors print.
		- **\_NOTIS_MPE**:
			- *Arguments*: `msg`, `ex`.
			- *Behavior*: If `ex` isn't true - prints `msg` to error output by `perror()`.
			- *Used*: Usually - in main function for errors print.
		- **\_NOTIS_V**:
			- *Arguments*: `ex`.
			- *Behavior*: If `ex` isn't true - just `return;`.
			- *Used*: Usually - used in `void` functions.
		- **\_NOTIS_F**:
			- *Arguments*: `ex`.
			- *Behavior*: If `ex` isn't true - just `return (false);`.
			- *Used*: Usually - used in `bool` or `int` functions.
		- **\_NOTIS_N**: (`ex`) | If `ex` isn't true - just `return (NULL);`. Used in functions where we must return pointer to something.
			- *Arguments*: `ex`.
			- *Behavior*: If `ex` isn't true - just `return (NULL);`.
			- *Used*: Usually - used in functions where we must return pointer to something.

#### Global variable's:

1. **g_matrix_y**: Height our `s_matrix` two dimensional array.
2. **g_matrix_x**: Width our `s_matrix` two dimensional array.

## Program usage features:

#### In this part i'll tell how you can interact with program.
###### dont done yet...



## Code progress & structuring program:

 - [x] File reading & validating data in it.
 - [ ] Drawing all points from map.
 - [ ] Add isometric camera view.
 - [ ] Add some colored effects like a `ft_raindow()` & etc.
 - [ ] Add bonus part from subject.
