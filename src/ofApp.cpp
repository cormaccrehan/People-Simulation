#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    ofEnableLighting();
    light.setPointLight();
    light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    light.setPosition(ofGetWidth()*.5,
                      ofGetHeight()*.5, 300);
    light.enable();
    ofEnableNormalizedTexCoords();
    ofSetBackgroundColor(0, 0, 0);
    for(int i = 0; i < 5; i++)
    {
        Person p;
        p.setPosition(ofRandom(-200,200), 0, ofRandom(-200,200));
        people.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < people.size(); i++)
    {
        people[i].updateInteraction(people, 2000,300,0.1, i);//vector,distance to check, radius size, bounce speed when hitting radius, person number in vector
        people[i].move(ofVec3f(people[i].getVelocity())); //note: when I tried adding people.move into update interaction it seemed to add a spin effect
    }
}

void ofApp::drawAxis() {
    ofPushStyle();
    
    // X = RED = sideways = WIDTH
    ofSetLineWidth(3);
    ofSetColor(255, 0, 0);
    ofDrawLine(0, 0, 0, 100, 0, 0);
    
    // Y = GREEN = upward and downward = HEIGHT
    ofSetLineWidth(3);
    ofSetColor(0, 255, 0);
    ofDrawLine(0, 0, 0, 0, 100, 0);
    
    // Z = BLUE = toward / backward from camera = DEPTH
    ofSetLineWidth(3);
    ofSetColor(0, 0, 255);
    ofDrawLine(0, 0, 0, 0, 0, 100);
    
    ofPopStyle();
}

void ofApp::drawGrid() {
    ofPushStyle();
    ofPushMatrix();
    ofSetLineWidth(1);
    ofSetColor(200);
    float size = 100;
    int num = 8;
    // draw lines along the flat XZ plane
    for(int i = 0; i <= num; i++){
        ofDrawLine( (i * size) - (size*num/2), 0, -size*num/2, (i * size) - (size*num/2), 0, size*num/2);
        ofDrawLine( -size*num/2, 0, (i * size) - (size*num/2), size*num/2, 0, (i * size) - (size*num/2));
    }
    ofPopMatrix();
    ofPopStyle();
}
//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    drawAxis();
    drawGrid();

    
    for(Person& p : people)
    {
        p.draw();
    }
    
    cam.end();
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
