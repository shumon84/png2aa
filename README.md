# png2aa
[![license](https://img.shields.io/github/license/shumon84/png2aa.svg)](./LICENSE)
[![GitHub release](https://img.shields.io/github/release/shumon84/png2aa.svg)]()

This program is image file conversion to AA(ascii art).

## Usage
`$ png2aa [file] [width] [-option]`

`[width]` must be greater than 0 and less than the image width.

## Supported image file formats
1. PNG
1. JPEG
1. BMP
1. PNM(PPM/PMG/PBM)

## Option
- `-w`, `--white-back`
  - Invert black and white. This option use it if the background color is white.
- `-b`, `--bound-box`
  - Ignore the area with black only. It is an option for transparent images.
- `-c`, `--color`
  - Output colorful ascii art. 

## Install for MaxOS
Required Homebrew.

`$ tap shumon84/png2aa`

`$ brew install png2aa`

## Author
shumon84

## License
[MIT License](https://github.com/shumon84/png2aa/blob/master/LICENSE)
