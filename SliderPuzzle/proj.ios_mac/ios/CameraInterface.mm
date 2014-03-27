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
#import "CAMViewController.h"
#import "cocos2d.h"
#import "CCEAGLView.h"

void CameraInterface::GetCameraPicture()
{
    
    //CameraInterfaceObjC *ci = [[CameraInterfaceObjC alloc] init];
    //[ci GetCameraPicture];
    CameraInterfaceObjC *ci = [[[CameraInterfaceObjC alloc] init] autorelease];

    UIApplication* clientApp = [UIApplication sharedApplication];
    
    UIWindow* topWindow = [clientApp keyWindow];

    if (!topWindow) {
        topWindow = [[clientApp windows] objectAtIndex:0];
    }
                //ci.view.frame = CGRectMake(100, 100, 200, 200);
    [((AppController *)clientApp.delegate).viewController presentModalViewController:ci animated:YES];
        //[controller.viewController.view addSubview:ci.view];
    //controller.viewController.view = ci.view;
        //[ci GetCameraPicture];
}

