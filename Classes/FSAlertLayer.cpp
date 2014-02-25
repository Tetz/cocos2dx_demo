#include "FSAlertLayer.h"
USING_NS_CC;

// create with 2 buttons
FSAlertLayer* FSAlertLayer::create(const char* message, CCObject *target, SEL_CallFuncN okSelector, SEL_CallFuncN ngSelector)
{
    FSAlertLayer* layer = FSAlertLayer::create();
    layer->setStyle(message, target, okSelector, ngSelector);
    return layer;
}


// create with only 1 button
FSAlertLayer* FSAlertLayer::create(const char* message, CCObject *target, SEL_CallFuncN okSelector)
{
    return FSAlertLayer::create(message, target, okSelector, NULL);
}


bool FSAlertLayer::init()
{
    // half clear black bgcolor
    if (! CCLayerColor::initWithColor(ccc4(0, 0, 0, 100))) {
        return false;
    }
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, true);
    
    CCSize vsize = pDirector->getVisibleSize();
    
    // bg
    CCSprite* frame = CCSprite::create("dialog_yellow.png");
    frame->setTag(FSAlertLayerTagFrame);
    frame->setPosition(ccp(vsize.width / 2, vsize.height / 2));
    this->addChild(frame);
    
    return true;
}


void FSAlertLayer::setStyle(const char* message, CCObject *target, SEL_CallFuncN okSelector, SEL_CallFuncN ngSelector)
{
    this->target        = target;
    this->okSelector    = okSelector;
    this->ngSelector    = ngSelector;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // message
    CCLabelTTF *pMsg = CCLabelTTF::create(message, "", 40);
    pMsg->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2  + 50));
    pMsg->setColor(ccc3(0,0,0));
    this->addChild(pMsg);
    
    // OK Button
    CCMenuItemImage *pOKItem = CCMenuItemImage::create("button_ok.png", "button_ok_dark.png", this, menu_selector(FSAlertLayer::menuAlertOK));
    
    int btnHeight = visibleSize.height / 2 - this->getChildByTag(FSAlertLayerTagFrame)->getContentSize().height / 2 + pOKItem->getContentSize().height / 2 + 10;
    
    pOKItem->setTag(FSAlertLayerTagOK);
    pOKItem->setPosition(ccp(visibleSize.width / 2, btnHeight +10));
    
    CCMenu* pMenu = CCMenu::create(pOKItem, NULL);
    pMenu->setPosition(CCPointZero);
    pMenu->setTag(FSAlertLayerTagMenu);
    this->addChild(pMenu);
    
    // set as 2 buttons
    if (ngSelector) {
        pOKItem->setPosition(ccp(visibleSize.width / 2 - pOKItem->getContentSize().width, btnHeight +10));
        
        // NG btn
        CCMenuItemImage* pNGItem = CCMenuItemImage::create("button_no.png", "button_no_2.png", this, menu_selector(FSAlertLayer::menuAlertClose));
        pNGItem->setTag(FSAlertLayerTagNG);
        pNGItem->setPosition(ccp(visibleSize.width / 2 + pOKItem->getContentSize().width, btnHeight +10));
        pMenu->addChild(pNGItem);
    }
}


// touch event disable other layers
bool FSAlertLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return true;
}


void FSAlertLayer::menuAlertOK(CCObject* pSender)
{
    CCLOG("OK");
    
    this->menuAlertClose(pSender);
    
    if (this->target && this->okSelector) {
        (this->target->*this->okSelector)(this);
    }
}


void FSAlertLayer::menuAlertClose(CCObject *pSender)
{
    this->removeFromParentAndCleanup(true);
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    if (((CCNode*)pSender)->getTag() == FSAlertLayerTagNG && this->target && this->ngSelector) {
        (this->target->*this->ngSelector)(this);
    }
}