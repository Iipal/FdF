# FdF
> "Fil de Fer"

###### made by tmaluh __(\_ipal)__

[![Video preview](https://raw.githubusercontent.com/Iipal/FdF/master/screen.png)](https://www.youtube.com/watch?v=hGdsDJowX3s)

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
- Zooming it. `[+ or -]` (or mouse)
- Rotate by XY axis. (X`[T | G]`, Y`[Y | H]` or mouse)
- Close FdF. `[ESC]`
- Bonus. `[C]` (Working only if exist file `frog_bonus.fdf` in `test_maps/`([frog.h](https://github.com/Iipal/FdF/blob/1fe0e35d533a151c652ed6e172404238045c997f/includes/frog.h#L16)))

### Something about maps for that project:

- Numbers in one line means our X-positions on map.
- Lines in file means our Y-positions on map.
- Each numbers on map means our Z-positions on map.
- `0xFFFFFF`: HEX color code for XYZ-position.
