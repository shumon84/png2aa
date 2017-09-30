#include"image.h"
#include<stdlib.h>
#include<string.h>

int opt_white;
int opt_bound_box;
int opt_color;

void option_check(int num,char *opt[])
{
  int i,j;
  int invalid=0;
  for(i=3;i<num;i++)
    {
      if(opt[i][0]=='-')
	{
	  if(opt[i][1]=='-')
	    {
	      if(strcmp(opt[i],"--white-back")==0)
		opt_white=1;
	      else if(strcmp(opt[i],"--bound-box")==0)
		opt_bound_box=1;
	      else if(strcmp(opt[i],"--color")==0)
		opt_color=1;
	      else
		{
		  fprintf(stderr,"%s:invalid option\n",opt[i]);
		  invalid=1;
		}
	    }
	  else
	    {
	      for(j=1;opt[i][j]!='\0';j++)
		switch(opt[i][j])
		  {
		  case 'w': opt_white=1;break;
		  case 'b': opt_bound_box=1;break;
		  case 'c': opt_color=1;break;
		  default : fprintf(stderr,"-%c:invalid option\n",opt[i][j]);invalid=1;break;
		  }
	    }
	}
      else
	{
	  fprintf(stderr,"%s:invalid option\n",opt[i]);
	  invalid=1;
	  break;
	}
    }
  if(invalid)exit(1);
}
