//
//  ui.hpp
//  RtVideoStreamer2
//
//  Created by Coco Yuan on 2018/4/10.
//

#ifndef ui_hpp
#define ui_hpp

#include <stdio.h>
#include "ofApp.h"


void UiInitialize(void);

class BiggerFontTheme : public ofxDatGuiTheme{
public:
    BiggerFontTheme(){
        font.size = 10;
        init();
    }
};


#endif /* ui_hpp */
