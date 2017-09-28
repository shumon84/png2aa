#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"image.h"

int opt_white=0;

const struct {
  char ascii;
  double ratio;
} palette[]=
  {
    {' ',0.000000},
    {'`',0.024761},
    {'.',0.038025},
    {'\'',0.039794},
    {',',0.054827},
    {'_',0.058806},
    {'-',0.059248},
    {':',0.076050},
    {'~',0.077819},
    {'"',0.084009},
    {'^',0.085188},
    {'!',0.089167},
    {';',0.092852},
    {'/',0.108327},
    {'<',0.108475},
    {'\\',0.108622},
    {'>',0.109211},
    {'+',0.111275},
    {'|',0.113338},
    {')',0.114370},
    {'(',0.115402},
    {'=',0.125718},
    {'L',0.127929},
    {'v',0.131172},
    {'?',0.136035},
    {'T',0.138541},
    {'t',0.138836},
    {'7',0.141046},
    {'r',0.142962},
    {'}',0.144289},
    {'x',0.145763},
    {'z',0.147089},
    {'c',0.147826},
    {'i',0.148121},
    {'[',0.148268},
    {']',0.148563},
    {'Y',0.150332},
    {'l',0.150774},
    {'{',0.151216},
    {'f',0.152100},
    {'I',0.154164},
    {'n',0.157259},
    {'u',0.157553},
    {'*',0.159617},
    {'s',0.159764},
    {'J',0.160648},
    {'y',0.164480},
    {'j',0.164923},
    {'F',0.165070},
    {'1',0.166544},
    {'4',0.168755},
    {'o',0.172144},
    {'V',0.174945},
    {'h',0.180693},
    {'a',0.182167},
    {'e',0.183493},
    {'k',0.185999},
    {'2',0.188504},
    {'Z',0.190125},
    {'X',0.194547},
    {'9',0.198379},
    {'P',0.199116},
    {'A',0.199705},
    {'C',0.200295},
    {'6',0.200884},
    {'3',0.205601},
    {'w',0.206338},
    {'U',0.206780},
    {'E',0.208548},
    {'p',0.208696},
    {'K',0.210022},
    {'m',0.210906},
    {'m',0.210906},
    {'b',0.213117},
    {'H',0.213559},
    {'q',0.213707},
    {'5',0.214886},
    {'d',0.217981},
    {'S',0.222697},
    {'@',0.226824},
    {'#',0.231393},
    {'O',0.233604},
    {'D',0.237583},
    {'R',0.238025},
    {'G',0.238172},
    {'%',0.239057},
    {'N',0.242152},
    {'&',0.245689},
    {'8',0.251437},
    {'g',0.252174},
    {'W',0.253206},
    {'0',0.257922},
    {'B',0.258217},
    {'Q',0.265144},
    {'M',0.267207},
    {'M',0.267207},
    {'$',0.268091},
  };

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

double white_ratio(image_t *img,int y1,int y2,int x1,int x2)
{
  int i,j;
  long long sum=0;
  long long n=0;
  
  for(i=y1;i<y2&&i<img->height;i++)
    for(j=x1;j<x2&&i<img->width;j++)
      {
	sum+=img->map[i][j].g;
	n++;
      }
  double ratio=(double)sum/n;
  if(opt_white)ratio=255-ratio;
  return ratio/255*0.268091;
}

char block_to_ascii(image_t *img,double unitH,double unitW,int y,int x)
{
  double ratio=white_ratio(img,unitH*y,unitH*(y+1),unitW*x,unitW*(x+1));
  char ascii;
  int i;
  for(i=0;i<96;i++)
    if(ratio<palette[i].ratio)
      break;
  if(palette[i].ratio-ratio<ratio-palette[i-1].ratio)
    ascii=palette[i].ascii;
  else
    ascii=palette[i-1].ascii;

  return ascii;
}

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

void image_to_aa(image_t *img,int width)
{
  image_to_gray(img);
  img=make_bound_box(img); 
  if(img->width<width)
    {
      fprintf(stderr,"Width = %d is too large.\n",width);
      exit(1);
    }
  double unitW=(double)img->width/width;
  double unitH=(double)unitW*1.95;
  int height=(double)(img->height*width)/(img->width*1.95);
  
  int i,j;

  for(i=0;i<height;i++)
    {
      for(j=0;j<width;j++)
	putchar(block_to_ascii(img,unitH,unitW,i,j));
      putchar('\n');
    }
}

void option_check(int num,char *opt[])
{
  int i;
  int p;
  int invalid=0;
  for(i=3;i<num;i++)
    {
      if(opt[i][1]=='-')p=1;
      else p=0;
      switch(opt[i][1+p])
	{
	case 'w': opt_white=1;break;
	default : fprintf(stderr,"%s:invalid option\n",opt[i]);invalid=1;break;
	}
    }
  if(invalid)exit(1);
}

int main(int argc,char *argv[])
{
  if(argc<3)
    {
      fprintf(stderr,"Usage:%s [*.png|*.jpg|*.bmp|*.pnm] [width] [-option]\n",argv[0]);
      exit(1);
    }
  int width=0;
  if(!sscanf(argv[2],"%d",&width) || width<0)
    {
      fprintf(stderr,"\"%s\" is not unsigned int.\n",argv[2]);
      exit(1);
    }

  option_check(argc,argv);
  
  image_to_aa(read_image(argv[1]),width);

  return 0;
}
