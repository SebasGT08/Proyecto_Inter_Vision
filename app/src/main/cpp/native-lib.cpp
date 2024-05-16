#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_proyecto_1vison_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_proyecto_1vison_MainActivity_processFrame(
        JNIEnv* env, jobject, jlong matAddrRgba) {
    Mat& mRgba = *(Mat*)matAddrRgba;
    Mat mGray;
    cvtColor(mRgba, mGray, COLOR_RGBA2GRAY);
    cvtColor(mGray, mRgba, COLOR_GRAY2RGBA);
}
