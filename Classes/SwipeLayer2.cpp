#include "SwipeLayer2.h"
#include "allScene.h"


using namespace cocos2d;

CCScene* SwipeLayer2::scene()
{
    CCScene *scene = CCScene::create();
    SwipeLayer2 *layer = SwipeLayer2::create();
    scene->addChild(layer);
    return scene;
}

bool SwipeLayer2::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setTouchEnabled(true);
    
    return true;
}

void SwipeLayer2::xtTouchesBegan(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesBegan");
}

void SwipeLayer2::xtTouchesMoved(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesMoved");
}

void SwipeLayer2::xtTouchesEnded(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesEnded");
}

void SwipeLayer2::xtTouchesBegan(CCPoint position)
{
    CCLog("xtTouchesBegan x: %f, y: %f", position.x, position.y);
}

void SwipeLayer2::xtTouchesMoved(CCPoint position)
{
    CCLog("xtTouchesMoved x: %f, y: %f", position.x, position.y);
}

void SwipeLayer2::xtTouchesEnded(CCPoint position)
{
    CCLog("xtTouchesEnded x: %f, y: %f", position.x, position.y);
}

void SwipeLayer2::xtTapGesture(CCPoint position)
{
    CCLog("xtTapGesture x: %f, y: %f", position.x, position.y);
}

void SwipeLayer2::xtDoubleTapGesture(CCPoint position)
{
    CCLog("xtDoubleTapGesture x: %f, y: %f", position.x, position.y);
}

void SwipeLayer2::xtLongTapGesture(CCPoint position)
{
    CCLog("xtLongTapGesture x: %f, y: %f", position.x, position.y);
}

void SwipeLayer2::xtSwipeGesture(XTTouchDirection direction, float distance, float speed)
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
    if (directionStr == "RIGHT")
    {
        CCScene* scene = FarmScene::scene();
        CCTransitionMoveInR* tran = CCTransitionMoveInR::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
    }
    
    if (directionStr == "LEFT")
    {
        CCScene* scene = SocialScene::scene();
        CCTransitionMoveInL* tran = CCTransitionMoveInL::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
    }

}