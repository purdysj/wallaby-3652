#include "camerafunc.h"

#define STD_OBJECT_HEIGHT_MM 30
#define CAMERA_HEIGHT_MM 100

#define x 'x'
#define y 'y'
#define z 'z'

bool cameraEnabled = false;

void setupCamera(const char* config)
{
    camera_open_black();
    
    if(camera_open_black() != 1)
        return;

    camera_load_config(config);
    
    cameraEnabled = true;

    while(1 == 1)
        run();
}

int getDimensions(char axis, int channel, int object)
{
    switch(axis)
    {
        case 'x':
            return get_object_bbox_width(channel, object);
            break;
        case 'y':
            return get_object_bbox_height(channel, object);
            break;
        default:
            break;
    } 
    return 0;
}



int calcDist()
{
    return (STD_OBJECT_HEIGHT_MM * get_camera_height()) / (getDimensions(y, 0, 0));
}

int calcDistEx(int channel, int object) // change channel, change object
{
    return (STD_OBJECT_HEIGHT_MM * get_camera_height()) / (getDimensions(y, channel, object));
}


void runCamera()
{
    while(!cameraEnabled)
        return;

    //TODO: Add code. xd         
}