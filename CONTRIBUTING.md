# Contribution Guidelines

## How to contribution
### 🖐 Make issue

1. Prepare demo gif and link for your mobile machine learning project.
> I recommend the width of gif is 320.<br>If you want to know how to generate gif demo, check [this tutorial](#How-to-generate-gif).
2. Make an issue before PR
> I will prepare the issue guidelines, but not yet.

### 👍 Make PR

1. Fork Awesome Machine Learning DEMOs with iOS repository.
2. Add your demo gif and link.
3. Make PR.

## Tips
### How to generate gif

1. Record DEMO video on iOS.<br>→ [How to record the screen on your iPhone, iPad, or iPod touch](https://support.apple.com/en-us/HT207935)
2. Export the video to mac.
3. Convert the video to gif using following script.
  1. Install [FFMPEG](https://ffmpeg.org) on your mac.<br>
  → Run the following command on Terminal app.<br>
  `$ brew install ffmpeg`
  2. Download the script([`gifconverter.sh`](https://gist.github.com/tucan9389/f0a20ce94e84e42e11d05b55673aacd1)).

  ```shell
  # echo $1
  video_path=$1
  directory_path=`dirname "$1"`
  file=`basename "$1"`

  extension="${file##*.}"
  filename="${file%.*}"
  echo $extension

  gif_path="${video_path%.*}.gif"
  echo $gif_path

  ffmpeg  -y -i $video_path  -vf fps=8,scale=320:-1:flags=lanczos,palettegen palette.png;
  ffmpeg -y -i $video_path -i palette.png -filter_complex "fps=8,scale=320:-1:flags=lanczos[x];[x][1:v]paletteuse" $gif_path;
  ```

  3. Run the script with the demo video path.<br>
  `$ sh gifconverter.sh ~/Desktop/DEMO.mp4`
  4. You can find `DEMO.gif` on `~/Desktop`.

  ### How to measure the performance

  #### Unit Test

  > Show output for each input?
  > Drawing detail of result?
  > Test for debugging?
  >
  > - Pose Estimation: draw dot each point and joint, print confidence each point.
  > - ...

  #### Bunch Test (planning...)

  > Analyze outputs from a bunch of inputs
  >
  > - average of inference time and fps
  > - accumulate execution time, fps...?
  > - rendering time
  > - total execution time
  > - ...
