#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include<QFileDialog>
#include<QDebug>
#include <QApplication>
#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QFileDialog>
#include<QMainWindow>
#include<QObject>
#include<iostream>


#include "yolo5.h"
#include<time.h>
using namespace cv;
using namespace std;



Net_config yolo_nets[5] = {
    {0.05, 0.2, 0.1, "best"},
    {0.5, 0.5, 0.5, "yolov5s"},
    {0.5, 0.5, 0.5,  "yolov5m"},
    {0.5, 0.5, 0.5, "yolov5l"},
    {0.5, 0.5, 0.5, "yolov5x"}
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YOLO yolo_model(yolo_nets[0]);
    while(1)
    {
        QString filename = QFileDialog::getOpenFileName(0,QObject::tr("Open Image"),".",QObject::tr("Image File (*.jpg *.png *.bmp)"));
        if(!(filename.isEmpty()))
        {
            qDebug()<<"选的文件是"<<filename;
            Mat srcimg = cv::imread(filename.toStdString());


            yolo_model.detect(srcimg);


            namedWindow("yolo", WINDOW_NORMAL);
            imshow("yolo", srcimg);
            waitKey(0);

            qDebug()<<"\n"<<"\n"<<"\n"<<"\n";
        }
    }
}
