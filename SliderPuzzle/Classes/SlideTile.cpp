#include "SlideTile.h"

SlideTile::SlideTile(void)
{
    moveRight = false;
    moveLeft = false;
    moveDown = false;
    moveUp = false;
}

SlideTile::~SlideTile(void)
{
}

Rect SlideTile::getRect()
{
    auto s = getBoundingBox().size;
    return Rect(-s.width / 2, -s.height / 2, s.width, s.height);
}

SlideTile* SlideTile::createWithTexture(Texture2D* aTexture)
{
    SlideTile* tile = new SlideTile();
    tile->initWithTexture(aTexture);
    tile->autorelease();
    
    return tile;
}

SlideTile* SlideTile::createWithTexture(Texture2D* aTexture, const cocos2d::Rect& rect)
{
    SlideTile* tile = new SlideTile();
    tile->initWithTexture(aTexture, rect);
    tile->autorelease();
    
    return tile;
}

bool SlideTile::initWithTexture(Texture2D* aTexture)
{
    if( Sprite::initWithTexture(aTexture) )
    {
        _state = TileUngrabbed;
    }
    
    return true;
}

bool SlideTile::initWithTexture(Texture2D* aTexture, const cocos2d::Rect& rect)
{
    if( Sprite::initWithTexture(aTexture, rect) )
    {
        _state = TileUngrabbed;
    }
    
    return true;
}


void SlideTile::onEnter()
{
    Sprite::onEnter();
    
    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(SlideTile::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(SlideTile::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(SlideTile::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void SlideTile::onExit()
{
    //    auto director = Director::getInstance();
    //    director->getTouchDispatcher()->removeDelegate(this);
    Sprite::onExit();
}

bool SlideTile::containsTouchLocation(Touch* touch)
{
    //return getRect().containsPoint(convertTouchToNodeSpaceAR(touch));
    return getBoundingBox().containsPoint(touch->getLocation());
}

bool SlideTile::onTouchBegan(Touch* touch, Event* event)
{
    if (_state != TileUngrabbed) return false;
    if ( !containsTouchLocation(touch) ) return false;
    
    touchStartPos = getPosition();
    
    _state = TileGrabbed;
    return true;
}

void SlideTile::onTouchMoved(Touch* touch, Event* event)
{
    auto touchPoint = touch->getLocation();

    if (moveRight)
    {
        float moveX = touchPoint.x;
        if (moveX < touchStartPos.x)
            moveX = touchStartPos.x;
        if (moveX > touchStartPos.x + getBoundingBox().size.width)
            moveX = touchStartPos.x + getBoundingBox().size.width;
        setPosition( Point(moveX, touchStartPos.y) );
    }
    if (moveLeft)
    {
        float moveX = touchPoint.x;
        if (moveX > touchStartPos.x)
            moveX = touchStartPos.x;
        if (moveX < touchStartPos.x - getBoundingBox().size.width)
            moveX = touchStartPos.x - getBoundingBox().size.width;
        setPosition( Point(moveX, touchStartPos.y) );
    }
    if (moveUp)
    {
        float moveY = touchPoint.y;
        if (moveY < touchStartPos.y)
            moveY = touchStartPos.y;
        if (moveY > touchStartPos.y + getBoundingBox().size.height)
            moveY = touchStartPos.y + getBoundingBox().size.height;
        setPosition( Point(touchStartPos.x, moveY) );
    }
    if (moveDown)
    {
        float moveY = touchPoint.y;
        if (moveY > touchStartPos.y)
            moveY = touchStartPos.y;
        if (moveY < touchStartPos.y - getBoundingBox().size.height)
            moveY = touchStartPos.y - getBoundingBox().size.height;
        setPosition( Point(touchStartPos.x, moveY) );
    }
//    setPosition( Point(touchPoint.x, getPosition().y) );
}

SlideTile* SlideTile::clone() const
{
    SlideTile* ret = SlideTile::createWithTexture(_texture);
    ret->_state = _state;
    ret->setPosition(getPosition());
    ret->setAnchorPoint(getAnchorPoint());
    return ret;
}

void SlideTile::onTouchEnded(Touch* touch, Event* event)
{
    if (moveDown || moveLeft || moveRight || moveUp)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point touchPos = getPosition();
    
        Point finalPos;
        finalPos.x = visibleSize.width / 2;
        col = 1;
        if (touchPos.x < visibleSize.width / 2 - getBoundingBox().size.width / 2) {
            finalPos.x -= getBoundingBox().size.width;
            col--;
        }
        else if (touchPos.x > visibleSize.width / 2 + getBoundingBox().size.width / 2) {
            finalPos.x += getBoundingBox().size.width;
            col++;
        }
    
        finalPos.y = visibleSize.height / 2;
        row = 1;
        
        if (touchPos.y < visibleSize.height / 2 - getBoundingBox().size.height / 2) {
            finalPos.y -= getBoundingBox().size.height;
            row++;
        }
        else if (touchPos.y > visibleSize.height / 2 + getBoundingBox().size.height / 2) {
            finalPos.y += getBoundingBox().size.height;
            row--;
        }
        setPosition( finalPos );
        moveRight = false;
        moveLeft = false;
        moveDown = false;
        moveUp = false;
    }
    _state = TileUngrabbed;
} 
