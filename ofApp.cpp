#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    rectW = 5;
    rectH = 5;
    sizeGrid=80;
    counter=0;
    tX=0;
    tY=0;
    distMultiply=1;
    
    for(int x=0; x<NUM; x++){
        for(int y=0; y<NUM; y++){
            posV[x][y]={x*sizeGrid,y*sizeGrid};
        }
    }
    keyWasPressed=false;
    keyWasReleased=false;
}

//--------------------------------------------------------------
void ofApp::update(){
    //counter++;
    myMouse={mouseX,mouseY};
  /*  if(keyWasPressed){
        if(distMultiply>0.5){
            distMultiply-=0.1;
        }
    }else{
        distMultiply=2;
    }
    */
   float time = ofGetElapsedTimef()*1;
   distMultiply = ofNoise(time)*1;
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    counter+=0.05;
    float scaleX = 1;
    float scaleY = 1;
    for(int x=0; x<NUM; x++){
        for(int y=0; y<NUM; y++){
            float dist=glm::distance(posV[x][y], myMouse)*distMultiply;
            if(keyWasPressed){
                ofNoFill();
                drawSquares(x,y,scaleX, scaleY,dist,200);
            }else{
                ofFill();
                drawSquares(x,y,scaleX, scaleY,dist,100);
            }
        }
    }
}

void ofApp::drawSquares(int x, int y, float scaleX, float scaleY, float dist, int constraint){
    rectH=ofClamp(ofMap(ofNoise(x*scaleX*dist/1000,y*scaleY*dist/1000,counter), 0, 1, 0, dist/2), 0, constraint);
    rectW=ofClamp(ofMap(ofNoise(x*scaleX*dist/1000,y*scaleY*dist/1000,counter+1), 0, 1, 0 ,dist/2),0,constraint);
    ofPushMatrix();
    ofTranslate(posV[x][y]);
    //ofRotateZDeg(ofGetFrameNum());
    ofDrawRectangle(0,0,rectW,rectH);
    ofPopMatrix();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        keyWasPressed=!keyWasPressed;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
