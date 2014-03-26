#include "SlideTile.h"

SlideTile::SlideTile(void)
{
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
    SlideTile* pPaddle = new SlideTile();
    pPaddle->initWithTexture(aTexture);
    pPaddle->autorelease();
    
    return pPaddle;
}

SlideTile* SlideTile::createWithTexture(Texture2D* aTexture, const cocos2d::Rect& rect)
{
    SlideTile* pPaddle = new SlideTile();
    pPaddle->initWithTexture(aTexture, rect);
    pPaddle->autorelease();
    
    return pPaddle;
}

bool SlideTile::initWithTexture(Texture2D* aTexture)
{
    if( Sprite::initWithTexture(aTexture) )
    {
        _state = kPaddleStateUngrabbed;
    }
    
    return true;
}

bool SlideTile::initWithTexture(Texture2D* aTexture, const cocos2d::Rect& rect)
{
    if( Sprite::initWithTexture(aTexture, rect) )
    {
        _state = kPaddleStateUngrabbed;
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
    CCLOG("Paddle::onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);
    
    if (_state != kPaddleStateUngrabbed) return false;
    if ( !containsTouchLocation(touch) ) return false;
    
    _state = kPaddleStateGrabbed;
    CCLOG("return true");
    return true;
}

void SlideTile::onTouchMoved(Touch* touch, Event* event)
{
    // If it weren't for the TouchDispatcher, you would need to keep a reference
    // to the touch from touchBegan and check that the current touch is the same
    // as that one.
    // Actually, it would be even more complicated since in the Cocos dispatcher
    // you get Sets instead of 1 UITouch, so you'd need to loop through the set
    // in each touchXXX method.
    
    CCLOG("Paddle::onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);
    
    CCASSERT(_state == kPaddleStateGrabbed, "Paddle - Unexpected state!");
    
    auto touchPoint = touch->getLocation();
    
    setPosition( Point(touchPoint.x, touchPoint.y) );
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
    CCASSERT(_state == kPaddleStateGrabbed, "Paddle - Unexpected state!");
    
    _state = kPaddleStateUngrabbed;
} 
