#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene(const char* gamePic)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create(gamePic);

    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init(const char* gamePic)
{
    srand(time(0));
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

    // add "HelloWorld" splash screen"

    auto boardPic = Sprite::create(gamePic);//"numberpicture.png");
    
    //In case of some error in retrieving the picture taken by camera, create with default picture.
    if (boardPic == nullptr)
        boardPic = Sprite::create("numberpicture.png");
    
    // Calculate the scale based on smaller of two dimensions
    float scaleVert = (visibleSize.height / boardPic->getBoundingBox().size.height);
    float scaleHoriz = (visibleSize.width / boardPic->getBoundingBox().size.width);
    float scale = scaleVert < scaleHoriz ? scaleVert : scaleHoriz;
    //auto boardTexture = boardPic->getTexture();
    
    // Initialize "invisible" tile so we can fade it in when puzzle is solved
    auto brRect = Rect(boardPic->getTextureRect().size.width*2/3, boardPic->getTextureRect().size.height*2/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    auto slideTile = SlideTile::createWithTexture(boardPic->getTexture(), brRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 + slideTile->getBoundingBox().size.width, visibleSize.height / 2 - slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    slideTile->_id = 9;
    slideTile->row = 2;
    slideTile->col = 2;
    finalTile = slideTile;
    finalTile->setVisible(false);
    finalTile->setOpacity(0);
    
    
    // Create all other tiles and add to vector
    auto ulRect = Rect(0, 0, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), ulRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 - slideTile->getBoundingBox().size.width, visibleSize.height / 2 + slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    slideTile->_id = 1;
    slideTile->row = 0;
    slideTile->col = 0;
    tiles.pushBack(slideTile);
    
    auto umRect = Rect(boardPic->getTextureRect().size.width/3, 0, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), umRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2, visibleSize.height / 2 + slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    slideTile->_id = 2;
    slideTile->row = 0;
    slideTile->col = 1;
    tiles.pushBack(slideTile);
    
    auto urRect = Rect(boardPic->getTextureRect().size.width*2/3, 0, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), urRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 + slideTile->getBoundingBox().size.width, visibleSize.height / 2 + slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    slideTile->_id = 3;
    slideTile->row = 0;
    slideTile->col = 2;
    tiles.pushBack(slideTile);
    
    auto mlRect = Rect(0, boardPic->getTextureRect().size.height/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), mlRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 - slideTile->getBoundingBox().size.width, visibleSize.height / 2) );
    addChild(slideTile, 0);
    slideTile->_id = 4;
    slideTile->row = 1;
    slideTile->col = 0;
    tiles.pushBack(slideTile);
    
    auto mRect = Rect(boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), mRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2, visibleSize.height / 2) );
    addChild(slideTile, 0);
    slideTile->_id = 5;
    slideTile->row = 1;
    slideTile->col = 1;
    tiles.pushBack(slideTile);
    
    auto mrRect = Rect(boardPic->getTextureRect().size.width*2/3, boardPic->getTextureRect().size.height/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), mrRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 + slideTile->getBoundingBox().size.width, visibleSize.height / 2) );
    addChild(slideTile, 0);
    slideTile->_id = 6;
    slideTile->row = 1;
    slideTile->col = 2;
    tiles.pushBack(slideTile);
    
    auto blRect = Rect(0, boardPic->getTextureRect().size.height*2/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), blRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2 - slideTile->getBoundingBox().size.width, visibleSize.height / 2 - slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    slideTile->_id = 7;
    slideTile->row = 2;
    slideTile->col = 0;
    tiles.pushBack(slideTile);
    
    auto bmRect = Rect(boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height*2/3, boardPic->getTextureRect().size.width/3, boardPic->getTextureRect().size.height/3);
    slideTile = SlideTile::createWithTexture(boardPic->getTexture(), bmRect);
    slideTile->setScale(scale);
    slideTile->setPosition( Point(visibleSize.width / 2, visibleSize.height / 2 - slideTile->getBoundingBox().size.height) );
    addChild(slideTile, 0);
    slideTile->_id = 8;
    slideTile->row = 2;
    slideTile->col = 1;
    tiles.pushBack(slideTile);
    

    
    
    
    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    emptyRow = 2;
    emptyCol = 2;
    grabbedTileId = 0;
    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[0][2] = 3;
    grid[1][0] = 4;
    grid[1][1] = 5;
    grid[1][2] = 6;
    grid[2][0] = 7;
    grid[2][1] = 8;
    grid[2][2] = -1;
    won = false;
    wonLabel = nullptr;
    time(&startTime);

    auto homeButton = MenuItemImage::create("homebutton.png", "homebutton.png",
                                            CC_CALLBACK_1(GameScene::homeButtonCallback, this));
    
    homeButton->setPosition(15 + homeButton->getBoundingBox().size.width / 2, visibleSize.height - 15 - homeButton->getBoundingBox().size.height);
    auto homeButtonMenu = Menu::create(homeButton, nullptr);
    homeButtonMenu->setPosition(Point::ZERO);
    this->addChild(homeButtonMenu, 1);
    
    auto randButton = MenuItemImage::create("randbutton.png", "randbutton.png",
                                            CC_CALLBACK_1(GameScene::randButtonCallback, this));
    
    randButton->setPosition(15 + randButton->getBoundingBox().size.width / 2, visibleSize.height - 15 - randButton->getBoundingBox().size.height - homeButton->getBoundingBox().size.height - 20);
    auto randButtonMenu = Menu::create(randButton, nullptr);
    randButtonMenu->setPosition(Point::ZERO);
    this->addChild(randButtonMenu, 1);

    timeLabel = LabelTTF::create("30 seconds", "Arial", 24);
    // position the label on the center of the screen
    timeLabel->setPosition(Point(origin.x + visibleSize.width - timeLabel->getContentSize().width/2 - 20, origin.y + visibleSize.height - timeLabel->getContentSize().height - 15));
    
    // add the label as a child to this layer
    this->addChild(timeLabel, 1);
    
    // Randomize game board
    randButtonCallback(this);
    
    // Set up doStep to be called
    schedule( schedule_selector(GameScene::doStep) );
    return true;
}

void GameScene::doStep(float delta)
{
    if (won) {
        return;
    }
    time_t endTime;
    time(&endTime);
    int timeRamaining = (int)(30.0 - difftime(endTime, startTime));
    if (timeRamaining < 0)
    {
        timeRamaining = 0;
    }
    std::ostringstream oss;
    oss << timeRamaining << " seconds";
    timeLabel->setString(oss.str());
    
    if (timeRamaining <= 0) {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point origin = Director::getInstance()->getVisibleOrigin();
        
        auto label = LabelTTF::create("YOU LOSE...", "Arial", 48);
        label->setColor(cocos2d::Color3B::RED);
        // position the label on the center of the screen
        label->setPosition(Point(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height/2));
        
        // add the label as a child to this layer
        this->addChild(label, 1);
        wonLabel = label;
        won = true;
        return;
    }
    
    for (auto& tile : tiles)
    {
        if (tile->_state == TileGrabbed)
        {
            grabbedTileId = tile->_id;
            if (tile->col + 1 == emptyCol && tile->row == emptyRow)
            {
                tile->moveRight = true;
            }
            if (tile->col == emptyCol && tile->row + 1 == emptyRow)
            {
                tile->moveDown = true;
            }
            if (tile->col - 1 == emptyCol && tile->row == emptyRow)
            {
                tile->moveLeft = true;
            }
            if (tile->col == emptyCol && tile->row - 1 == emptyRow)
            {
                tile->moveUp = true;
            }
        }
        if (tile->_state == TileUngrabbed && grabbedTileId == tile->_id) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (grid[row][col] == grabbedTileId && (row != tile->row || col != tile->col)) {
                        grid[row][col] = -1;
                        grid[emptyRow][emptyCol] = grabbedTileId;
                        emptyRow = row;
                        emptyCol = col;
                    }
                }
            }
            grabbedTileId = 0;
        }
    }
    
    if ((won = checkWin()))
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point origin = Director::getInstance()->getVisibleOrigin();
        
        auto label = LabelTTF::create("YOU WIN!!", "Arial", 48);
        label->setColor(cocos2d::Color3B::RED);
        // position the label on the center of the screen
        label->setPosition(Point(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height/2));
        
        // add the label as a child to this layer
        this->addChild(label, 1);
        wonLabel = label;
        
        finalTile->setVisible(true);
        auto fadeAction = FadeIn::create(2.0f);
        finalTile->runAction(fadeAction);
    }
    
}

void GameScene::homeButtonCallback(Ref* pSender) {
    Director::getInstance()->popScene();
}

void GameScene::randButtonCallback(Ref* pSender) {
    for (int moves = 0; moves < 100; moves++)
    {
        int randRow = emptyRow;
        int randCol = emptyCol;
        int move = rand() % 4 + 1;
        switch (move) {
            case 1:
                randRow--;
                break;
                
            case 2:
                randRow++;
                break;
                
            case 3:
                randCol--;
                break;
                
            case 4:
                randCol++;
                break;
                
            default:
                break;
        }
        
        if (randRow >=0 && randRow < 3 && randCol >=0 && randCol < 3)
        {
            tiles.at(grid[randRow][randCol]-1)->row = emptyRow;
            tiles.at(grid[randRow][randCol]-1)->col = emptyCol;
            int temp = grid[emptyRow][emptyCol];
            grid[emptyRow][emptyCol] = grid[randRow][randCol];
            grid[randRow][randCol] = temp;
            emptyRow = randRow;
            emptyCol = randCol;
        }
    }
    won = false;
    if (wonLabel != nullptr)
    {
        this->removeChild(wonLabel);
        wonLabel = nullptr;
    }
    setAllTiles();
    finalTile->setOpacity(0);
    
    finalTile->setVisible(false);
    time(&startTime);
}

void GameScene::setAllTiles()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    for (auto& tile : tiles)
    {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                int moveHoriz = col - 1;
                int moveVert = -1*(row-1);
                if (grid[row][col] == tile->_id) {
                    tile->setPosition( Point(visibleSize.width / 2 + moveHoriz * tile->getBoundingBox().size.width, visibleSize.height / 2 + moveVert * tile->getBoundingBox().size.height) );
                    tile->row = row;
                    tile->col = col;
                }
                
            }
        }
        
    }
}

bool GameScene::checkWin()
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row][col] != row * 3 + col + 1 && grid[row][col] != -1) {
                return false;
            }
        }
    }
    return true;
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
