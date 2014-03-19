#include "SwipeLayer.h"
#include "allScene.h"

using namespace cocos2d;

CCScene* SwipeLayer::scene()
{
    CCScene *scene = CCScene::create();
    SwipeLayer *layer = SwipeLayer::create();
    scene->addChild(layer);
    return scene;
}

bool SwipeLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setTouchEnabled(true);
    
    return true;
}

void SwipeLayer::xtTouchesBegan(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesBegan");
}

void SwipeLayer::xtTouchesMoved(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesMoved");
}

void SwipeLayer::xtTouchesEnded(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesEnded");
}

void SwipeLayer::xtTouchesBegan(CCPoint position)
{
    CCLog("xtTouchesBegan x: %f, y: %f", position.x, position.y);
}

void SwipeLayer::xtTouchesMoved(CCPoint position)
{
    CCLog("xtTouchesMoved x: %f, y: %f", position.x, position.y);
}

void SwipeLayer::xtTouchesEnded(CCPoint position)
{
    CCLog("xtTouchesEnded x: %f, y: %f", position.x, position.y);
}

void SwipeLayer::xtTapGesture(CCPoint position)
{
    CCLog("xtTapGesture x: %f, y: %f", position.x, position.y);
}

void SwipeLayer::xtDoubleTapGesture(CCPoint position)
{
    CCLog("xtDoubleTapGesture x: %f, y: %f", position.x, position.y);
}

void SwipeLayer::xtLongTapGesture(CCPoint position)
{
    CCLog("xtLongTapGesture x: %f, y: %f", position.x, position.y);
}

void SwipeLayer::xtSwipeGesture(XTTouchDirection direction, float distance, float speed)
{
    std::string directionStr = "";
    switch (direction) {
        case XTLayer::UP:    directionStr = "UP";    break;
        case XTLayer::DOWN:  directionStr = "DOWN";  break;
        case XTLayer::LEFT:  directionStr = "LEFT";  break;
        case XTLayer::RIGHT: directionStr = "RIGHT"; break;
        default:break;
    }
    
    CCLog("xtSwipeGesture direction: %s, distance: %f, speed: %f", directionStr.c_str(), distance, speed);
    if (directionStr == "LEFT")
    {
        CCScene* scene = FriendsListScene::scene();
        CCTransitionMoveInL* tran = CCTransitionMoveInL::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
    }
    CCLog("xtSwipeGesture direction: %s, distance: %f, speed: %f", directionStr.c_str(), distance, speed);
    if (directionStr == "RIGHT")
    {
        CCScene* scene = SocialScene::scene();
        CCTransitionMoveInR* tran = CCTransitionMoveInR::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
    }
}