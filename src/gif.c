/**
 * @file gif.c
 *
 * Copyright(c) 2017 shumon84
 *
 * This software is released under the MIT License.
 * http://opensource.org/licenses/MIT
 *
 * @brief GIFファイルの読み書き処理
 * @author <a href="mailto:cameremon84@gmail.com">shumon84</a>
 * @date 2017/10/04
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<ctype.h>
#include"image.h"

image_t **read_gif_file(const char *filename)
{
}

image_t **read_gif_stream(FILE *fp)
{
}

result_t write_gif_file(const char *filename,image_t *img)
{
}

result_t write_gif_stream(FILE *fp,image_t *img)
{
}
