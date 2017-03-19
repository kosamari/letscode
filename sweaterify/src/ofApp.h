#pragma once

#include "ofMain.h"

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
    
    
        void knit(int x, int y);
        float dither(float brightness, int x, int y);
        float threshold(float brightness);
        float sts;
        float rows;
        float sWidth;
        float sHeight;
        float dip;
        float vResolution;
        float previewWidth;
        float vWidth;
        float vHeight;
        float knitWidth;
        float knitHeight;

    ofVideoGrabber grabber;
};
