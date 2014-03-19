#include "MainMenuBarLayer.h"
#include "FarmScene.h"

using namespace cocos2d;

bool MainMenuBarLayer::init()
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
    this->addChild(scale9Sprite,4);
    
    // Go back to privious scene
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(MainMenuBarLayer::goBackScene));
    menuBackItem->setPosition(ccp(menuBackItem->getContentSize().width/2, visibleSize.height - menuBackItem->getContentSize().height/2));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    //this->addChild(menuBack);
    
    // Send a message
    CCMenuItemImage* sendItemImg = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(MainMenuBarLayer::goBackScene));
    sendItemImg->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    CCMenu* menuSend = CCMenu::create(sendItemImg, NULL);
    menuSend->setPosition(CCPointZero);
    //this->addChild(menuSend);
    
    // EditBox
    CCEditBox* editBox;
    CCSize editBoxSize = CCSizeMake(100, 100);
    editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("frame_g.png"));
    editBox->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    editBox->setFontColor(ccBLUE);
    editBox->setPlaceHolder("");
    editBox->setMaxLength(100);
    editBox->setFontSize(24);
    editBox->setDelegate(this);
    editBox->setTag(_EDITBOX_);
    editBox->setInputMode(kEditBoxInputModeAny);
    //editBox->setReturnType(kKeyboardReturnTypeSend);
    this->addChild(editBox,5);
    
    // End
    return true;
}

bool MainMenuBarLayer::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    // can not touch on back layers
    return true;
}

void MainMenuBarLayer::menuCloseCallback(CCObject* pSender)
{
    this->removeFromParentAndCleanup(true);
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
}


void MainMenuBarLayer::goBackScene()
{
    CCLog("MainMenuBarLayer::goBackScene() => %s","running");
    CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInL::create(2.0f,FarmScene::scene()));
}

void MainMenuBarLayer::editBoxEditingDidBegin(CCEditBox* editBox){
    //CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInB::create(2.0f,SendScene::scene()));
}
void MainMenuBarLayer::editBoxEditingDidEnd(CCEditBox* editBox){}
void MainMenuBarLayer::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void MainMenuBarLayer::editBoxReturn(CCEditBox* editBox){
    inputText = editBox->getText();
}