#ifndef PERSON_H
#define PERSON_H

#include "ofMain.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
using namespace glm;

//references used in code:
//https://openframeworks.cc/documentation/3d/ofNode/#show_rotateDeg
//https://www.youtube.com/watch?v=uWzPe_S-RVE&t=1551s
//Boids class example

class Person
{
public:
    Person();
    ~Person();
    Person(const Person& t);//copy constructor
    void move(ofVec3f velocity);//to be called in update
    void updateInteraction(vector<Person>& _people, float checkdist,float boundradius, float bouncespeed, int _personNum);//to be called in update
    void draw();
    ofVec3f getVelocity();
    ofVec3f getPosition();
    void setPosition(float x, float y, float z);
    
private:
    void helloInteraction();//for hello movement
    void resetArmAfterWave();//set arm back to original position after waive
    void checkBoundary(float speed, float size);//checks to see if gone out of radius
    void walkingAngles();//double pendulum calculation for leg movement
    
    //various direction vectors
    ofVec3f oppositeVelocity(); //to apply to people after waive
    ofVec3f setVelocity(ofVec3f _velocity);
    ofVec3f velocity;
    ofVec3f personPos;
    
    //person interaction data
    void personInteraction(vector<Person>& _people,int _personNum);
    int startInteractionTimerClock();
    int personStopTimer = 0;
    
    //collision booleans
    bool getCollision();
    bool setCollisionOpposite();
    bool setCollisionFalse();
    bool isCollision = false;
    
    float distToCheck; //check distance from boundery
    
    //position for getPosition vector
    float xPos;
    float yPos;
    float zPos;

    void moveAngleCalc(float x, float z);
    void moveLegs();
    
    //right arm
    ofBoxPrimitive backArm;
    ofBoxPrimitive frontArm;
    ofSpherePrimitive shoulderJoint;
    ofSpherePrimitive armJoint;
    
    //other arm
    ofBoxPrimitive backArm1;
    ofBoxPrimitive frontArm1;
    ofSpherePrimitive shoulderJoint1;
    ofSpherePrimitive armJoint1;
    
    //other arm
    ofBoxPrimitive thigh; //backarm
    ofBoxPrimitive shin;//front arm
    ofSpherePrimitive thighJoint;//thighJoint
    ofSpherePrimitive knee;//armjoint
    
    //other arm
    ofBoxPrimitive thigh1;
    ofBoxPrimitive shin1;
    ofSpherePrimitive thighJoint1;
    ofSpherePrimitive knee1;
    
    //body
    ofBoxPrimitive body;
    
    //head
    ofSpherePrimitive head;
    
    // data members for pendulum equation
    float a1 = 0;
    float a2 = 0;
    float r1 = 200;
    float r2 = 200;
    float m1 = 40;
    float m2 = 40;
    float x1;
    float x2;
    float y1;
    float y2;
    float a1Deg = 30;
    float a2Deg = 20;

    float a1_v = 0;
    float a2_v = 0;
    float a2_a = 0;
    float g = 1;
    float degRot = 0;//delete
    float pa1;
    float pa2;
    ofNode rotation;
    float w;
    float x;
    float y;
    float z;
    float myX; //tester
    float armPosx = -100;
    float armPosy = -100;
    float sizeScale = 0.5;
    bool leftLeg = true;
};

#endif 
