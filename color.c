#include"image.h"

const struct{
  uint32_t code;
  char escape[16];
}color[]=
  {
    {0x000000,"\e[48;5;16m "},
    {0x00005f,"\e[48;5;17m "},
    {0x000087,"\e[48;5;18m "},
    {0x0000af,"\e[48;5;19m "},
    {0x0000d7,"\e[48;5;20m "},
    {0x0000ff,"\e[48;5;21m "},
    {0x005f00,"\e[48;5;22m "},
    {0x005f5f,"\e[48;5;23m "},
    {0x005f87,"\e[48;5;24m "},
    {0x005faf,"\e[48;5;25m "},
    {0x005fd7,"\e[48;5;26m "},
    {0x005fff,"\e[48;5;27m "},
    {0x008700,"\e[48;5;28m "},
    {0x00875f,"\e[48;5;29m "},
    {0x008787,"\e[48;5;30m "},
    {0x0087af,"\e[48;5;31m "},
    {0x0087d7,"\e[48;5;32m "},
    {0x0087ff,"\e[48;5;33m "},
    {0x00af00,"\e[48;5;34m "},
    {0x00af5f,"\e[48;5;35m "},
    {0x00af87,"\e[48;5;36m "},
    {0x00afaf,"\e[48;5;37m "},
    {0x00afd7,"\e[48;5;38m "},
    {0x00afff,"\e[48;5;39m "},
    {0x00d700,"\e[48;5;40m "},
    {0x00d75f,"\e[48;5;41m "},
    {0x00d787,"\e[48;5;42m "},
    {0x00d7af,"\e[48;5;43m "},
    {0x00d7d7,"\e[48;5;44m "},
    {0x00d7ff,"\e[48;5;45m "},
    {0x00ff00,"\e[48;5;46m "},
    {0x00ff5f,"\e[48;5;47m "},
    {0x00ff87,"\e[48;5;48m "},
    {0x00ffaf,"\e[48;5;49m "},
    {0x00ffd7,"\e[48;5;50m "},
    {0x00ffff,"\e[48;5;51m "},
    {0x5f0000,"\e[48;5;52m "},
    {0x5f005f,"\e[48;5;53m "},
    {0x5f0087,"\e[48;5;54m "},
    {0x5f00af,"\e[48;5;55m "},
    {0x5f00d7,"\e[48;5;56m "},
    {0x5f00ff,"\e[48;5;57m "},
    {0x5f5f00,"\e[48;5;58m "},
    {0x5f5f5f,"\e[48;5;59m "},
    {0x5f5f87,"\e[48;5;60m "},
    {0x5f5faf,"\e[48;5;61m "},
    {0x5f5fd7,"\e[48;5;62m "},
    {0x5f5fff,"\e[48;5;63m "},
    {0x5f8700,"\e[48;5;64m "},
    {0x5f875f,"\e[48;5;65m "},
    {0x5f8787,"\e[48;5;66m "},
    {0x5f87af,"\e[48;5;67m "},
    {0x5f87d7,"\e[48;5;68m "},
    {0x5f87ff,"\e[48;5;69m "},
    {0x5faf00,"\e[48;5;70m "},
    {0x5faf5f,"\e[48;5;71m "},
    {0x5faf87,"\e[48;5;72m "},
    {0x5fafaf,"\e[48;5;73m "},
    {0x5fafd7,"\e[48;5;74m "},
    {0x5fafff,"\e[48;5;75m "},
    {0x5fd700,"\e[48;5;76m "},
    {0x5fd75f,"\e[48;5;77m "},
    {0x5fd787,"\e[48;5;78m "},
    {0x5fd7af,"\e[48;5;79m "},
    {0x5fd7d7,"\e[48;5;80m "},
    {0x5fd7ff,"\e[48;5;81m "},
    {0x5fff00,"\e[48;5;82m "},
    {0x5fff5f,"\e[48;5;83m "},
    {0x5fff87,"\e[48;5;84m "},
    {0x5fffaf,"\e[48;5;85m "},
    {0x5fffd7,"\e[48;5;86m "},
    {0x5fffff,"\e[48;5;87m "},
    {0x870000,"\e[48;5;88m "},
    {0x87005f,"\e[48;5;89m "},
    {0x870087,"\e[48;5;90m "},
    {0x8700af,"\e[48;5;91m "},
    {0x8700d7,"\e[48;5;92m "},
    {0x8700ff,"\e[48;5;93m "},
    {0x875f00,"\e[48;5;94m "},
    {0x875f5f,"\e[48;5;95m "},
    {0x875f87,"\e[48;5;96m "},
    {0x875faf,"\e[48;5;97m "},
    {0x875fd7,"\e[48;5;98m "},
    {0x875fff,"\e[48;5;99m "},
    {0x878700,"\e[48;5;100m "},
    {0x87875f,"\e[48;5;101m "},
    {0x878787,"\e[48;5;102m "},
    {0x8787af,"\e[48;5;103m "},
    {0x8787d7,"\e[48;5;104m "},
    {0x8787ff,"\e[48;5;105m "},
    {0x87af00,"\e[48;5;106m "},
    {0x87af5f,"\e[48;5;107m "},
    {0x87af87,"\e[48;5;108m "},
    {0x87afaf,"\e[48;5;109m "},
    {0x87afd7,"\e[48;5;110m "},
    {0x87afff,"\e[48;5;111m "},
    {0x87d700,"\e[48;5;112m "},
    {0x87d75f,"\e[48;5;113m "},
    {0x87d787,"\e[48;5;114m "},
    {0x87d7af,"\e[48;5;115m "},
    {0x87d7d7,"\e[48;5;116m "},
    {0x87d7ff,"\e[48;5;117m "},
    {0x87ff00,"\e[48;5;118m "},
    {0x87ff5f,"\e[48;5;119m "},
    {0x87ff87,"\e[48;5;120m "},
    {0x87ffaf,"\e[48;5;121m "},
    {0x87ffd7,"\e[48;5;122m "},
    {0x87ffff,"\e[48;5;123m "},
    {0xaf0000,"\e[48;5;124m "},
    {0xaf005f,"\e[48;5;125m "},
    {0xaf0087,"\e[48;5;126m "},
    {0xaf00af,"\e[48;5;127m "},
    {0xaf00d7,"\e[48;5;128m "},
    {0xaf00ff,"\e[48;5;129m "},
    {0xaf5f00,"\e[48;5;130m "},
    {0xaf5f5f,"\e[48;5;131m "},
    {0xaf5f87,"\e[48;5;132m "},
    {0xaf5faf,"\e[48;5;133m "},
    {0xaf5fd7,"\e[48;5;134m "},
    {0xaf5fff,"\e[48;5;135m "},
    {0xaf8700,"\e[48;5;136m "},
    {0xaf875f,"\e[48;5;137m "},
    {0xaf8787,"\e[48;5;138m "},
    {0xaf87af,"\e[48;5;139m "},
    {0xaf87d7,"\e[48;5;140m "},
    {0xaf87ff,"\e[48;5;141m "},
    {0xafaf00,"\e[48;5;142m "},
    {0xafaf5f,"\e[48;5;143m "},
    {0xafaf87,"\e[48;5;144m "},
    {0xafafaf,"\e[48;5;145m "},
    {0xafafd7,"\e[48;5;146m "},
    {0xafafff,"\e[48;5;147m "},
    {0xafd700,"\e[48;5;148m "},
    {0xafd75f,"\e[48;5;149m "},
    {0xafd787,"\e[48;5;150m "},
    {0xafd7af,"\e[48;5;151m "},
    {0xafd7d7,"\e[48;5;152m "},
    {0xafd7ff,"\e[48;5;153m "},
    {0xafff00,"\e[48;5;154m "},
    {0xafff5f,"\e[48;5;155m "},
    {0xafff87,"\e[48;5;156m "},
    {0xafffaf,"\e[48;5;157m "},
    {0xafffd7,"\e[48;5;158m "},
    {0xafffff,"\e[48;5;159m "},
    {0xd70000,"\e[48;5;160m "},
    {0xd7005f,"\e[48;5;161m "},
    {0xd70087,"\e[48;5;162m "},
    {0xd700af,"\e[48;5;163m "},
    {0xd700d7,"\e[48;5;164m "},
    {0xd700ff,"\e[48;5;165m "},
    {0xd75f00,"\e[48;5;166m "},
    {0xd75f5f,"\e[48;5;167m "},
    {0xd75f87,"\e[48;5;168m "},
    {0xd75faf,"\e[48;5;169m "},
    {0xd75fd7,"\e[48;5;170m "},
    {0xd75fff,"\e[48;5;171m "},
    {0xd78700,"\e[48;5;172m "},
    {0xd7875f,"\e[48;5;173m "},
    {0xd78787,"\e[48;5;174m "},
    {0xd787af,"\e[48;5;175m "},
    {0xd787d7,"\e[48;5;176m "},
    {0xd787ff,"\e[48;5;177m "},
    {0xd7af00,"\e[48;5;178m "},
    {0xd7af5f,"\e[48;5;179m "},
    {0xd7af87,"\e[48;5;180m "},
    {0xd7afaf,"\e[48;5;181m "},
    {0xd7afd7,"\e[48;5;182m "},
    {0xd7afff,"\e[48;5;183m "},
    {0xd7d700,"\e[48;5;184m "},
    {0xd7d75f,"\e[48;5;185m "},
    {0xd7d787,"\e[48;5;186m "},
    {0xd7d7af,"\e[48;5;187m "},
    {0xd7d7d7,"\e[48;5;188m "},
    {0xd7d7ff,"\e[48;5;189m "},
    {0xd7ff00,"\e[48;5;190m "},
    {0xd7ff5f,"\e[48;5;191m "},
    {0xd7ff87,"\e[48;5;192m "},
    {0xd7ffaf,"\e[48;5;193m "},
    {0xd7ffd7,"\e[48;5;194m "},
    {0xd7ffff,"\e[48;5;195m "},
    {0xff0000,"\e[48;5;196m "},
    {0xff005f,"\e[48;5;197m "},
    {0xff0087,"\e[48;5;198m "},
    {0xff00af,"\e[48;5;199m "},
    {0xff00d7,"\e[48;5;200m "},
    {0xff00ff,"\e[48;5;201m "},
    {0xff5f00,"\e[48;5;202m "},
    {0xff5f5f,"\e[48;5;203m "},
    {0xff5f87,"\e[48;5;204m "},
    {0xff5faf,"\e[48;5;205m "},
    {0xff5fd7,"\e[48;5;206m "},
    {0xff5fff,"\e[48;5;207m "},
    {0xff8700,"\e[48;5;208m "},
    {0xff875f,"\e[48;5;209m "},
    {0xff8787,"\e[48;5;210m "},
    {0xff87af,"\e[48;5;211m "},
    {0xff87d7,"\e[48;5;212m "},
    {0xff87ff,"\e[48;5;213m "},
    {0xffaf00,"\e[48;5;214m "},
    {0xffaf5f,"\e[48;5;215m "},
    {0xffaf87,"\e[48;5;216m "},
    {0xffafaf,"\e[48;5;217m "},
    {0xffafd7,"\e[48;5;218m "},
    {0xffafff,"\e[48;5;219m "},
    {0xffd700,"\e[48;5;220m "},
    {0xffd75f,"\e[48;5;221m "},
    {0xffd787,"\e[48;5;222m "},
    {0xffd7af,"\e[48;5;223m "},
    {0xffd7d7,"\e[48;5;224m "},
    {0xffd7ff,"\e[48;5;225m "},
    {0xffff00,"\e[48;5;226m "},
    {0xffff5f,"\e[48;5;227m "},
    {0xffff87,"\e[48;5;228m "},
    {0xffffaf,"\e[48;5;229m "},
    {0xffffd7,"\e[48;5;230m "},
    {0xffffff,"\e[48;5;231m "},
  };

uint32_t color_code(color_t c)
{
  return (c.r<<16)+(c.g<<8)+(c.b);
}

uint32_t subtract_color(uint32_t c,uint32_t element[])
{
  int i;
  int ind;
  uint32_t min=0xff;
  uint32_t temp;
  for(i=0;i<6;i++)
    {
      temp=c>element[i]?c-element[i]:element[i]-c;
      if(min>temp)
	{
	  min=temp;
	  ind=i;
	}
    }
  return ind;
}

void change_color(uint32_t code)
{
  uint32_t index;
  uint32_t element[]={0,95,135,175,215,255};
  uint32_t r=subtract_color((code>>16)&0xff,element);
  uint32_t g=subtract_color((code>>8)&0xff,element);
  uint32_t b=subtract_color(code&0xff,element);

  index=r*36+g*6+b;  

  printf("%s",color[index].escape);
}

uint32_t color_average(image_t *img,uint32_t y1,uint32_t y2,uint32_t x1,uint32_t x2)
{
  int i,j;
  uint64_t r=0;
  uint64_t g=0;
  uint64_t b=0;
  uint64_t n=0;
  for(i=y1;i<y2&&i<img->height;i++)
    for(j=x1;j<x2&&j<img->width;j++)
      {
	r+=img->map[i][j].c.r;
	g+=img->map[i][j].c.g;
	b+=img->map[i][j].c.b;
	n++;
      }
  return color_code(color_from_rgb(r/n,g/n,b/n));
}

void block_to_color(image_t *img,double unitH,double unitW,uint32_t y,uint32_t x)
{
  uint32_t average=color_average(img,unitH*y,unitH*(y+1),unitW*x,unitW*(x+1));
  change_color(average);
}
