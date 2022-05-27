#pragma once

#include "ofMain.h"

#define NUM 30

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void drawSquares(int x, int y, float scaleX, float scaleY, float dist, int constraint);

    
    glm::vec2 posV[NUM][NUM];
    //glm::vec2 dist[NUM][NUM];
    float sizeGrid;
    float counter;
    float rectW;
    float rectH;
    float tX;
    float tY;
    float distMultiply;
    glm::vec2 myCenter;
    glm::vec2 myMouse;
    bool keyWasPressed;
    bool keyWasReleased;
    
    



};
