# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

## Installation:

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

#### MLX
For correct work program & project need install MLX library. (Use this [MLX](https://github.com/abouvier/minilibx.git))

When you have already installed MLX library you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete temporal files.
- **make fclean**: Delete executable FdF file & libft library.
- **make re**: It's rules - **make fclean** & **make** in one.

## Usage:

```bash
./fdf test_maps/<map_name>
```

### Something about maps for that project:

- Numbers in one line means our X-positions on map.
- Lines in file means our Y-positions on map.
- Each numbers on map means our Z-positions on map.
- `0xFFFFFF`: HEX color code for XYZ-position.

### Program usage features:
###### Info will be also printed when program start
- Move figure up, down, right & left. `[WASD or Arrows]`
- Zooming it. `[+ or -]`
- Rotate by XYZ axis. (X`[T | G]`, Y`[Y | H]`, Z`[U | J]`) 
- Close FdF. `[ESC]`
- Bonus. `[C]` (Working only if issue file `frog_bonus.fdf` in `test_maps/`)
