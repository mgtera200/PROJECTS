# Simple Perception Stack for Self-Driving Cars


![car_det](https://github.com/mgtera200/PROJECTS/assets/127119775/e22becdd-b5a3-4c14-825c-b813b4200b27)


## Introduction
This project demonstrates a simple perception stack for self-driving cars (SDCs) using computer vision techniques. The focus is on analyzing video streams from front-facing cameras to detect lane lines and other vehicles on the road.

## Project Overview
The project is divided into two main tasks:

### Task 1 - Lane Line Detection - [![Output Video]](https://drive.google.com/file/d/1WeqngoYKfQe3-zhrwhLsD1pCoffYqgx6/view?usp=sharing)
In this task, a software pipeline is developed to identify the lane boundaries in a video. The pipeline detects and tracks lane lines, highlights them, and overlays the detected lines on the original frames.

### Task 2 - Car Detection - [![Output Video]](https://drive.google.com/file/d/18n7Anaozkn24yErfpM8ZSoZdtXvzXvu9/view?usp=sharing)
This task involves detecting cars on the road using Haar cascade classifiers. The system locates and identifies vehicles in the video stream and draws bounding boxes around them.

## Technologies Used
- OpenCV
- NumPy

## Getting Started
To run this project, follow these steps:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/self-driving-car-perception-stack.git
   cd self-driving-car-perception-stack

2. **Install Dependencies:**
Ensure you have OpenCV and NumPy installed. You can install them using pip:
```bash
pip install opencv-python numpy
```


3. **Run Lane Line Detection:**

```bash
python lane_detection.py
```

4. **Run Car Detection:**

```bash
python car_detection.py
```

## Code Explanation
### Lane Line Detection Code
The lane_detection.py script processes video frames to detect lane lines. It performs the following steps:

1. Converts the frame to grayscale.
2. Applies Canny edge detection to highlight edges.
3. Masks the region of interest (the road area).
4. Uses the Hough Transform to detect lines.
5. Draws the detected lane lines on the original frame.


### Car Detection Code
The car_detection.py script uses a pre-trained Haar cascade classifier to detect cars in video frames. It performs the following steps:

1. Loads the Haar cascade for car detection.
2. Reads video frames in a loop.
3. Converts each frame to grayscale.
4. Uses the Haar cascade to detect cars.
5. Draws rectangles around detected cars.

## Conclusion
This project provides a foundational understanding of creating a perception stack for self-driving cars using basic computer vision techniques. It can be further enhanced with more advanced methods and additional sensor data.

## Acknowledgements
Ain Shams University, Faculty of Engineering, Image Processing / Computer Vision
