from bitmap import make_bitmap
from multiprocessing import Pool, cpu_count
import os

PNG_PATH = './frames'
IMAGES = [f for f in os.listdir(PNG_PATH) if f.split('.')[1] == 'png']
PIXELART_RESOLUTION = (960, 720)
PADDING = 0
PALETTE_dict = {
<<<<<<< Updated upstream
    (255, 255, 255): ' ',
    (0, 0, 0): '#',
=======
    (255, 255, 255): "B",
    (0, 0, 0): 'W',
>>>>>>> Stashed changes
    # (0, 255, 0): 'Transparent', # Makes transparents portions of the image green
                                  # Note: Won't be used in the final image, nor will it be
                                  # In the final repo
}

# We will thread all of our image calls to make_bitmap to run at once
def main():
    with Pool(processes=cpu_count() - 2) as task_pool:
        print("Starting to make bitmaps... (This might take a while)")
        for image in IMAGES:
            task_pool.apply_async(make_bitmap, args=(f'{PNG_PATH}/{image}', PIXELART_RESOLUTION[0], PIXELART_RESOLUTION[1], PALETTE_dict, PADDING))
        task_pool.close()
        task_pool.join()
    
    with open("out/bad_apple_pixmap_frames.h", "w") as f:
        f.write("#ifndef __BAD_APPLE_PIXMAP_H__\n")
        f.write("#define __BAD_APPLE_PIXMAP_H__\n")
        f.write("\n")
        f.write("\n")
        for image in IMAGES:
            f.write(f'#include "display/frames/{image.split(".")[0]}_pixmap.h"\n')
        f.write("\n")
        f.write(f"#define NUM_FRAMES_H {len(IMAGES)}\n")
        f.write(f"#define FRAME_HEIGHT_H {PIXELART_RESOLUTION[1]}\n")
        f.write(f"#define FRAME_WIDTH_H {PIXELART_RESOLUTION[0]}\n")
        f.write("\n")
        
        f.write(f"static const int NUM_FRAMES = NUM_FRAMES_H;\n")
        f.write(f"static const int FRAME_HEIGHT = FRAME_HEIGHT_H;\n")
        f.write(f"static const int FRAME_WIDTH = FRAME_WIDTH_H;\n")
        f.write("\n")
<<<<<<< Updated upstream
        f.write("static const std::vector<const char**> bad_apple_frames = {\n")
=======
        f.write(f"static const colour[{len(IMAGES)}][{PIXELART_RESOLUTION[1]}][{PIXELART_RESOLUTION[0]}] = "+ "{\n")
>>>>>>> Stashed changes
        for image in IMAGES:
            f.write(f"    {image.split('.')[0]},\n")
        f.write("};\n")
        f.write("\n")
        f.write("#endif\n")
    print("Done")

if __name__ == '__main__':
    main()
