#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

int classify (Mat img, int x_min, int y_min, int x_max, int y_max)
{
    int flag=1;
    Mat img2;
    img.copyTo(img2);
   // rectangle(test, Point((x_min_f-30)<0?10:(x_min_f-30),(y_min_f-30)<0?10:(y_min_f-30)), Point((x_max_f+30)>1000?990:(x_max_f+30),(y_max_f+30)>1000?990:(y_max_f+30)), Scalar(0, 255, 255), 2);
    int width=((x_max+30)>1000?990:(x_max+30))-((x_min-30)<0?10:(x_min-30));
    int height= ((y_max+30)>1000?990:(y_max+30))-((y_min-30)<0?10:(y_min-30));
    Mat crop = img2(Rect((x_min-30)<0?10:(x_min-30),(y_min-30)<0?10:(y_min-30),width,height));
   // imshow("coped image",crop);
    /*
    Scalar big = mean( img2 );
    Scalar small = mean( crop );
    float value1=big.val[0]+big.val[1]+big.val[2],value2=small.val[0]+small.val[1]+small.val[2];
    if (value1<=value2) {
        flag=0;
    }
    else{
        flag=1;
    }
    return flag;
     */
    double max_big, min_big,max_small,min_small;
    cv::Point min_loc, max_loc;
    cv::minMaxLoc(img, &min_big, &max_big, &min_loc, &max_loc);
    cv::minMaxLoc(crop, &min_small, &max_small, &min_loc, &max_loc);
    cout<<max_big<<"   "<<max_small<<endl;
    cout<<min_big<<"   "<<min_small<<endl;

    if (abs(max_big-max_small)<0.01){
        flag=0;
    };
    return flag;

}

float mean_of_crop (Mat img, int x_min, int y_min, int x_max, int y_max,int thresh)
{
    int start_x = x_min-30<0 ? x_min:x_min-30;
    int start_y = y_min-30<0 ? y_min:y_min-30;
    int end_x = x_max+30>thresh ? x_max:x_max+30;
    int end_y = y_max+30>thresh ? y_max:y_max+30;
    Mat img2;
    img.copyTo(img2);
    Mat crop = img2(Rect(start_x,start_y,end_x-start_x,end_y-start_y));
    imshow("croped image",crop);
   // Scalar big = mean( img2 );
    Scalar small = mean( crop );
    return small.val[0]+small.val[1]+small.val[2];
   // float value1=big.val[0]+big.val[1]+big.val[2],value2=small.val[0]+small.val[1]+small.val[2];

}

int find_min (vector<int> vec)
{
    int min =10000;
    for(int i=0;i<vec.size();++i){
        if (vec[i]<=min) min=vec[i];
    }
    return min;
}
int find_max (vector<int> vec)
{
    int max = -1;
    for(int i=0;i<vec.size();++i){
        if (vec[i]>=max) max=vec[i];
    }
    return max;
}

int main(int argc, char** argv)
{
    for (int i =5; i < 312; i++) {
        char path[256] = {0};
        sprintf(path, "/Users/LiYisong/Desktop/SUEZ/Membrane/A/%d.bmp", i);
        string in;
        if (argc != 2) {
            //cout << "Usage: lsd_lines [input image]. Now loading ../data/building.jpg" << std::endl;
            in = path;
        } else {
            in = argv[1];
        }
        cout<<in<<endl;
        Mat src = imread(in);
        Mat show_image=src;
        resize(show_image,show_image,Size(1000,1000),0,0);
        //imshow("src",src);
        cvtColor(src,src,COLOR_BGR2GRAY);//转为灰度图
        //  Mat dst = imread(in,1);
        Mat src1 = src,src2 = src,src3 = src;
        Mat dst1, dst2, dst3;
        Mat image1,image2,image3;

        //resize(src1,image1,Size(1000,1000),0,0);
        resize(src1,image1,Size(1000,1000),0,0);
        resize(src2,image2,Size(3000,3000),0,0);
        resize(src3,image3,Size(200,200),0,0);

        int flag;
    #if 0
        Canny(image, image, 50, 200, 3); // Apply canny edge
    #endif
        // Create and LSD detector with standard or no refinement.
    #if 1
        Ptr<LineSegmentDetector> ls1 = createLineSegmentDetector(LSD_REFINE_ADV);
        Ptr<LineSegmentDetector> ls2 = createLineSegmentDetector(LSD_REFINE_ADV);
        Ptr<LineSegmentDetector> ls3 = createLineSegmentDetector(LSD_REFINE_ADV);
    #else
        Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_NONE);
    #endif
        double start = double(getTickCount());
        vector<Vec4f> lines_std1;
        vector<Vec4f> lines_std2;
        vector<Vec4f> lines_std3;

        vector<int> x_min,y_min,x_max,y_max;
        int x_min_f,y_min_f,x_max_f,y_max_f;
        // Detect the lines
        ls1->detect(image1, lines_std1);
        ls2->detect(image2, lines_std2);
        ls3->detect(image3, lines_std3);

        int max1_x=-1,max1_y=-1,min1_x=10000,min1_y=10000;
        int max2_x=-1,max2_y=-1,min2_x=10000,min2_y=10000;
        int max3_x=-1,max3_y=-1,min3_x=10000,min3_y=10000;

        int count1 = lines_std1.size();
        if (count1!=0) {
            for (int i = 0; i < count1; i++) {
                Vec4f p = lines_std1[i];
                //cout<<"p[0]= "<<p[0]<<"p[1]= "<<p[1]<<"p[2]= "<<p[2]<<"p[3]= "<<p[3]<<endl;
                if (p[0] >= max1_x) {
                    max1_x = p[0];
                }
                if (p[2] >= max1_x) {
                    max1_x = p[2];
                }
                if (p[0] <= min1_x) {
                    min1_x = p[0];
                }
                if (p[2] <= min1_x) {
                    min1_x = p[2];
                }
                if (p[1] >= max1_y) {
                    max1_y = p[1];
                }
                if (p[3] >= max1_y) {
                    max1_y = p[3];
                }
                if (p[1] <= min1_y) {
                    min1_y = p[1];
                }
                if (p[3] <= min1_y) {
                    min1_y = p[3];
                }
            }
        }
        int count2 = lines_std2.size();
        if (count2!=0) {
            for (int i = 0; i < count2; i++) {
                Vec4f p = lines_std2[i];
               // cout << p[0] << endl;
                if (p[0] >= max2_x) {
                    max2_x = p[0];
                }
                if (p[2] >= max2_x) {
                    max2_x = p[2];
                }
                if (p[0] <= min2_x) {
                    min2_x = p[0];
                }
                if (p[2] <= min2_x) {
                    min2_x = p[2];
                }
                if (p[1] >= max2_y) {
                    max2_y = p[1];
                }
                if (p[3] >= max2_y) {
                    max2_y = p[3];
                }
                if (p[1] <= min2_y) {
                    min2_y = p[1];
                }
                if (p[3] <= min2_y) {
                    min2_y = p[3];
                }
                //line(image2, Point(p[0],p[1]), Point(p[2],p[3]), Scalar(0, 255, 255), 3);
            }
        }

        int count3 = lines_std3.size();
        if (count3!=0) {
            for (int i = 0; i < count3; i++) {
                Vec4f p = lines_std3[i];
                //cout << p[0] << endl;
                if (p[0] >= max3_x) {
                    max3_x = p[0];
                }
                if (p[2] >= max3_x) {
                    max3_x = p[2];
                }
                if (p[0] <= min3_x) {
                    min3_x = p[0];
                }
                if (p[2] <= min3_x) {
                    min3_x = p[2];
                }
                if (p[1] >= max3_y) {
                    max3_y = p[1];
                }
                if (p[3] >= max3_y) {
                    max3_y = p[3];
                }
                if (p[1] <= min3_y) {
                    min3_y = p[1];
                }
                if (p[3] <= min3_y) {
                    min3_y = p[3];
                }
            }
        }
        double duration_ms = (double(getTickCount()) - start) * 1000 / getTickFrequency();
        std::cout << "It took " << duration_ms << " ms." << std::endl;
        Mat test;
//        image1.copyTo(test);
        show_image.copyTo(test);

       // src.copyTo(test);
        // Show found lines
        // Mat drawnLines(image);
        // ls->drawSegments(drawnLines, lines_std);
        if (max1_x!=-1){
            x_min.push_back(min1_x);
            y_min.push_back(min1_y);
            x_max.push_back(max1_x);
            y_max.push_back(max1_y);
           // int mean1 = mean_of_crop (image1, min1_x, min1_y, max1_x, max1_y,1000);
            //rectangle(image1, Point(min1_x,min1_y), Point(max1_x,max1_y), Scalar(0, 255, 255), 1);;
        }

        if (max2_x!=-1){
            max2_x=max2_x/3.0;max2_y=max2_y/3.0;min2_x=min2_x/3.0;min2_y=min2_y/3.0;
            x_min.push_back(min2_x);
            y_min.push_back(min2_y);
            x_max.push_back(max2_x);
            y_max.push_back(max2_y);
           // int mean2 = mean_of_crop (image2, min2_x, min2_y, max2_x, max2_y,3000);
           // rectangle(image1, Point(min2_x,min2_y), Point(max2_x,max2_y), Scalar(0, 255, 255), 1);
        }

        if (max3_x!=-1){
            max3_x=max3_x*5.0;max3_y=max3_y*5.0;min3_x=min3_x*5.0;min3_y=min3_y*5.0;
            x_min.push_back(min3_x);
            y_min.push_back(min3_y);
            x_max.push_back(max3_x);
            y_max.push_back(max3_y);
          //  int mean3 = mean_of_crop (image3, min3_x, min3_y, max3_x, max3_y,200);
          //  rectangle(image1, Point(min3_x,min3_y), Point(max3_x,max3_y), Scalar(0, 255, 255), 1);
        }
        if (max1_x==-1 && max2_x==-1 && max3_x==-1){
            cout<<"This image has no defect~~~~~~~~~~"<<endl;
            resize(image1,dst1,Size(500,500),0,0);
            putText(dst1,"No Defect",Point(50,60),FONT_HERSHEY_SIMPLEX,1,Scalar(255,23,0),4,8);//在图片上写文字
            imshow("Result", dst1);
        }
        else{
            cout<<"This image has defects!!!!!!!!"<<endl;
            x_min_f = find_min(x_min);
            y_min_f = find_min(y_min);
            x_max_f = find_max(x_max);
            y_max_f = find_max(y_max);
            flag = classify(image1,x_min_f,y_min_f,x_max_f,y_max_f);
            //cout<<"x_min "<<x_min_f<<"y_min "<<y_min_f<<"x_max "<<x_max_f<<"y_max "<<y_max_f<<endl;
            //cout<<"flag= "<<flag<<endl;
            rectangle(test, Point((x_min_f-30)<0?10:(x_min_f-30),(y_min_f-30)<0?10:(y_min_f-30)), Point((x_max_f+30)>1000?990:(x_max_f+30),(y_max_f+30)>1000?990:(y_max_f+30)), Scalar(0, 0, 255), 2);
            //resize(image1,dst1,Size(500,500),0,0);
            //imshow("Result1", dst1);
            resize(test,dst2,Size(700,700),0,0);
            if (flag==0){
                if (max3_x!=-1){
                    putText(dst2,"scratch",Point(50,60),FONT_HERSHEY_SIMPLEX,1,Scalar(255,23,0),4,8);//在图片上写文字

                }
                else {
                    putText(dst2, "light leak", Point(50, 60), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 23, 0), 4,
                            8);//在图片上写文字
                }
                imshow("Result", dst2);
               // imshow("defects detected!", dst2);

            }
            if (flag==1){
                putText(dst2,"stain",Point(50,60),FONT_HERSHEY_SIMPLEX,1,Scalar(255,23,0),4,8);//在图片上写文字
                imshow("Result", dst2);
               // imshow("defects detected!", dst2);

            }
        }

        /*
        cout<<max1_x<<"  "<<min1_x<<"  "<<max1_y<<"  "<<min1_y<<endl;
        cout<<max2_x<<"  "<<min2_x<<"  "<<max2_y<<"  "<<min2_y<<endl;
        cout<<max3_x<<"  "<<min3_x<<"  "<<max3_y<<"  "<<min3_y<<endl;
        */
        waitKey(0);
        destroyAllWindows();
    }

    return 0;
}