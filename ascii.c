#include"image.h"
extern int opt_white;
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

double white_ratio(image_t *img,uint32_t y1,uint32_t y2,uint32_t x1,uint32_t x2)
{
  int i,j;
  uint64_t sum=0;
  uint64_t n=0;
  
  for(i=y1;i<y2&&i<img->height;i++)
    for(j=x1;j<x2&&i<img->width;j++)
      {
	sum+=img->map[i][j].g;
	n++;
      }
  printf("%llu/%llu,",sum,n); // debug
  double ratio=(double)sum/n;
  //  printf("%.2f,",ratio); // debug
  if(opt_white)ratio=255-ratio;
  return ratio/255*0.268091;
}

void block_to_ascii(image_t *img,double unitH,double unitW,uint32_t y,uint32_t x)
{
  char ascii;
  int i;
  double ratio=white_ratio(img,unitH*y,unitH*(y+1),unitW*x,unitW*(x+1));
  for(i=0;i<96;i++)
    if(ratio<palette[i].ratio)
      break;
  if(palette[i].ratio-ratio<ratio-palette[i-1].ratio)
    ascii=palette[i].ascii;
  else
    ascii=palette[i-1].ascii;
  //  putchar(ascii);
}
  
