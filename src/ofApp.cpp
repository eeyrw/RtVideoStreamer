#include "ofApp.h"
imageProcess ip;
//--------------------------------------------------------------
void ofApp::setup(){
    UiInitialize();
    ofBackground(255,255,255);
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ip=imageProcess();
}

void ofApp::loadVideo(ofxDatGuiButtonEvent e){
    vPlayer.setPaused(true);
        ofFileDialogResult result = ofSystemLoadDialog("Load file");
        if(result.bSuccess) {
            string path = result.getPath();
            if(vPlayer.isLoaded())
            {
                vPlayer.closeMovie();
                vPlayer.load(path);
                vPlayer.setLoopState(OF_LOOP_NONE);
                vPlayer.play();
            }
            else
            {
                vPlayer.load(path);
                vPlayer.setLoopState(OF_LOOP_NONE);
                vPlayer.play();
            }

        }
    vPlayer.setPaused(false);
}

void ofApp::playCtrl(ofxDatGuiButtonEvent e){
    if(vPlayer.isPaused())
    {
        vPlayer.setPaused(false);
    }
    else if(vPlayer.isPlaying())
    {
        vPlayer.setPaused(true);
    }
}

void ofApp::setVideoPos(ofxDatGuiSliderEvent e)
{
    if(vPlayer.isLoaded())
    {
        int totalFrame=vPlayer.getTotalNumFrames();
        vPlayer.setFrame(totalFrame*e.value);
    }
}

void ofApp::setVideoVol(ofxDatGuiSliderEvent e)
{
    if(vPlayer.isLoaded())
    {
        vPlayer.setVolume(e.value);
    }
}
void ofApp::setFxType(ofxDatGuiDropdownEvent e)
{
    ip.setFxType(static_cast<PROCESS_TYPE>(e.child));
}
//--------------------------------------------------------------
void ofApp::update(){
    vPlayer.update();
}

//--------------------------------------------------------------

void ofApp::processImage(){
    ofPixels & pixels = vPlayer.getPixels();
    ofPixels resizedPixels;
    resizedPixels.allocate(256, 160, OF_PIXELS_RGB);
    pixels.resizeTo(resizedPixels);
    

    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
    //    for (int i = 0; i < vidWidth; i+=vidWidth/128){
    //        for (int j = 0; j < vidHeight; j+=vidHeight/64){
    //            unsigned char r = resizedPixels[(j * 128 + i)*nChannels];
    //            float val = 1 - ((float)r / 255.0f);
    //            ofDrawCircle(700 + i*4,20+j*5,val>0.2?2:0);
    //        }
    //    }
    
    rawImg.setFromPixels(resizedPixels);
    greyImg.clone(rawImg);
    greyImg.setImageType(OF_IMAGE_GRAYSCALE);

    ip.conduct(&greyImg, &ditherImg1);
    
}

void ofApp::draw(){
    
    if(vPlayer.isLoaded())
    {
    ofSetHexColor(0xFFFFFF);
    
        if(vPlayer.isFrameNew())
        {
            processImage();
        }
        
        
        rawImg.draw(20,20);
        greyImg.draw(350,340);
        ditherImg1.draw(340, 20, 320, 240);
//        ditherImg2.draw(340+340, 20, 320, 240);
//        ditherImg3.draw(340+340+340, 20, 320, 240);
    

    
    ofSetHexColor(0x000000);
    
    ofDrawBitmapString("frame: " + ofToString(vPlayer.getCurrentFrame()) + "/"+ofToString(vPlayer.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(vPlayer.getPosition()*vPlayer.getDuration(),2) + "/"+ofToString(vPlayer.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(vPlayer.getSpeed(),2),20,420);
    
    if(vPlayer.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
