#include"image.h"
extern int opt_bound_box;

image_t* make_bound_box(image_t *img)
{  
  uint32_t i,j;
  uint32_t x=img->width/2;
  uint32_t y=img->height/2;
  uint32_t maxx=0;
  uint32_t maxy=0;
  uint32_t minx=0;
  uint32_t miny=0;

  for(i=0;i<y;i++)
    for(j=0;j<img->width;j++)
      if(img->map[i][j].g!=0x00)
	{
	  miny=i;
	  i=y;
	  break;
	}
  for(i=img->height-1;i>y;i--)
    for(j=0;j<img->width;j++)
      if(img->map[i][j].g!=0x00)
	{
	  maxy=i;
	  i=y;
	  break;
	}
  for(i=0;i<x;i++)
    for(j=0;j<img->height;j++)
      if(img->map[j][i].g!=0x00)
	{
	  minx=i;
	  i=x;
	  break;
	}
  for(i=img->width-1;i>x;i--)
    for(j=0;j<img->height;j++)
      if(img->map[j][i].g!=0x00)
	{
	  maxx=i;
	  i=x;
	  break;
	}

  uint32_t width=maxx-minx+1;
  uint32_t height=maxy-miny+1;
  image_t *bound_box=allocate_image(width,height,COLOR_TYPE_GRAY);
  
  for(i=0;i<height;i++)
    for(j=0;j<width;j++)
      bound_box->map[i][j].g=img->map[miny+i][minx+j].g;
  
  return bound_box;
}
