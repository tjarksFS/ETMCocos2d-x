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

    director->setOpenGLView(glView);
    
    director->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    auto scene = MainMenuScene::createScene([self.filePath UTF8String]);
    
    // run
    director->runWithScene(scene);
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    // add opengl view on the remaining space of the view
    [self loadOpenglScene:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
}

-(void)viewDidDisappear:(BOOL)animated {
    cocos2d::Director *pDirector = cocos2d::Director::getInstance();
    pDirector->end();
}

- (void)viewDidUnload {

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
