#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
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
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
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
    
    auto label = LabelTTF::create("Game Scene", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"

    auto boardPic = Sprite::create("numberpicture.png");
    // position the sprite on the center of the screen
    //boardPic->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    float scale = (visibleSize.height / boardPic->getBoundingBox().size.height);
    //auto boardTexture = boardPic->getTexture();
    
    auto ulRect = Rect(0, 0, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    //auto ulSprite = Sprite::createWithTexture(boardTexture, ulRect);
    
    auto slideTile = SlideTile::createWithTexture(boardPic->getTexture(), ulRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 - slideTile->getBoundingBox().size.width, visibleSize.height / 2 + slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    
    auto umRect = Rect(boardPic->getTextureRect().size.width/3, 0, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), umRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2, visibleSize.height / 2 + slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    
    auto urRect = Rect(boardPic->getTextureRect().size.width*2/3, 0, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), urRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 + slideTile->getBoundingBox().size.width, visibleSize.height / 2 + slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    
    auto mlRect = Rect(0, boardPic->getTextureRect().size.height/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), mlRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 - slideTile->getBoundingBox().size.width, visibleSize.height / 2) );
    addChild(slideTile, 0);
    
    auto mRect = Rect(boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), mRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2, visibleSize.height / 2) );
    addChild(slideTile, 0);
    
    auto mrRect = Rect(boardPic->getTextureRect().size.width*2/3, boardPic->getTextureRect().size.height/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), mrRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 + slideTile->getBoundingBox().size.width, visibleSize.height / 2) );
    addChild(slideTile, 0);
    
    auto blRect = Rect(0, boardPic->getTextureRect().size.height*2/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), blRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 - slideTile->getBoundingBox().size.width, visibleSize.height / 2 - slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    
    auto bmRect = Rect(boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height*2/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), bmRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2, visibleSize.height / 2 - slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
    
    auto homeButton = MenuItemImage::create("homebutton.png", "homebutton.png",
                                            CC_CALLBACK_1(GameScene::homeButtonCallback, this));
    
    homeButton->setPosition(300, 300);
    auto homeButtonMenu = Menu::create(homeButton, nullptr);
    homeButtonMenu->setPosition(Point::ZERO);
    this->addChild(homeButtonMenu, 1);
    
    
    return true;
}

void GameScene::homeButtonCallback(Ref* pSender) {
    Director::getInstance()->popScene();
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

