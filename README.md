# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

## Installation:

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

#### MLX
For correct work program & project need install MLX library. (Use this [MLX](https://github.com/abouvier/minilibx.git))
When you have already installed MLX library - uncomment one of this variables in `Makefile` for compiling on MacOS\Linux system:

```bash
# macOS:
# MLXFLAGS = -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
# linux:
# MLXFLAGS = -L /usr/local/lib -I /usr/local/lib -lmlx -lXext -lX11
```

after that, you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete temporal files.
- **make fclean**: Delete executable FdF file & libft library.
- **make re**: It's rules - **make fclean** & **make** in one.

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
1. `struct	s_matrix`: Simple structure with two `int`'s
	- `z`: Value of Z-position
	- `rgb`: Value converted from `HEX` to `RGB Int` color of current position
	- *In code i use this struct like a two dimensional array*.
2. `struct	s_mlx`: Struct for work with MiniLibX library.
	- `mlx`: Saving `void *` to init all mlx functions.
	- `win`: Saving `void *` to graphic window.
3. `struct	s_point`: Simpe struct for storage X and Y.
	- `y`: Y-position.
	- `x`: X-position.

#### About `typedef`'s and `define`'s:	
1. `typedef`: *(used in `define` macroses to get around the school42 norme. (Example: `_BOOL;` macros))*
	- **string**: `char *`.
	- **cstring**: `const char *`.
	- **ustring**: `unsigned char *`.
	- **bool**: `enum e_bool` with only 2 values(`true` and `false`).
	- **pvoid**: `void *`.
	- **t_matrix**: `struct s_matrix`.
	- **t_mlx**: `struct s_mlx`.
	- **t_point**: `struct s_point`.
2. `#define`:
	- Constants:
		- **WIN_Y**: Height our window. Value - 1200.
		- **WIN_X**: Width our window. Value - 600. (2:1 Display aspect ratio)
		- **ZERO**: Value - 0.
		- **NEG**: Value - -1.
		- **HEX**: Value - 16.
		- **DEC**: Value - 10.
		- **PI**: Value - 3.141592.
		- **IRGB_WHITE**: RGB Int white color. Default `struct s_matrix.rgb` value. Value - 16777215.
	- Macroses:
		- **\_MSG()**:
			- *Arguments*: `msg`.
			- *Behavior*: Prints string with newline character in standart output.
			- *Used*: Usually - used in `_NOTIS_MSG`.
			- *Usage*: `_MSG("ERROR!!!");`
		- **\_NOTIS_MSG()**:
			- *Arguments*: `msg`, `ex`.
			- *Behavior*: If `ex` isn't true - prints `msg` to standart output by **\_MSG**.
			- *Used*: Usually - in main function for errors print.
			- *Usage*: `_NOTIS_MSG("ERROR!!! argc is 0.", argc);`
		- **\_NOTIS_MPE()**:
			- *Arguments*: `msg`, `ex`.
			- *Behavior*: If `ex` isn't true - prints `msg` to error output by `perror()`.
			- *Used*: Usually - in main function for errors print.
			- *Usage*: `_NOTIS_MPE("ERROR!!! argc is bigger than 1.", argc > 1);`
		- **\_NOTIS_V()**:
			- *Arguments*: `ex`.
			- *Behavior*: If `ex` isn't true - just `return;`.
			- *Used*: Usually - used in `void` functions.
			- *Usage*: `_NOTIS_V(a > 1);`
		- **\_NOTIS_F()**:
			- *Arguments*: `ex`.
			- *Behavior*: If `ex` isn't true - just `return (false);`.
			- *Used*: Usually - used in `bool` or `int` functions.
			- *Usage*: `_NOTIS_F(a > 1);`
		- **\_NOTIS_N()**:
			- *Arguments*: `ex`.
			- *Behavior*: If `ex` isn't true - just `return (NULL);`.
			- *Used*: Usually - used in functions where we must return pointer to something.
			- *Usage*: `_NOTIS_N(a > 1);`
		- **\_SWAP()**:
			- *Arguments*: `a`, `b`.
			- *Behavior*: Macros just swap two value of any type.
			- *Used*: Nowhere yet.
			- *Usage*: `_SWAP(var_int, var_char);`
		- **\_ABS()**:
			- *Arguments*: `var`.
			- *Behavior*: Simple macro to get absolute value from `var`.
			- *Used*: For Bresenham Algorithm.
			- *Usage*: `_ABS(negative_number);`
		- **\_DEG()**:
			- *Arguments*: `rad`.
			- *Behavior*: Simple macro to get degrees from `rad`.
			- *Used*: For XYZ-rotation.
			- *Usage*: `_DEG(0.01);`
		- **\_RAD()**:
			- *Arguments*: `deg`.
			- *Behavior*: Simple macro to get radianas from `deg`.
			- *Used*: For XYZ-rotation.
			- *Usage*: `_RAD(90);`
		- **\_BOOL**:
			- *Arguments*: none.
			- *Behavior*: Macro for using `bool` type in C. Only for to get around the school42 norme.
			- *Used*: Only in header(`defines.h`).
			- *Usage*: Dont needed use anywhere else.

#### Global variable's:

1. **g_matrix_y**: Height our `struct s_matrix` two dimensional array.
2. **g_matrix_x**: Width our `struc ts_matrix` two dimensional array.

## Program usage features:

#### In this part i'll tell how you can interact with program.
###### dont done yet...



## Code progress & structuring program:

 - [x] File reading & validating data in it.
 - [x] Drawing all points from map in graphic window.
 - [ ] Add isometric camera view.
 - [ ] Add some colored effects like a `ft_raindow()` & etc.
 - [ ] Add bonus part from subject.
