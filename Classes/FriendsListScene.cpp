#include "FriendsListScene.h"
#include "all_in_one.h"

CCScene * FriendsListScene::scene()
{
    CCScene * scene = CCScene::create();
    FriendsListScene * layer = FriendsListScene::create();
    scene->addChild(layer);
    return scene;
}

bool FriendsListScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
    {
    }
    
    // Set background
    //Setter::setBackground(this);
    
    this->main();
    
    return true;
}

void FriendsListScene::main()
{
    // Add swipe layer
    CCLayer * layer = SwipeLayer2::create();
    this->addChild(layer);
}