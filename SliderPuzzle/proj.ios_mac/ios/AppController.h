#import <UIKit/UIKit.h>

@class RootViewController;

@interface AppController : UIResponder <UIApplicationDelegate> {
    //UIWindow *window;
    //RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;

@property (nonatomic, retain) RootViewController *viewController;

@end

