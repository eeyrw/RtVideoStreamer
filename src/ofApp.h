#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxDatGui.h"
#include "ofxDither.h"
#include "ui.hpp"
#include "imageProcess.hpp"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void loadVideo(ofxDatGuiButtonEvent e);
        void setVideoPos(ofxDatGuiSliderEvent e);
        void setVideoVol(ofxDatGuiSliderEvent e);
        void setFxType(ofxDatGuiDropdownEvent e);
    void playCtrl(ofxDatGuiButtonEvent e);
    void processImage();

    
        ofVideoPlayer   vPlayer;
        ofImage rawImg;
        ofImage greyImg;
        ofImage ditherImg1;
        ofImage ditherImg2;
        ofImage ditherImg3;
    
    
    
		
};
