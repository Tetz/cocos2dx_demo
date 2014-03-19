#include "ModalLayer.h"

using namespace cocos2d;

bool ModalLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, true);
    CCSize visibleSize = pDirector->getVisibleSize();
    CCSprite* frame = CCSprite::create("HelloWorld.png");
    frame->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(frame);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "Send.png",
                                                          "SendHighlighted.png",
                                                          this,
                                                          menu_selector(ModalLayer::menuCloseCallback) );
    pCloseItem->setPosition(ccp(
                                visibleSize.width/2+frame->getContentSize().width/2-pCloseItem->getContentSize().width/2-10,
                                visibleSize.height/2+frame->getContentSize().height/2-pCloseItem->getContentSize().height/2-10));
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu);
    return true;
}

bool ModalLayer::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    // can not touch on back layers
    return true;
}

void ModalLayer::menuCloseCallback(CCObject* pSender)
{
    this->removeFromParentAndCleanup(true);
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
}