#include<stdlib.h>
#include"image.h"
#include"option.h"
#include"bound_box.h"
#include"ascii.h"
#include"color.h"

extern int opt_bound_box;
extern int opt_color;

void image_to_aa(image_t *img,uint32_t width)
{
  if(opt_color)
    image_to_rgb(img);
  else
    image_to_gray(img);
  
  if(opt_bound_box)
    img=make_bound_box(img);
  
  if(img->width<width)
    {
      fprintf(stderr,"Width = %d is too large.\n",width);
      exit(1);
    }
  double unitW=(double)img->width/width;
  double unitH=(double)unitW*1.95;
  uint32_t height=(double)(img->height*width)/(img->width*1.95);
  
  int i,j;

  for(i=0;i<height;i++)
    {
      for(j=0;j<width;j++)
	{
	  if(opt_color)
	    block_to_color(img,unitH,unitW,i,j);
	  else
	    block_to_ascii(img,unitH,unitW,i,j);
	}
      printf("\e[49m\n");
    }
}
