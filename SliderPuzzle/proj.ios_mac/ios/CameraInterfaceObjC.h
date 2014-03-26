//
//  CameraInterfaceObjC.h
//  SliderPuzzle
//
//  Created by Matthew Tjarks on 3/26/14.
//
//

#import <UIKit/UIKit.h>

@interface CameraInterfaceObjC : UIViewController<UINavigationControllerDelegate, UIImagePickerControllerDelegate>
- (void) GetCameraPicture;
- (void) imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info;
@end
