#include <iostream>
using namespace std;

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

#include <openbr_plugin.h>
using namespace br;

int main(int argc, char** argv) {
  // initialize OpenBR context and transforms
  br::Context::initialize(argc, argv);
  QSharedPointer<Transform> transform = Transform::fromAlgorithm("FaceRecognition");//br::Transform::fromAlgorithm("/home/colin/documents/openbr/tmp/128Eigenfaces");
  QSharedPointer<Distance> distance = Distance::fromAlgorithm("FaceRecognition");//br::Distance::fromAlgorithm("/home/colin/documents/openbr/tmp/128Eigenfaces");

  // open and enroll the target
  Template target("/home/colin/colin.jpg");
  target >> *transform;

  // initialize USB Webcam
  VideoCapture cap(0);
  if (!cap.isOpened()) {
    return -1;
  }

  Mat edges;
  for(;;) {
    // get the frame and display it
    Mat frame;
    cap >> frame;
    imshow("webcam", frame);
    if (waitKey(30) >= 0) {
      break;
    }

    Template frameTemplate(frame);
    frameTemplate >> *transform;

    float comparison = distance->compare(frameTemplate, target);
    cout << "Comparison: " << comparison << endl;
  }

  br::Context::finalize();

  /*
  // get the 128 Eigenfaces transform

  br::Template queryB("/home/colin/tmp/128ATT400/s1_2.pgm");

  // enroll the templates
  queryA >> *transform;
  queryB >> *transform;

  float comparison = distance->compare(queryA, queryB);
  cout << "Comparison: " << comparison << endl;

  br::Context::finalize();
  return 0;
  */
}
