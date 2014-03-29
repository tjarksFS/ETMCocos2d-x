#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "SlideTile.h"

class GameScene : public cocos2d::Layer
{
private:
    char* gamePic;
    Vector<SlideTile*> tiles;
    SlideTile* finalTile;
    int grid[3][3];
    int emptyRow;
    int emptyCol;
    int grabbedTileId;
    bool won;
    cocos2d::LabelTTF* wonLabel;
    cocos2d::LabelTTF* timeLabel;
    time_t startTime;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(const char* gamePic);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(const char* gamePic);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void homeButtonCallback(cocos2d::Ref* pSender);
    void randButtonCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    //CREATE_FUNC(GameScene);
    static GameScene* create(const char* gamePic)
    {
        GameScene *pRet = new GameScene();
        if (pRet && pRet->init(gamePic))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    void doStep(float delta);
    void setAllTiles();
    bool checkWin();
};

#endif