//
//  MyModalViewController.m
//  SliderPuzzle
//
//  Created by Matthew Tjarks on 3/27/14.
//
//

#import "MyGameViewController.h"

#include "cocos2d.h"
//#import "EAGLView.h"
#import "CCEAGLView.h"
#include "MainMenuScene.h"

@interface MyGameViewController ()

@end

@implementation MyGameViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        //[self.image alloc];
    }
    return self;
}

-(void)loadOpenglScene:(CGRect)rect {
    /*
     cocos2d::Application::sharedApplication().run();
    
    EAGLView *glView = [EAGLView viewWithFrame: rect
                                   pixelFormat: kEAGLColorFormatRGBA8
                                   depthFormat: GL_DEPTH_COMPONENT16_OES
                            preserveBackbuffer: NO
                                    sharegroup:nil
                                 multiSampling:NO
                               numberOfSamples:0];
    
    [self.view insertSubview:glView atIndex:0];
    
    cocos2d::CCDirector *pDirector = cocos2d::CCDirector::sharedDirector();
    
    pDirector->setOpenGLView(&cocos2d::CCEGLView::sharedOpenGLView());
    
	// enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    // pDirector->enableRetinaDisplay(true);
    
	// turn on display FPS
	pDirector->setDisplayFPS(true);
    
	// pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);
    
	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);
    
	// create a scene. it's an autorelease object
    cocos2d::Scene *pScene = MainMenuScene::createScene();
    
	// run
	pDirector->runWithScene(pScene);
    
    // to avoid BAD ACCESS when calling CCDirector::end()
    [[EAGLView sharedEGLView] retain];
    
    
    */
    
    
   // auto app = cocos2d::Application::getInstance();
   // app->run();
    
    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: rect
                                   pixelFormat: kEAGLColorFormatRGBA8
                                   depthFormat: GL_DEPTH_COMPONENT24_OES
                            preserveBackbuffer: NO
                                    sharegroup:nil
                                 multiSampling:NO
                               numberOfSamples:0];
    
    cocos2d::GLView *glView = GLView::createWithEAGLView(eaglView);
    
    [self.view insertSubview:eaglView atIndex:0];
    // initialize director
    auto director = Director::getInstance();
    //auto glview = director->getOpenGLView();
    //if(!glview) {
    //    glview = GLView::create("My Game");
    //    director->setOpenGLView(glview);
    //}
    
    director->setOpenGLView(glView);
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    //auto director = Director::getInstance();
    //NSString *nss = @"chosenPic.png";
    //cocos2d::Sprite *spr = Sprite::create("numberpicture.png");
    
    // create a scene. it's an autorelease object
    auto scene = MainMenuScene::createScene([self.filePath UTF8String]);
    
    // run
    director->runWithScene(scene);
    //director->resume();
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    // create navigation bar with "Close" button
    //UINavigationBar *bar=[[[UINavigationBar alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 49)] autorelease];
    //[self.view insertSubview:bar atIndex:0];
    
    
    //UIBarButtonItem *closeButton=[[[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStyleDone target:self action:@selector(close)] autorelease];
    
    //UINavigationItem *item = [[UINavigationItem alloc] initWithTitle:@""];
    //item.rightBarButtonItem = closeButton;
    //item.hidesBackButton = YES;
    //[bar pushNavigationItem:item animated:NO];
    //[item release];
    
    // add opengl view on the remaining space of the view
    [self loadOpenglScene:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
}

-(void)viewDidDisappear:(BOOL)animated {
    cocos2d::Director *pDirector = cocos2d::Director::getInstance();
    pDirector->end();
}

- (void)viewDidUnload {
    //[[CCEAGLView sharedEGLView] release];
//    cocos2d::Director *pDirector = cocos2d::Director::getInstance();
    
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

-(void)close {
    [self dismissModalViewControllerAnimated:YES];
}

@end
