//
//  CAMViewController.m
//  CameraTest
//
//  Created by Matthew Tjarks on 3/27/14.
//
//

#import "RootViewController.h"
#import "AppController.h"
#import "MyGameViewController.h"

@interface RootViewController ()


@end

@implementation RootViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    image = NULL;
    hasSelectedPhoto = NO;

     
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)startGame:(UIButton *)sender {
    MyGameViewController *controller=[[[MyGameViewController alloc] init] autorelease];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *localFilePath = [documentsDirectory stringByAppendingPathComponent:@"chosenPic.png"];
    
    if (hasSelectedPhoto) {
        controller.filePath = localFilePath;
    }
    else {
        controller.filePath = @"numberpicture.png";
    }
    

    [self presentModalViewController:controller animated:YES];
}

 - (IBAction)takePhoto:(UIButton *)sender {
     if (![UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
         
         UIAlertView *myAlertView = [[UIAlertView alloc] initWithTitle:@"Error"
                                                               message:@"Device has no camera"
                                                              delegate:nil
                                                     cancelButtonTitle:@"OK"
                                                     otherButtonTitles: nil];
         
         [myAlertView show];
         return;
     }
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
    picker.allowsEditing = YES;
    picker.sourceType = UIImagePickerControllerSourceTypeCamera;
    
    [self presentViewController:picker animated:YES completion:NULL];
    
}


- (IBAction)selectPhoto:(UIButton *)sender {
    
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
    picker.allowsEditing = YES;
    picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    
    [self presentViewController:picker animated:YES completion:NULL];
    
    
}
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    
    image = info[UIImagePickerControllerEditedImage];

    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *localFilePath = [documentsDirectory stringByAppendingPathComponent:@"chosenPic.png"];
    
    [UIImagePNGRepresentation(image) writeToFile:localFilePath options:NSDataWritingAtomic error:NULL];
    hasSelectedPhoto = YES;
    [picker dismissViewControllerAnimated:YES completion:NULL];
    
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    
    
    [picker dismissViewControllerAnimated:YES completion:NULL];
    
}

@end
