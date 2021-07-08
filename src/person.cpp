#include "person.h"

#include <iostream>

using namespace std;

Person::Person() {
    velocity = ofVec3f(ofRandom(-0.2, 0.2), 0, ofRandom(-0.2, 0.2));
    
    //parenting head
    head.setParent(body);
    
    //parenting arm 1
    frontArm.setParent(armJoint); // front arm
    armJoint.setParent(backArm); //arm joint
    backArm.setParent(shoulderJoint); // back arm
    shoulderJoint.setParent(body); //body
    
    //parenting arm 2
    frontArm1.setParent(armJoint1); // front arm
    armJoint1.setParent(backArm1); //arm joint
    backArm1.setParent(shoulderJoint1); // back arm
    shoulderJoint1.setParent(body); //body
    
    //parenting leg 1
    shin.setParent(knee); // front arm
    knee.setParent(thigh); //arm joint
    thigh.setParent(thighJoint); // back arm
    thighJoint.setParent(body); //body
    
    //parenting leg 1
    shin1.setParent(knee1); // front arm
    knee1.setParent(thigh1); //arm joint
    thigh1.setParent(thighJoint1); // back arm
    thighJoint1.setParent(body); //body
    
    //setting position head
    head.setPosition(0, 20, 0);
    
    //setting positions arm 2
    shoulderJoint1.rotateDeg(20, 0, 0, 1);
    shoulderJoint1.setPosition(10, 10, 0);
    backArm1.setPosition(0, -10, 0);
    armJoint1.setPosition(0, -10, 0);
    frontArm1.setPosition(0, -10, 0);
    
    //setting position - arm 1
    shoulderJoint.rotateDeg(-20, 0, 0, 1);
    body.setPosition(0, 0, 0);
    backArm.setPosition(0, -10, 0);
    frontArm.setPosition(0, -10, 0);
    shoulderJoint.setPosition(-10, 10, 0);
    armJoint.setPosition(0, -10, 0);
    
    //setting positions leg 1
    thighJoint.setPosition(-10, -10, 0);
    thigh.setPosition(0, -10, 0);
    knee.setPosition(0, -10, 0);
    shin.setPosition(0, -10, 0);
    
    //setting positions leg 2
    thighJoint1.setPosition(10, -10, 0);
    thigh1.setPosition(0, -10, 0);
    knee1.setPosition(0, -10, 0);
    shin1.setPosition(0, -10, 0);
    
    //set dimentions head
    head.setRadius(20);
    
    //set dimentions - arm 1
    backArm.setHeight(20);
    backArm.setDepth(5);
    backArm.setWidth(5);
    frontArm.setHeight(20);
    frontArm.setWidth(5);
    frontArm.setDepth(5);
    armJoint.setRadius(1);
    shoulderJoint.setRadius(1);
    
    //body dimentions
    body.setHeight(20);
    body.setWidth(5);
    
    //set dimentions - arm 2
    backArm1.setHeight(20);
    backArm1.setWidth(5);
    backArm1.setDepth(5);
    frontArm1.setHeight(20);
    frontArm1.setWidth(5);
    frontArm1.setDepth(5);
    armJoint1.setRadius(1);
    shoulderJoint1.setRadius(1);
    
    //set dimentions leg 1
    thigh.setHeight(20);
    thigh.setDepth(5);
    thigh.setWidth(5);
    shin.setHeight(20);
    shin.setWidth(5);
    shin.setDepth(5);
    knee.setRadius(1);
    thighJoint.setRadius(1);
    
    //set dimentions - leg 2
    thigh1.setHeight(20);
    thigh1.setWidth(5);
    thigh1.setDepth(5);
    shin1.setHeight(20);
    shin1.setWidth(5);
    shin1.setDepth(5);
    knee1.setRadius(1);
    thighJoint1.setRadius(1);
    
    //set dimentions body
    body.setHeight(40);
    body.setWidth(20);
    body.setDepth(5);
}

//copy constructor
Person::Person(const Person & t) {
    velocity = ofVec3f(ofRandom(-0.3, 0.3), 0, ofRandom(-0.3, 0.3));
    
    body = t.body;
    //parenting head
    head.setParent(body);
    
    //parenting arm 1
    frontArm.setParent(armJoint); // front arm
    armJoint.setParent(backArm); //arm joint
    backArm.setParent(shoulderJoint); // back arm
    shoulderJoint.setParent(body); //body
    
    //parenting arm 2
    frontArm1.setParent(armJoint1); // front arm
    armJoint1.setParent(backArm1); //arm joint
    backArm1.setParent(shoulderJoint1); // back arm
    shoulderJoint1.setParent(body); //body
    
    //parenting leg 1
    shin.setParent(knee); // front arm
    knee.setParent(thigh); //arm joint
    thigh.setParent(thighJoint); // back arm
    thighJoint.setParent(body); //body
    
    //parenting leg 1
    shin1.setParent(knee1); // front arm
    knee1.setParent(thigh1); //arm joint
    thigh1.setParent(thighJoint1); // back arm
    thighJoint1.setParent(body); //body
    
    //setting position head
    head.setPosition(0, 20, 0);
    
    //setting positions arm 2
    shoulderJoint1.rotateDeg(20, 0, 0, 1);
    shoulderJoint1.setPosition(10, 10, 0);
    backArm1.setPosition(0, -10, 0);
    armJoint1.setPosition(0, -10, 0);
    frontArm1.setPosition(0, -10, 0);
    
    //setting position - arm 1
    shoulderJoint.rotateDeg(-20, 0, 0, 1);
    backArm.setPosition(0, -10, 0);
    frontArm.setPosition(0, -10, 0);
    shoulderJoint.setPosition(-10, 10, 0);
    armJoint.setPosition(0, -10, 0);
    
    //setting positions leg 1
    thighJoint.setPosition(-10, -10, 0);
    thigh.setPosition(0, -10, 0);
    knee.setPosition(0, -10, 0);
    shin.setPosition(0, -10, 0);
    
    //setting positions leg 2
    thighJoint1.setPosition(10, -10, 0);
    thigh1.setPosition(0, -10, 0);
    knee1.setPosition(0, -10, 0);
    shin1.setPosition(0, -10, 0);
    
    //set dimentions head
    head.setRadius(20);
    
    //set dimentions - arm 1
    backArm.setHeight(20);
    backArm.setDepth(5);
    backArm.setWidth(5);
    frontArm.setHeight(20);
    frontArm.setWidth(5);
    frontArm.setDepth(5);
    armJoint.setRadius(1);
    shoulderJoint.setRadius(1);
    
    //body dimentions
    body.setHeight(20);
    body.setWidth(5);
    
    //set dimentions - arm 2
    backArm1.setHeight(20);
    backArm1.setWidth(5);
    backArm1.setDepth(5);
    frontArm1.setHeight(20);
    frontArm1.setWidth(5);
    frontArm1.setDepth(5);
    armJoint1.setRadius(1);
    shoulderJoint1.setRadius(1);
    
    //set dimentions leg 1
    thigh.setHeight(20);
    thigh.setDepth(5);
    thigh.setWidth(5);
    shin.setHeight(20);
    shin.setWidth(5);
    shin.setDepth(5);
    knee.setRadius(1);
    thighJoint.setRadius(1);
    
    //set dimentions - leg 2
    thigh1.setHeight(20);
    thigh1.setWidth(5);
    thigh1.setDepth(5);
    shin1.setHeight(20);
    shin1.setWidth(5);
    shin1.setDepth(5);
    knee1.setRadius(1);
    thighJoint1.setRadius(1);
    
    //set dimentions body
    body.setHeight(40);
    body.setWidth(20);
    body.setDepth(5);
}

Person::~Person() {}

ofVec3f Person::getVelocity() {
    return velocity;
}

ofVec3f Person::setVelocity(ofVec3f _velocity) {
    velocity = _velocity;
}

ofVec3f Person::getPosition() {
    return body.getPosition();
}

bool Person::getCollision() {
    return isCollision;
}

bool Person::setCollisionOpposite() {
    isCollision = !isCollision;
}

bool Person::setCollisionFalse() {
    isCollision = false;
}
//this is used to time the wave simulation
int Person::startInteractionTimerClock() {
    if (personStopTimer < 100) {
        personStopTimer++;
    } else if (personStopTimer == 100) {
        personStopTimer = 0;
    }
}

void Person::setPosition(float x, float y, float z) {
    if (x < 5000 && x > 0)
        xPos = x;
    yPos = y;
    zPos = z;
    
    body.setPosition(xPos, yPos, zPos);
}

void Person::move(ofVec3f velocity) {
    velocity = velocity;
    body.move(velocity); //this just keeps adding these amounts to current position
    if (velocity.x > 0 || velocity.y > 0 || velocity.z) {
        moveLegs();
    }
    
    //This normalises the angle of rotation for negative velocities
    float myRotAngle;
    if (velocity.z < 0) {
        myRotAngle = (atan(velocity.x / velocity.z) * 180) / 3.14;
    } else if (velocity.z > 0) {
        myRotAngle = ((atan(velocity.x / velocity.z) * 180) / 3.14) - 180;
    }
    
    // for turning rotation - i had to convert a quaternion angle to a eular angle
    quat turnQuat;
    turnQuat = quat(w, x, y, z);
    vec3 EularTurnAngle(0, myRotAngle, 0);
    turnQuat = quat(EularTurnAngle);
    
    body.setOrientation(turnQuat);
    body.setOrientation(body.getOrientationQuat() * EularTurnAngle);
}

//animate the leg movement when velocity > 0
void Person::moveLegs() {
    float legTimer = ofGetFrameNum() % (20); //how long until next leg movement triggered
    if (legTimer == 0) {
        leftLeg = !leftLeg;
        a1 = 0;
        a2 = 0;
        a1 += PI / 10;
        a2 -= PI / 12; // this will add that amount to current position
    }
}

//this is a double pendelum formula to animate the walking legs
void Person::walkingAngles() {
    //applying equation of a double pendulum
    float num1 = -g * (2 * m1 + m2) * sin(a1);
    float num2 = -m2 * g * sin(a1 - 2 * a2);
    float num3 = -2 * sin(a1 - a2) * m2;
    float num4 = a2_v * a2_v * r2 + a1_v * a1_v * r1 * cos(a1 - a2);
    float den = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
    //angular acceleration - pendulum 1
    float a1_a = (num1 + num2 + num3 * num4) / den;
    
    num1 = 2 * sin(a1 - a2);
    num2 = a1_v * a1_v * r1 * (m1 + m2);
    num3 = g * (m1 + m2) * cos(a1);
    num4 = a2_v * a2_v * r2 * m2 * cos(a1 - a2);
    den = r2 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
    //angular acceleration- pendulum 2
    a2_a = (num1 * (num2 + num3 + num4)) / den;
    //angular velocity
    a1_v += a1_a;
    a2_v += a2_a;
    //angle effected by angular velocity
    a1 += a1_v;
    a2 += a2_v;
    //adds a dampening effect to act as drag and dampen the leg movement
    a1_v *= 0.85;
    a2_v *= 0.5;
    
    //Quaternion conversion
    quat MyQuaternion;
    quat stableQuat;
    quat armQuat;
    
    // Direct specification of the 4 components
    MyQuaternion = quat(w, x, y, z);
    
    // Conversion from Euler angles (in radians) to Quaternion
    vec3 EulerAngles((a1 * 180) / PI, 0, 0);
    MyQuaternion = quat(EulerAngles);
    
    vec3 stableAngle(0, 0, 0);
    stableQuat = quat(stableAngle);
    
    vec3 armAngle((a2 * 180) / PI, 0, 0);
    armQuat = quat(armAngle);
    
    //alternates which leg the angles apply to
    if (leftLeg) {
        thighJoint.setOrientation(stableQuat);
        thighJoint.setOrientation(thighJoint.getOrientationQuat() * EulerAngles);
        
        knee.setOrientation(armQuat);
        knee.setOrientation(knee.getOrientationQuat() * armAngle);
    }
    
    if (!leftLeg) {
        thighJoint1.setOrientation(stableQuat);
        thighJoint1.setOrientation(thighJoint1.getOrientationQuat() * EulerAngles);
        
        knee1.setOrientation(armQuat);
        knee1.setOrientation(knee1.getOrientationQuat() * armAngle);
    }
}

//this is to trigger function when distance is within a certain radius
void Person::personInteraction(vector < Person > & _people, int _personNum) {
    for (int i = 0; i < _people.size() && i != _personNum; i++) //this stops it including interaction with itself
    {
        //this sets velocity to 0 and tiggers iscollided to true
        float dist = getPosition().distance(_people[i].getPosition());
        if (dist < 30) //sets distance trigger
        {
            if (getCollision() == false && _people[i].getCollision() == false) {
                setVelocity(ofVec3f(0, 0, 0));
                _people[i].setVelocity(ofVec3f(0, 0, 0));
                setCollisionOpposite(); //set collision to true
                _people[i].setCollisionOpposite();
            }
        }
        if (dist > 40) //sets distance reset value
        { //this resets the collisions to false when they get 40m away from each other so they are open for another greeting/collisions
            if (getCollision() == true && _people[i].getCollision() == true) {
                setCollisionFalse(); //set Collision to false
                _people[i].setCollisionFalse(); //set Collision to false
            }
        }
        //this is saying if they have collided and their velocity is 0 to greet each other
        if (getCollision() == true && _people[i].getCollision() == true && getVelocity() == ofVec3f(0, 0, 0) && _people[i].getVelocity() == ofVec3f(0, 0, 0)) {
            helloInteraction();
            _people[i].helloInteraction();
            //this is a timer that stops the clap motion by giving them a velocity > 0 hence exiting the current if statement
            if (personStopTimer == 0) {
                ofVec3f oppositeVelocity = ofVec3f(ofRandom(-0.3, 0.3), 0, ofRandom(-0.3, 0.3));
                setVelocity(oppositeVelocity);
                oppositeVelocity *= -1;
                _people[i].setVelocity(oppositeVelocity);
                resetArmAfterWave();
                _people[i].resetArmAfterWave();
            }
        }
        std::cout << getCollision() << std::endl;
    }
}

//sets arm to original position
void Person::resetArmAfterWave() {
    quat armWaveQuat;
    armWaveQuat = quat(w, x, y, z);
    vec3 armWaveTurnAngle(0, 0, 0);
    armWaveQuat = quat(armWaveTurnAngle);
    
    armJoint.setOrientation(armWaveQuat);
    armJoint.setOrientation(armJoint.getOrientationQuat() * armWaveTurnAngle);
}

//this function basically rotates the arm
void Person::helloInteraction() {
    startInteractionTimerClock();
    int waveAngle = personStopTimer % 20;
    quat armWaveQuat;
    armWaveQuat = quat(w, x, y, z);
    vec3 armWaveTurnAngle(0, 0, waveAngle - 120);
    armWaveQuat = quat(armWaveTurnAngle);
    
    armJoint.setOrientation(armWaveQuat);
    armJoint.setOrientation(armJoint.getOrientationQuat() * armWaveTurnAngle);
}

//called in update to run the other update functions and update distance and person position for bounderies and interactions
void Person::updateInteraction(vector < Person > & _people, float checkdist, float boundradius, float bouncespeed, int _personNum) {
    //this constantly updates checking distance for boundery
    distToCheck = checkdist;
    
    //Keep Boids in a sphere
    checkBoundary(bouncespeed, boundradius);
    
    //update Person Position for interaction
    personPos = getPosition();
    
    personInteraction(_people, _personNum); //causes hello response
    
    walkingAngles(); //animates legs
    
}

//this just reverses the velocity when boundary is reached
void Person::checkBoundary(float bouncespeed, float size) {
    
    ofVec3f position = getPosition();
    ofVec3f desired = ofVec3f(0, 0, 0) - position;
    
    //The size variable is the radius of a sphere around the origin ofVec3f(0,0,0)
    if (desired.length() > size) {
        desired = desired.normalize() * bouncespeed;
        velocity = desired - velocity;
    }
}

//draw all the ofPrimitives
void Person::draw() {
    //draw head
    head.draw();
    
    // draw arm1
    frontArm.draw();
    backArm.draw();
    armJoint.draw();
    shoulderJoint.draw();
    
    //draw arm 2
    frontArm1.draw();
    backArm1.draw();
    armJoint1.draw();
    shoulderJoint1.draw();
    
    //draw leg1
    shin.draw();
    thigh.draw();
    knee.draw();
    thighJoint.draw();
    
    //draw leg 2
    shin1.draw();
    thigh1.draw();
    knee1.draw();
    thighJoint1.draw();
    
    //draw body
    body.draw();
}
