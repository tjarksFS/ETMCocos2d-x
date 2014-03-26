//
//  CameraInterface.m
//  SliderPuzzle
//
//  Created by Matthew Tjarks on 3/26/14.
//
//

#import "CameraInterface.h"
#import "CameraInterfaceObjC.h"
#include "AppController.h"
#include "RootViewController.h"
//#import "cocos2d.h"
#import "CCEAGLView.h"

void CameraInterface::GetCameraPicture()
{
    //CameraInterfaceObjC *ci = [[CameraInterfaceObjC alloc] init];
    //[ci GetCameraPicture];
    
    id sth = [[UIApplication sharedApplication] delegate];
    if ([sth isKindOfClass:[AppController class]]) {
        CameraInterfaceObjC *ci = [[CameraInterfaceObjC alloc] init];
        ci.view.frame = CGRectMake(100, 100, 200, 200);
        AppController *controller = (AppController *)sth;
        [controller.viewController.view addSubview:ci.view];
        //[ci GetCameraPicture];
    }
}

