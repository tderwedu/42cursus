# ```cub3D```
*a 19 Coding School project*

This project’s objectives is to use ray-casting to make a dynamic representation of the inside of a maze from a first person perspective. This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever.

![](cub3D.gif)

## Addings

- Walls/object collision.
- A skybox and textured floor/ceil.
- A minimap with the player position.
- The ability to look up and down.
- Rotate the point of view with the mouse.
- The ability to jump and crouch.
- A life bar and the ability to lose/gain life points.
- Doors that can open and close.
- Secret doors.
- Moving enemies.
- A pickable knife.

## How to use it

### Set the mapping configuration in the `makefile`:
```
# MAPPING:
# 1 : Linux QWERTY
# 2 : Linux AZERTY
MAPPING         =       1
```
1. QWERTY : `WASD` keys to move through the maze.
2. AZERTY : `ZQSD` keys to move through the maze.

In both case, the arrow keys can also be used.
- `ctrl` to crouch,
- `space` to jump.

### Compile the files with the addings:
```
make bonus
```
w
To play, a map's path need to be specified:
```
./cub3D maps/bonus.cub 
```
To save a screenshot of the first in-game image:
```
./cub3D maps/bonus.cub --save
```

## Acknowledgements

- Lode Vandevenne's [Raycasting tutorials](https://lodev.org/cgtutor/raycasting.html#Introduction)
- 42docs' [MiniLibX docs](https://harm-smits.github.io/42docs/libs/minilibx)
- [Fdf cook book](https://stackoverflow.com/c/42network/questions/164)
- Mason D Young's [cud3D](https://github.com/qst0/ft_libgfx)
- Amy Plant's ascii art [cud3D](https://github.com/iciamyplant/Cub3d-Linux)
- Emily Liberman's [barrels](https://www.artstation.com/artwork/gJV9XQ)
- Tua Xiong's ascii art [dragon](https://www.asciiart.eu/mythology/dragons)

## License

Everything in this repository is released under the [Unlicense](https://github.com/tderwedu/42cursus/blob/main/LICENSE).

