from bitmap import make_bitmap
from multiprocessing import Pool, cpu_count
import os

PNG_PATH = './frames'
IMAGES = [f for f in os.listdir(PNG_PATH) if f.split('.')[1] == 'png']
PIXELART_RESOLUTION = (960, 720)
PADDING = 0
PALETTE_dict = {
    (255, 255, 255): ' ',
    (0, 0, 0): '#',
    (0, 255, 0): 'Transparent', # Makes transparents portions of the image green
                                # Note: Won't be used in the final image, nor will it be
                                # In the final repo
}

# We will thread all of our image calls to make_bitmap to run at once
def main():
    # with Pool(processes=cpu_count()) as task_pool:
    #     print("Starting to make bitmaps... (This might take a while)")
    #     for image in IMAGES:
    #         task_pool.apply_async(make_bitmap, args=(f'{PNG_PATH}/{image}', PIXELART_RESOLUTION[0], PIXELART_RESOLUTION[1], PALETTE_dict, PADDING))
    #     task_pool.close()
    #     task_pool.join()
    
    with open("out/bad_apple_pixmap.h", "w") as f:
        f.write("#ifndef __BAD_APPLE_PIXMAP__\n")
        f.write("#define __BAD_APPLE_PIXMAP__\n")
        f.write("\n")
        f.write("\n")
        for image in IMAGES:
            f.write(f'#include "frames/display/{image.split(".")[0]}_pixmap.h"\n')
        f.write("\n")
        f.write(f"static const int NUM_FRAMES = {len(IMAGES)};\n")
        f.write(f"static const int FRAME_HEIGHT = {PIXELART_RESOLUTION[0]};\n")
        f.write(f"static const int FRAME_WIDTH = {PIXELART_RESOLUTION[1]};\n")
        f.write("\n")
        f.write(f"static const char bad_apple_frames[{len(IMAGES)}][{PIXELART_RESOLUTION[1]}][{PIXELART_RESOLUTION[0]}] " "= {\n")
        for image in IMAGES:
            f.write(f"    {image.split('.')[0]},\n")
        f.write("};\n")
        f.write("\n")
        f.write("#endif\n")
    print("Done")

if __name__ == '__main__':
    main()
