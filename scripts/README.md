# Pre-Processing the Video File

## Steps
1. [This Video](https://www.youtube.com/watch?v=UkgK8eUdpAo) was used to create the animation in this project.
2. After downlading the video (using whichever method, I used [`yt-dlp`](https://github.com/yt-dlp/yt-dlp)), convert the video to a series of images using [`ffmpeg`](https://ffmpeg.org/).
    ```bash
    cd X11-Bad-Apple/scripts/frames
    ffmpeg -i video.webm frame%04d.png
    ```

At the end, you should end up with a folder containing a series of images, each one representing a frame of the video.
[![Folder Structure](https://i.gyazo.com/4e2b47d154f619155c418d8ac2f1a848.gif)](https://gyazo.com/4e2b47d154f619155c418d8ac2f1a848)
