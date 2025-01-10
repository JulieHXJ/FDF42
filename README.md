# FDF42

Project breakdown
1. File Parsing:
Parse the .fdf file to extract the 3D points (x, y, z).
Use get_next_line and ft_split from your libft to read the file and split data efficiently.

2. Data Representation:\n
Represent the map using a structure like t_map, which will store the grid of 3D points and metadata (e.g., dimensions).

3. Projection:\n
Use an isometric projection to convert the 3D points into 2D coordinates for rendering.

4. draw the 2D map:\n
Use bresenham algorithm to draw the line between the converted points.

5. Rendering:
Use MiniLibX or MLX42 to render the wireframe model in a window.
Implement smooth window management (e.g., ESC to quit, cross to close).

6. User Interaction:
Allow basic interactions like zoom, rotation, and translation of the map.
Add controls for switching projections or adjusting parameters.

# Resources
isometric projection formula:
x = (x - y) * cos(30);
y = (x + y) * sin(30) - z;

draw line algorithm:
https://youtu.be/RGB-wlatStc?si=jZuOaV4Hl028tf3a This video will explain the idea of Bresenham’s line drawing algorithm and the math behind it. but it only explains one very specific case, which is when the slope is less 1 and the values of x and y need to be incremented.

mlx tutorial:
https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-macos
Everything needed is here. For instructions of functions, go to docs/

The functions used in my FDF:
mlx_init()
mlx_new_image()
mlx_image_to_window()
mlx_key_hook()
mlx_mouse_hook()
mlx_scroll_hook()
mlx_close_window()
mlx_loop_hook()
mlx_loop();
mlx_terminate();








/**
 * Callback function used to handle scrolling.
 * 
 * @param[in] xdelta The mouse x delta.
 * @param[in] ydelta The mouse y delta.
 * @param[in] param Additional parameter to pass on to the function.
 */
typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

/**
 * Callback function used to handle mouse actions.
 * 
 * @param[in] button The mouse button/key pressed.
 * @param[in] action The mouse action that took place.
 * @param[in] mods The modifier keys pressed together with the mouse key.
 * @param[in] param Additional parameter to pass on to the function.
 */
typedef void (*mlx_mousefunc)(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

/**
 * Callback function used to handle key presses.
 * 
 * @param[in] keydata The callback data, contains info on key, action, ...
 * @param[in] param Additional parameter to pass on to the function.
 */
typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);


Reference:
https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448

https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc

https://medium.com/@youbihi129/42-the-network-fdf-fil-de-fer-project-roadmap-464be06d6f15