//
//  imageProcess.hpp
//  RtVideoStreamer2
//
//  Created by Coco Yuan on 2018/4/10.
//

#ifndef imageProcess_hpp
#define imageProcess_hpp

#include <stdio.h>

#include "ofApp.h"



typedef enum _PROCESS_TYPE
{
    DITHER_ORDERED=0,
    DITHER_FLOYD_STEINBERG,
    DITHER_ATKINSON,
    BINARY,
}PROCESS_TYPE;

class imageProcess
{
    
public:
    
    imageProcess(ofImage* imageIn, ofImage* imageOut);
    imageProcess();
    ~imageProcess();
    void setFxType(PROCESS_TYPE type);
    void conduct(ofImage* imageIn, ofImage* imageOut);
    vector<pair<PROCESS_TYPE,string>>  getFxList();
    
private:
    vector<pair<PROCESS_TYPE,string>> fxList=
    {
        {DITHER_ORDERED,"Dither ordered"},
        {DITHER_FLOYD_STEINBERG,"Dither floyd steinberge"},
        {DITHER_ATKINSON,"Dither atkinson"},
        {BINARY,"Binary"}
    };
    PROCESS_TYPE type;
    ofImage* imageIn;
    ofImage* imageOut;
    void process();

    
};

#endif /* imageProcess_hpp */
