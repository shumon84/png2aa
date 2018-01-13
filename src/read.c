#include"image.h"
#include<stdlib.h>

image_t *error(const char *filename)
{
  fprintf(stderr,
	  "This file format is not supported.\n"
	  "Supported file formats are PNG, JPEG, BMP, PNM(PPM/PGM/PBM).\n");
  exit(1);
  return NULL;
}

image_t *read_image(char* filename)
{
  image_t *(*read_func[])(const char*)=
    {
      read_png_file,
      read_jpeg_file,
      read_bmp_file,
      read_pnm_file,
      error,
    };
  int i;
  image_t *img=NULL;
  for(i=0;img==NULL;i++)
    img=read_func[i](filename);
  return img;
}
