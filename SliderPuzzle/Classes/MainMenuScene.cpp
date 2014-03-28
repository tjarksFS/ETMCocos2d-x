#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene(const char* path)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();
    layer->gamePic = path;
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    auto helpButton = MenuItemImage::create("helpbutton.png", "helpbutton.png",
                                            CC_CALLBACK_1(MainMenuScene::helpButtonCallback, this));
    auto gameButton = MenuItemImage::create("gamebutton.png", "gamebutton.png",
                                            CC_CALLBACK_1(MainMenuScene::gameButtonCallback, this));
                                            
    helpButton->setPosition(100, 200);
    gameButton->setPosition(200, 300);
                                            
    auto helpButtonmenu = Menu::create(helpButton, nullptr);
    helpButtonmenu->setPosition(Point::ZERO);
    this->addChild(helpButtonmenu,1);
    
    auto gameButtonmenu = Menu::create(gameButton, nullptr);
    gameButtonmenu->setPosition(Point::ZERO);
    this->addChild(gameButtonmenu,1);
    
    
    return true;
}


void MainMenuScene::helpButtonCallback(Ref* pSender) {
    Director::getInstance()->pushScene(HelpScene::createScene());
}

void MainMenuScene::gameButtonCallback(Ref* pSender) {
    Director::getInstance()->pushScene(GameScene::createScene(gamePic));
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
