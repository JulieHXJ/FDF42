# FDF42

https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448

https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc

https://medium.com/@youbihi129/42-the-network-fdf-fil-de-fer-project-roadmap-464be06d6f15

https://github.com/tarikkudesu/fdf/blob/main/srcs/get_map.c


mlx tutorial:
https://gontjarow.github.io/MiniLibX/
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
https://gontjarow.github.io/MiniLibX/?source=post_page-----7184cca317fc--------------------------------

https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-macos

The functions used are :
mlx_init()
mlx_new_window()
mlx_clear_window()
mlx_destroy_window()
mlx_new_image()
mlx_destroy_image()
mlx_get_data_addr()
mlx_put_image_to_window()
mlx_hook()
mlx_mouse_hook()
mlx_loop()
mlx_xpm_file_to_image()


draw line algorithm:
https://youtu.be/RGB-wlatStc?si=jZuOaV4Hl028tf3a This video will explain the idea of Bresenham’s line drawing algorithm and the math behind it. but it only explains one very specific case, which is when the slope is less 1 and the values of x and y need to be incremented.

cartesian to isometric:
x = x - y
y = (x + y) / 2


main
https://github.com/MartijnWallage/42_FdF/blob/master/inc/fdf.h

https://git.chevro.fr/42-cestoliv/fdf/-/blob/main/src/main.c?ref_type=heads

1. File Parsing:
Parse the .fdf file to extract the 3D points (x, y, z).
Use get_next_line and ft_split from your libft to read the file and split data efficiently.

2. Data Representation:
Represent the map using a structure like t_map, which will store the grid of 3D points and metadata (e.g., dimensions).

3. Projection:
Use an isometric projection to convert the 3D points into 2D coordinates for rendering.

4. Rendering:
Use MiniLibX to render the wireframe model in a window.
Implement smooth window management (e.g., ESC to quit, cross to close).

5. User Interaction:
Allow basic interactions like zoom, rotation, and translation of the map.
Add controls for switching projections or adjusting parameters.