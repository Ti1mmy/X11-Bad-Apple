#!/bin/python3
from pixelator import Pixelator
from PIL import Image, ImageOps
from os import remove
from io import BytesIO
from numpy import frombuffer
from cv2 import imdecode

def make_bitmap(filename: str, width: int, height: int, palette_dict: dict, padding=0) -> None:
    
    pixelart_resolution = (width, height)
    palette = list(palette_dict.keys())

    png = Image.open(f'{filename}').convert('RGBA')
    filename = filename.split('/')[-1]
    
    # Make border larger to shrink the image
    png = ImageOps.expand(png, border=padding, fill=None)
    background = Image.new('RGBA', png.size, (0,255,0)) # Make background green
    png_masked = Image.alpha_composite(background, png)

    # Should do nearest resample to prevent dithering
    png_masked = png_masked.resize(pixelart_resolution, resample=Image.NEAREST)
    
    memory_buffer = BytesIO()
    png_masked.save(memory_buffer, format='png')
    memory_buffer.seek(0)
    # print(memory_buffer.getvalue())
    img_data = frombuffer(memory_buffer.getvalue(), dtype='uint8')
    img = Pixelator(data=imdecode(img_data, 1))
    pixelated_img = img.pixelate(
        width = pixelart_resolution[0],
        height = pixelart_resolution[1],
        palette=palette
    )

    # Write pixelated image data to file
    out_filename = filename.split('.')[0]

    with open(f"out/{out_filename}_pixmap.h", "w") as out:
        # Include Guard!!
        out.write(f'#ifndef __{out_filename.upper()}_PIXMAP_H__\n')
        out.write(f'#define __{out_filename.upper()}_PIXMAP_H__\n\n')
        out.write("#include <vector>\n\n")
        # Define the pixmap
        out.write(f'static const char {out_filename}[{pixelart_resolution[1]}][{pixelart_resolution[0] + 1}] = ' + '{\n')
        for horizontal_line in pixelated_img.data:
            line = []
            for pixel in horizontal_line:
                pixel_tuple = tuple([int(x) for x in pixel])
                pixel_colour = palette_dict[pixel_tuple]
                line.append(pixel_colour)
            line_str = '\t{"' + f'{"".join(line)}' + '"},\n'
            out.write(line_str)
        out.write('};\n\n')
        out.write('#endif\n')
        out.close()

        #print(pixelated_img.data)
        #pixelated_img.write(filename=f'./out/{image.split(".")[0]}_pixelated_80x80.png', height=80, width=80)
            
        # Comment this line out if you want to see what the masked image looks like
        # In particular, could be useful if you decide to use it to bitmap-ify 
        # other assets/videos
        remove(f'./out/{out_filename}_temp_masked.png')
        memory_buffer.close()
