#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "SlideTile.h"

class GameScene : public cocos2d::Layer
{
private:
    Vector<SlideTile*> tiles;
    int grid[3][3];
    int emptyRow;
    int emptyCol;
    int grabbedTileId;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void homeButtonCallback(cocos2d::Ref* pSender);
    void randButtonCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    void doStep(float delta);
};

#endif