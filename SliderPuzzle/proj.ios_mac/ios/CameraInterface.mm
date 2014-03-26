//
//  CameraInterface.m
//  SliderPuzzle
//
//  Created by Matthew Tjarks on 3/26/14.
//
//

#include "CameraInterface.h"
#import "cocos2d.h"
#import "CCEAGLView.h"

void CameraInterface::GetCameraPicture()
{
    // Create image picker controller
    UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
    
    // Set source to the camera
    imagePicker.sourceType =  UIImagePickerControllerSourceTypeCamera;
    
    // Delegate is self
    //imagePicker.delegate = this;
    
    // Allow editing of image ?
    //imagePicker.allowsImageEditing = NO;
    
    // Show image picker
    [[UIApplication sharedApplication] presentModalViewController:imagePicker animated:YES];

}

