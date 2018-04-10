//
//  ui.cpp
//  RtVideoStreamer2
//
//  Created by Coco Yuan on 2018/4/10.
//

#include "ui.hpp"
extern ofApp* app;
ofxDatGui* gui;
ofxDatGuiButton* btnOpenFile;
ofxDatGuiTextInput* textIpAddr;
ofxDatGuiSlider* sldFrame;
ofxDatGuiSlider* sldVol;


void onTextInputEvent(ofxDatGuiTextInputEvent e)
{
    cout << e.text <<endl;
}
void UiInitialize(void)
{
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    gui->setTheme(new BiggerFontTheme());
    
    btnOpenFile=gui->addButton("OPEN VIDEO FILE");
    btnOpenFile->onButtonEvent(app,&ofApp::loadVideo);
    
    sldFrame = gui->addSlider("VIDEO POS", 0, 1);
    sldFrame->onSliderEvent(app,&ofApp::setVideoPos);
    
    sldVol = gui->addSlider("VIDEO VOL", 0, 1);
    sldVol->onSliderEvent(app,&ofApp::setVideoVol);
    
    
    textIpAddr=gui->addTextInput("IP Address", "192.168.1.134:346376");
    textIpAddr->onTextInputEvent(&onTextInputEvent);
    vector<string> options = {"ONE", "TWO", "THREE", "FOUR"};
    gui->addDropdown("AA",options);
    gui->addFRM();
}
