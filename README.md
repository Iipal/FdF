# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

## Installation:

Just use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

## Usage:

```bash
./fdf test_maps/<map_name>
```

## Tips & note

### Maps file:

Something about maps for that project:
	1. Numbers in one line means our X-position's on map.
	2. Lines in file means our Y-position's on map.
	3. Each numbers on map means our Z-position's on map.
	4. 0xFFFFFF: Means HEX color code for current position.

### In code:

In code i have some function prefixes for better understanding:
	1. `pj_*`: This is **important** functions for program work.
	2. `add_*`: This is __additional__ functions for `pj_`.
	3. `ft_*`: This is functions from libft.

About structures:
	1. `s_file`: Storage file data & how much lines in it.
		- `tab`: Two dimension characters array with data from file.
		- `lines`: Lines counter in file.
	2. `s_matrix`: Simple structure with two `int`'s
		- `z`: Value of Z-position
		- `rgb`: Value converted from `HEX` to `RGB Int` color of current position
		- In code i use this struct like a two dimensional array.

About `typedef`'s and `define`'s:
	1. `string`: `char *`.
	2. `cstring`: `const char *`.
	3. `ustring`: `unsigned char *`.
	4. `bool`: `enum e_bool` with only 2 value's(`true` and `false`).
	5. `pvoid`: `void *`
	6. `WIN_X`: Width our window.
	7. `WIN_Y`: Height our window.
	8. `ZERO`: Just 0.
	9. `NEG`; Just -1.
	10. `HEX`: Just 16. Used for `ft_atoi_base`.
	11. `DEC`: Just 10. Used for `ft_atoi_base`.

## Program usage:

In this part i'll tell how you can interact with program.
###### dont done yet...

## Code progress & structuring program:

 - [x] File reading & validating data in it.
 - [ ] Drawing all points from map.
 - [ ] Add isometric camera view.
 - [ ] Add some colored effects like a `ft_raindow` & etc.
 - [ ] Add bonus part from subject.