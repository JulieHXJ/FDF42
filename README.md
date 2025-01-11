# FDF42

# Project breakdown
1. File Parsing:<br>
Parse the .fdf file to extract the 3D points (x, y, z).<br>
Use get_next_line and ft_split from your libft to read the file and split data efficiently.<br>

2. Data Representation:<br>
Represent the map using a structure like t_map, which will store the grid of 3D points and metadata (e.g., dimensions).<br>

3. Projection:<br>
Use an isometric projection to convert the 3D points into 2D coordinates for rendering.<br>

4. draw the 2D map:<br>
Use bresenham algorithm to draw the line between the converted points.<br>

5. Rendering:<br>
Use MiniLibX or MLX42 to render the wireframe model in a window.<br>
Implement smooth window management (e.g., ESC to quit, cross to close).<br>

6. User Interaction:<br>
Allow basic interactions like zoom, rotation, and translation of the map.<br>
Add controls for switching projections or adjusting parameters.<br>

# Resources
isometric projection formula:<br>
x = (x - y) * cos(30);<br>
y = (x + y) * sin(30) - z;<br>

draw line algorithm:<br>
https://youtu.be/RGB-wlatStc?si=jZuOaV4Hl028tf3a<br>
This video will explain the idea of Bresenham’s line drawing algorithm and the math behind it. but it only explains one very specific case, which is when the slope is less 1 and the values of x and y need to be incremented.<br>

mlx tutorial:<br>
https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-macos<br>
Everything needed is here. For instructions of functions, go to docs/<br>

The functions used in my FDF:<br>
mlx_init()<br>
mlx_new_image()<br>
mlx_image_to_window()<br>
mlx_key_hook()<br>
mlx_mouse_hook()<br>
mlx_scroll_hook()<br>
mlx_close_window()<br>
mlx_loop_hook()<br>
mlx_loop()<br>
mlx_terminate()<br>


Hook functions used in my fdf:<br>
/* Callback function used to handle scrolling.<br>
 * @param[in] xdelta The mouse x delta.<br>
 * @param[in] ydelta The mouse y delta.<br>
 * @param[in] param Additional parameter to pass on to the function.<br>
 */<br>
typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);<br>

/* Callback function used to handle mouse actions.<br>
 * @param[in] button The mouse button/key pressed.<br>
 * @param[in] action The mouse action that took place.<br>
 * @param[in] mods The modifier keys pressed together with the mouse key.<br>
 * @param[in] param Additional parameter to pass on to the function.<br>
 */<br>
typedef void (*mlx_mousefunc)(mouse_key_t button, action_t action, modifier_key_t mods, void* param);<br>

/* Callback function used to handle key presses.<br>
 * @param[in] keydata The callback data, contains info on key, action, ...<br>
 * @param[in] param Additional parameter to pass on to the function.<br>
 */<br>
typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);<br>

# Reference:
https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448<br>
https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc<br>
https://medium.com/@youbihi129/42-the-network-fdf-fil-de-fer-project-roadmap-464be06d6f15<br>