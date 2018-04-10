#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    UiInitialize();
    ofBackground(255,255,255);
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
}

void ofApp::loadVideo(ofxDatGuiButtonEvent e){
        ofFileDialogResult result = ofSystemLoadDialog("Load file");
        if(result.bSuccess) {
            string path = result.getPath();
            vPlayer.load(path);
            vPlayer.setLoopState(OF_LOOP_NORMAL);
            //fingerMovie.setVolume(0);
            vPlayer.play();
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
//--------------------------------------------------------------
void ofApp::update(){
    vPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(vPlayer.isPlaying())
    {
    ofSetHexColor(0xFFFFFF);
    
    //vPlayer.draw(20,20,320,240);
    
    ofPixels & pixels = vPlayer.getPixels();
    
    
    ofPixels resizedPixels;
    resizedPixels.allocate(256, 160, OF_PIXELS_RGB);
    pixels.resizeTo(resizedPixels);
    
    int vidWidth = resizedPixels.getWidth();
    int vidHeight = resizedPixels.getHeight();
    int nChannels = resizedPixels.getNumChannels();
    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
    //    for (int i = 0; i < vidWidth; i+=vidWidth/128){
    //        for (int j = 0; j < vidHeight; j+=vidHeight/64){
    //            unsigned char r = resizedPixels[(j * 128 + i)*nChannels];
    //            float val = 1 - ((float)r / 255.0f);
    //            ofDrawCircle(700 + i*4,20+j*5,val>0.2?2:0);
    //        }
    //    }
    
    ofImage oim;
    ofSetColor(ofColor::white);
    oim.setFromPixels(resizedPixels);
    oim.draw(20,20);
    ofSetColor(ofColor::white);
    oim.setImageType(OF_IMAGE_GRAYSCALE);
    oim.draw(350,340);
    ofxDither od=ofxDither();
    ofImage dout;
    od.dither_atkinson(oim, dout);
    dout.draw(340, 20, 320, 240);
    od.dither_floyd_steinberg(oim, dout);
    dout.draw(340+340, 20, 320, 240);
    od.dither_ordered(oim, dout);
    dout.draw(340+340+340, 20, 320, 240);
    
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
