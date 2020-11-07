#include "./../includes/cub3d.h"

// char	ft_get_new_dir_sprite(t_plr ray, t_all *all)
// {
// 	char new_dir;
// 	t_plr test_plr;
// 	//LV
// 	float k = 1;

// 	new_dir = 'O';
// 	if (sin(ray.start) <= 0 && cos(ray.start) <= 0)
// 	{
// 		test_plr.x = ray.x + k;
// 		test_plr.y = ray.y + k;
// 		//printf ("tut 1, \n");
// 		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x / SCALE)] == '2')
// 			return ('N');
// 		if (all->map[(int)(test_plr.y / SCALE)][(int)(ray.x / SCALE)] == '2')
// 			return ('W');
// 		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
// 			return ('W');
// 		//printf ("tut 2\n");
// 	}

// 	//PV
// 	if (sin(ray.start) <= 0 && cos(ray.start) >= 0)
// 	{
// 		test_plr.x = ray.x - k;
// 		test_plr.y = ray.y + k;
// 		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '2')
// 			return ('N');
// 		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '2')
// 			return ('E');
// 		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
// 			return ('N');
// 	}

// 	//NP
// 	if (sin(ray.start) >= 0 && cos(ray.start) >= 0)
// 	{
// 		test_plr.x = ray.x - k;
// 		test_plr.y = ray.y - k;
// 		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '2')
// 			return ('S');
// 		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '2')
// 			return ('E');
// 		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
// 			return ('E');
// 	}

// 	//NL
// 	if (sin(ray.start) >= 0 && cos(ray.start) <= 0)
// 	{
// 		test_plr.x = ray.x + k;
// 		test_plr.y = ray.y - k;
// 		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '2')
// 			return ('S');
// 		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '2')
// 			return ('W');
// 		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
// 			return ('S');
// 	}

// 	return (new_dir);
// }

// void ft_draw_sprite(t_all *all, float y_draw, float x_draw, int i, float ugol, t_plr ray)
// {   
//     float distance;
//     float perpendicular;
//     float height;
//     float start;
//     float end;  

//     //printf("1\n");

//     all->new_dir = ft_get_new_dir_sprite(ray, all);
//     distance = sqrt(pow(x_draw - all->plr->x, 2) + pow(y_draw - all->plr->y, 2)) * cos(ugol - all->plr->dir);
//     perpendicular = (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
//     //height = all->mapInfo->yRenderSize / (distance * sin(all->plr->dir));
//     height = (SCALE / distance) * (all->mapInfo->xRenderSize / 2) / tan(FOV/2);

//     start = all->mapInfo->yRenderSize/2 - height/2;
//     end = height + start;
// 	if (end > all->mapInfo->yRenderSize)
//         end = all->mapInfo->yRenderSize;

//     //printf("2 new dir %c\n", all->new_dir);

//     float h=0;
//     int w=0;
//     float hit;
//     //float ptr;

//     //int     k;
//     //int color;

//     //void *addr;

//     char *color = "abs";

//     if (all->new_dir == 'N' || all->new_dir == 'S')
//     {
//         //hit = modff(x_draw, &ptr);
//         hit = fmod(x_draw, SCALE) / SCALE;
//         //printf("x hit = %f, x_draw = %f\n",hit, x_draw);
//     }
//     if (all->new_dir == 'W' || all->new_dir == 'E')
//     {
//         //hit = modff(y_draw, &ptr); 
//         hit = fmod(y_draw, SCALE) / SCALE;
//         //printf("y hit = %f, y_draw = %f\n", hit, y_draw);
//     }
//     w = all->text[0].img_width * hit;
// 	float step;
// 	step = 1.0 * all->text[0].img_height / (end - start);
// 	//printf("2 hei = %d end = %f start = %f\n", all->text[0].img_height, end, start);
//     //printf("3 w = %d h = %f step = %f\n", w, h, step);
// 	//printf("addr= %d\n", all->text[0].line_length);
//     while (start < end)
//     {

// 		if (start >= 0)
// 		{
//             color = (all->text[0].addr + ((((int)(h * all->text[0].img_height / height)*all->text[0].line_length + ((int)w * (all->text[0].bits_per_pixel/ 8))))));
//     		//color = (all->text[0].addr +((int)h/64 * all->text[0].line_length + (int)w * (all->text[0].bits_per_pixel/ 8)));
//         	//color = ((all->text[0].addr + (all->text[0].img_width * (int)h) + ((int)w)));
//             if (*(int*)color)
//                 ft_draw(all, start, i, *(int*)color);
// 			// else
// 			// {
// 			// 	//ft_draw(all, start, i, 0x00AA00FF);
// 			// }
			
//             //printf("3.2 color %d\n", *(int*)color);    
// 		}
        
// 		//printf("3.1 w = %d h = %f hh = %d\n", w, h, (int)(h * all->text[0].img_height / height * all->text[0].line_length));
// 		h++;
//         start++;
//     }

//     //printf("4 w = %d h = %f\n", w, h);

// }

void ft_draw_sprites(t_all *all)
{
	int i;
	int j;

	i = 0;
	t_sprite tmp;
	int len = all->sprites[0].len;
	while (i < len)
	{
		all->sprites[i].dist = sqrt(pow(all->sprites[i].x - all->plr->x, 2) + pow(all->sprites[i].y - all->plr->y, 2));
		tmp = all->sprites[i];
		//printf("%f %f\n", all->sprites[i].dist, tmp.dist);
		i++;
	}
	
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (all->sprites[i].dist > all->sprites[j].dist)
			{
				tmp = all->sprites[i];
				all->sprites[i] = all->sprites[j];
				all->sprites[j] = tmp;
				//printf("2 %d \n", j);
			}
			//printf("3 %d \n", j);
			j++;
		}
		//printf("1 %d \n", i);
		i++;
		//printf("1 %d \n", i);
	}
	//printf("1 %d \n", i);
	i = 0;
	while (i < len)
	{
		//printf("%f \n", all->sprites[i].dist);
		all->text[0].y = all->sprites[i].y;
		all->text[0].x = all->sprites[i].x;
		ft_draw_sprite_2(all);
		i++;
	}

}

void ft_draw_sprite_2(t_all *all)
{   
	//printf("zashel 1\n");
	float sprite_dir;
	char *color;

	//printf ("sprite X Y %f %f\n", all->text[0].y, all->text[0].x);
	//printf ("plr X Y %f %f\n", all->plr->y, all->plr->x);
	sprite_dir = atan2(all->text[0].y - all->plr->y, all->text[0].x - all->plr->x);
	while (sprite_dir - all->plr->dir >  M_PI) sprite_dir -= 2*M_PI; 
    while (sprite_dir - all->plr->dir < -M_PI) sprite_dir += 2*M_PI;
	sprite_dir -= all->plr->dir;
	// расстояние от игрока до спрайта
    float sprite_dist = sqrt(pow(all->text[0].x - all->plr->x, 2) + pow(all->text[0].y - all->plr->y, 2)); 
    float sprite_screen_size = (SCALE / sprite_dist) * (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
	

	int h_offset = all->mapInfo->xRenderSize/ (FOV * (180 / M_PI)) * ((180 / M_PI * sprite_dir) + 30) - sprite_screen_size / 2;
    int v_offset = all->mapInfo->yRenderSize / 2 - sprite_screen_size / 2;
	//printf("zashel 1.5 %d %f %d %f\n", h_offset, sprite_screen_size, v_offset, sprite_dir - all->plr->dir);

	float j = 0;
	float i = 0;
	float step; 
	step = all->text[0].img_height / sprite_screen_size;
	int				tex_y;
	int				tex_x;
	float			tex_pos = 0;
	tex_pos = 0;

	while (i < sprite_screen_size)
	{
		//printf("zashel 2 %d \n", h_offset);
        if (h_offset + i < 0 || h_offset + i >= all->mapInfo->xRenderSize || all->dist_wall[(int)(h_offset + i)] < sprite_dist )
		{
			i++;
			continue;
		}
		tex_x = i / sprite_screen_size * all->text[0].img_width;
		tex_pos = 0;
		j = 0;
        while (j < sprite_screen_size) 
		{
			//printf("zashel 3\n");
			tex_y = (unsigned int)tex_pos & (all->text[0].img_height - 1);
			color = all->text[0].addr + ((int)tex_y * all->text[0].line_length + ((int)(tex_x ) * (all->text[0].bits_per_pixel/ 8)));
			//color = (all->text[0].addr + ((((int)((tex_y * all->text[0].img_height) / sprite_screen_size)*all->text[0].line_length + ((int)tex_x * (all->text[0].bits_per_pixel/ 8))))));
            if (v_offset + j < 0 || v_offset + j > all->mapInfo->yRenderSize)
			{
				//printf("zashel 5\n");
				j++;
				continue;
			}
			tex_pos += step;
			//tex_pos++;
        	if (*(int *)color) //*(int *)
			{
				//printf("zashel 4\n");
				ft_draw(all,  v_offset + j, h_offset +  i, *(int *)color);
			}	
			j++;
        }
		//printf("zashel 3 %d \n", h_offset);
		i++;
	}
}