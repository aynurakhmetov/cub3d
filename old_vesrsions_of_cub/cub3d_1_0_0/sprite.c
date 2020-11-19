#include "./cub.h"

char	ft_get_new_dir_sprite(t_plr ray, t_all *all)
{
	char new_dir;
	t_plr test_plr;
	//LV
	float k = 1;

	new_dir = 'O';
	if (sin(ray.start) <= 0 && cos(ray.start) <= 0)
	{
		test_plr.x = ray.x + k;
		test_plr.y = ray.y + k;
		//printf ("tut 1, \n");
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x / SCALE)] == '2')
			return ('N');
		if (all->map[(int)(test_plr.y / SCALE)][(int)(ray.x / SCALE)] == '2')
			return ('W');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
			return ('W');
		//printf ("tut 2\n");
	}

	//PV
	if (sin(ray.start) <= 0 && cos(ray.start) >= 0)
	{
		test_plr.x = ray.x - k;
		test_plr.y = ray.y + k;
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '2')
			return ('N');
		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '2')
			return ('E');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
			return ('N');
	}

	//NP
	if (sin(ray.start) >= 0 && cos(ray.start) >= 0)
	{
		test_plr.x = ray.x - k;
		test_plr.y = ray.y - k;
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '2')
			return ('S');
		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '2')
			return ('E');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
			return ('E');
	}

	//NL
	if (sin(ray.start) >= 0 && cos(ray.start) <= 0)
	{
		test_plr.x = ray.x + k;
		test_plr.y = ray.y - k;
		if (all->map[(int)(ray.y / SCALE)][(int)(test_plr.x/ SCALE)] == '2')
			return ('S');
		if (all->map[(int)(test_plr.y/ SCALE)][(int)(ray.x/ SCALE)] == '2')
			return ('W');
		if (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == '2')
			return ('S');
	}

	return (new_dir);
}

void ft_draw_sprite(t_all *all, float y_draw, float x_draw, int i, float ugol, t_plr ray)
{   
    float distance;
    float perpendicular;
    float height;
    float start;
    float end;  

    //printf("1\n");

    all->new_dir = ft_get_new_dir_sprite(ray, all);
    distance = sqrt(pow(x_draw - all->plr->x, 2) + pow(y_draw - all->plr->y, 2)) * cos(ugol - all->plr->dir);
    perpendicular = (all->mapInfo->xRenderSize / 2) / tan(FOV/2);
    //height = all->mapInfo->yRenderSize / (distance * sin(all->plr->dir));
    height = (SCALE / distance) * (all->mapInfo->xRenderSize / 2) / tan(FOV/2);

    start = all->mapInfo->yRenderSize/2 - height/2;
    end = height + start;
	if (end > all->mapInfo->yRenderSize)
        end = all->mapInfo->yRenderSize;

    //printf("2 new dir %c\n", all->new_dir);

    float h=0;
    int w=0;
    float hit;
    //float ptr;

    //int     k;
    //int color;

    //void *addr;

    char *color = "abs";

    if (all->new_dir == 'N' || all->new_dir == 'S')
    {
        //hit = modff(x_draw, &ptr);
        hit = fmod(x_draw, SCALE) / SCALE;
        //printf("x hit = %f, x_draw = %f\n",hit, x_draw);
    }
    if (all->new_dir == 'W' || all->new_dir == 'E')
    {
        //hit = modff(y_draw, &ptr); 
        hit = fmod(y_draw, SCALE) / SCALE;
        //printf("y hit = %f, y_draw = %f\n", hit, y_draw);
    }
    w = all->text[0].img_width * hit;
	float step;
	step = 1.0 * all->text[0].img_height / (end - start);
	//printf("2 hei = %d end = %f start = %f\n", all->text[0].img_height, end, start);
    //printf("3 w = %d h = %f step = %f\n", w, h, step);
	//printf("addr= %d\n", all->text[0].line_length);
    while (start < end)
    {

		if (start >= 0)
		{
            color = (all->text[0].addr + ((((int)(h * all->text[0].img_height / height)*all->text[0].line_length + ((int)w * (all->text[0].bits_per_pixel/ 8))))));
    		//color = (all->text[0].addr +((int)h/64 * all->text[0].line_length + (int)w * (all->text[0].bits_per_pixel/ 8)));
        	//color = ((all->text[0].addr + (all->text[0].img_width * (int)h) + ((int)w)));
            if (*(int*)color)
                ft_draw(all, start, i, *(int*)color);
			// else
			// {
			// 	//ft_draw(all, start, i, 0x00AA00FF);
			// }
			
            //printf("3.2 color %d\n", *(int*)color);    
		}
        
		//printf("3.1 w = %d h = %f hh = %d\n", w, h, (int)(h * all->text[0].img_height / height * all->text[0].line_length));
		h++;
        start++;
    }

    //printf("4 w = %d h = %f\n", w, h);

}