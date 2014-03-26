#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "cocos2d.h"
USING_NS_CC;

typedef enum tagPaddleState
{
    kPaddleStateGrabbed,
    kPaddleStateUngrabbed
} PaddleState;

class SlideTile : public Sprite, public Clonable
{
    PaddleState        _state;
    
public:
    SlideTile(void);
    virtual ~SlideTile(void);
    
    Rect getRect();
    bool initWithTexture(Texture2D* aTexture);
    bool initWithTexture(Texture2D* aTexture, const cocos2d::Rect& rect);
    virtual void onEnter() override;
    virtual void onExit() override;
    bool containsTouchLocation(Touch* touch);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    virtual SlideTile* clone() const;
    
    static SlideTile* createWithTexture(Texture2D* aTexture);
    static SlideTile* createWithTexture(Texture2D* aTexture, const cocos2d::Rect& rect);
};

#endif
