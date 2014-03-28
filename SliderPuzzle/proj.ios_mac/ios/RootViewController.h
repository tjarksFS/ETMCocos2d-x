//
//  CAMViewController.h
//  CameraTest
//
//  Created by Matthew Tjarks on 3/27/14.
//
//

#import <UIKit/UIKit.h>

@interface RootViewController : UIViewController <UIImagePickerControllerDelegate, UINavigationControllerDelegate>
{
    UIImage *image;
}
- (IBAction)takePhoto:(UIButton *)sender;
- (IBAction)selectPhoto:(UIButton *)sender;
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info;
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker;
@end
