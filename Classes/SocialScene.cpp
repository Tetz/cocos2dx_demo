#include "SocialScene.h"
#include "all_in_one.h"

CCScene * SocialScene::scene()
{
    CCScene * scene = CCScene::create();
    SocialScene * layer = SocialScene::create();
    scene->addChild(layer);
    return scene;
}

bool SocialScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,200,255,255)) )
    {
    }
    
    // Set background
    //Setter::setBackground(this);
    
    this->main();
    
    return true;
}

void SocialScene::main()
{
    // Add swipe layer
    CCLayer * layer = SwipeLayer3::create();
    this->addChild(layer);
}