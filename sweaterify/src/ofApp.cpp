#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // video Input size
    vWidth = 640;
    vHeight = 480;
    vResolution = vHeight / vWidth;
    
    // knit canvas size
    knitWidth = 800;
    knitHeight = knitWidth * vResolution;
    
    // video preview on screen
    previewWidth = 200;
    
    // base setup for app
    grabber.setup(vWidth, vHeight);
    ofSetWindowShape(knitWidth + previewWidth, knitWidth * vResolution);
    ofBackground(0);
    
    // knitting vars for stitch shape
    sts = 80;
    rows = 80 * vResolution;
    sWidth = knitWidth / sts;
    sHeight = knitWidth * vResolution / rows;
    dip = sHeight / 2;
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}


//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(0,0, previewWidth, previewWidth *  vResolution);

    for (int x = 0; x < knitWidth; x += sWidth){
        for (int y = 0; y < knitHeight; y += sHeight){

//            float color = dither(grabber.getPixels().getColor(ofMap(x, 0, knitWidth, 0, vWidth), ofMap(y, 0, knitHeight, 0, vHeight)).getBrightness(), x/sWidth, y/sHeight);
            float color = threshold(grabber.getPixels().getColor(ofMap(x, 0, knitWidth, 0, vWidth), ofMap(y, 0, knitHeight, 0, vHeight)).getBrightness());
            if(color == 0) {
                // base color
                ofSetColor(50, 204, 183);
            } else {
                // accent color
                ofSetColor(242, 248, 255);
            }
            ofFill();
            knit(previewWidth + x, y);
// OUTLINE the knit stitch shape
//            ofNoFill();
//            ofSetColor(80);
//            knit(previewWidth + x, y);
        }
    }
}

float ofApp::threshold(float brightness) {
    float c = 0;
    if (brightness > 127) {
        c = 1;
    } else {
        c = 0;
    }
    return c;
}

float ofApp::dither(float brightness, int x, int y){
    float c = 0;
    float bayermatrix[16] = {
        0,  128,  32,  160,
        192, 64,  224, 96,
        48,  176, 16,  144,
        240, 112,  208, 80
    };
    
    if (brightness > bayermatrix[((x % 4) * 4) + (y % 4)]) {
        c = 1;
    } else {
        c = 0;
    }

    return c;
}

void ofApp::knit(int x, int y) {
    // right side of "V" in knit stitch graphics
    ofBeginShape();
    ofVertex(x + (sWidth/2), y + dip);
    ofBezierVertex(x + sWidth - (sWidth / 3),y - (sHeight / 12), x + sWidth - (sWidth / 3),y - (sHeight / 12), x + sWidth - (sWidth / 10), y - sHeight / 4);
    ofBezierVertex(x + sWidth - (sWidth / 50), y, x + sWidth - (sWidth / 50), y, x + sWidth - (sWidth / 70), y + (sHeight / 10));
    ofBezierVertex(x + sWidth, y + (sHeight / 4), x + sWidth, y + (sHeight * 0.50), x + sWidth - (sWidth / 15), y + (sHeight * 0.66));
    ofBezierVertex(x + sWidth - (sWidth * 0.3), y + sHeight, x + sWidth - (sWidth * 0.3), y + sHeight, x + sWidth - (sWidth / 2) + (sWidth / 20), y + sHeight + sHeight / 3);
    ofBezierVertex(x + sWidth - (sWidth * 0.55), y + (sHeight * 0.7),x + sWidth - (sWidth * 0.55), y + (sHeight * 0.7), x + sWidth - (sWidth / 2), y + dip);
    ofEndShape();
    
    // left side
    ofBeginShape();
    ofVertex(x + (sWidth/2), y + dip);
    ofBezierVertex(x + (sWidth * 0.4), y + (sHeight / 12), x + (sWidth * 0.4), y + (sHeight / 12), x + (sWidth / 10), y - sHeight / 4);
    ofBezierVertex(x + (sWidth / 50), y, x + (sWidth / 50), y, x + (sWidth / 70), y + (sHeight / 10));
    ofBezierVertex(x, y + (sHeight / 4), x, y + (sHeight * 0.50), x + (sWidth / 15), y + (sHeight * 0.66));
    ofBezierVertex(x + (sWidth * 0.3), y + sHeight, x + (sWidth * 0.3), y + sHeight, x + (sWidth / 2) - (sWidth / 20), y + sHeight + sHeight / 3);
    ofBezierVertex(x + (sWidth * 0.56), y + (sHeight + sHeight / 4), x + (sWidth * 0.56), y + (sHeight + sHeight / 4), x + (sWidth / 2) - sWidth * 0.05, y + dip);
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    knitWidth = w - previewWidth;
    knitHeight = (w - previewWidth) * vResolution;
    sWidth = (w - previewWidth) / sts;
    sHeight = (w - previewWidth) * vResolution / rows;
    dip = sHeight / 2;
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
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
