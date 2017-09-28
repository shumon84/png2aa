#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include"image.h"
#include"option.h"
#include"read.h"
#include"convert.h"

int main(int argc,char *argv[])
{
  if(argc<3)
    {
      fprintf(stderr,"Usage:%s [*.png|*.jpg|*.bmp|*.pnm] [width] [-option]\n",argv[0]);
      exit(1);
    }
  uint32_t width=0;
  if(!sscanf(argv[2],"%ud",&width) || width<0)
    {
      fprintf(stderr,"\"%s\" is not unsigned int.\n",argv[2]);
      exit(1);
    }

  option_check(argc,argv);
  
  image_to_aa(read_image(argv[1]),width);

  return 0;
}
