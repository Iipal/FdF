# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

## Installation:

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

#### MLX
For correct work program & project need install MLX library. (Use this [MLX](https://github.com/abouvier/minilibx.git))

When you have already installed MLX library you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete temporary files.
- **make fclean**: Delete executable FdF file & libft library.
- **make re**: It's rules - **make fclean** & **make** in one.

## Usage:

```bash
./fdf test_maps/<map_name>
```

- Move figure up, down, right & left. `[WASD or Arrows]`
- Zooming it. `[+ or -]`
- Rotate by XY axis. (X`[T | G]`, Y`[Y | H]`) 
- Close FdF. `[ESC]`
- Bonus. `[C]` (Working only if exist file `frog_bonus.fdf` in `test_maps/`: [frog.h](https://github.com/Iipal/FdF/blob/c2ae671c89be79027b7e69cf3475624b758d886e/includes/frog.h#L16))

### Something about maps for that project:

- Numbers in one line means our X-positions on map.
- Lines in file means our Y-positions on map.
- Each numbers on map means our Z-positions on map.
- `0xFFFFFF`: HEX color code for XYZ-position.
