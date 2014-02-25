#include "MenuBarLayer.h"
#include "FarmScene.h"

using namespace cocos2d;

bool MenuBarLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, true);
    
    // Display Size
    CCSize visibleSize = pDirector->getVisibleSize();
    
    // Background Image for menu bar
    CCScale9Sprite* scale9Sprite = CCScale9Sprite::create("frame_v.png");
    scale9Sprite->setContentSize(ccp(visibleSize.width,visibleSize.height/10));
    scale9Sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height - scale9Sprite->getContentSize().height/2));
    this->addChild(scale9Sprite);
   
    // Go back to privious scene
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(MenuBarLayer::goBackScene));
    menuBackItem->setPosition(ccp(menuBackItem->getContentSize().width/2, visibleSize.height - menuBackItem->getContentSize().height/2));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack);
 
    // Send a message
    CCMenuItemImage* sendItemImg = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(MenuBarLayer::goBackScene));
    sendItemImg->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    CCMenu* menuSend = CCMenu::create(sendItemImg, NULL);
    menuSend->setPosition(CCPointZero);
    this->addChild(menuSend);
    
    // End
    return true;
}

bool MenuBarLayer::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    // can not touch on back layers
    return true;
}

void MenuBarLayer::menuCloseCallback(CCObject* pSender)
{
    this->removeFromParentAndCleanup(true);
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
}


void MenuBarLayer::goBackScene()
{
    CCLog("MenuBarLayer::goBackScene() => %s","running");
    CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInL::create(2.0f,FarmScene::scene()));
}