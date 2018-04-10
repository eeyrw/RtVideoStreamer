//
//  imageProcess.cpp
//  RtVideoStreamer2
//
//  Created by Coco Yuan on 2018/4/10.
//

#include "imageProcess.hpp"

imageProcess::imageProcess (ofImage* imageIn, ofImage* imageOut)
{
    this->type=DITHER_ORDERED;
    this->imageIn=imageIn;
    this->imageOut=imageOut;
    process();
    
}

imageProcess::imageProcess()
{
    this->type=DITHER_ORDERED;
}

imageProcess::~imageProcess()
{
    
}

void imageProcess::conduct(ofImage* imageIn, ofImage* imageOut)
{
    this->imageIn=imageIn;
    this->imageOut=imageOut;
    process();
}

vector<pair<PROCESS_TYPE,string>> imageProcess::getFxList()
{
    return fxList;
}

void imageProcess::process()
{
    ofxDither od=ofxDither();
    switch (this->type) {
        case DITHER_ORDERED:
        od.dither_ordered(*imageIn, *imageOut);
            break;
        case DITHER_FLOYD_STEINBERG:
            od.dither_floyd_steinberg(*imageIn, *imageOut);
            break;
        case DITHER_ATKINSON:
            od.dither_atkinson(*imageIn, *imageOut);
            break;
        case BINARY:
            od.binary(*imageIn,*imageOut);
            break;
        default:
            break;
    }
}

void imageProcess::setFxType(PROCESS_TYPE type)
{
    this->type=type;
}
