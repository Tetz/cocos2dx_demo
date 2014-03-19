#include "SendScene.h"
#include "FarmScene.h"

CCScene * SendScene::scene()
{
    CCScene * scene = CCScene::create();
    SendScene * layer = SendScene::create();
    scene->addChild(layer);
    return scene;
}

bool SendScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,200,255,255)) )
    {
    }
    // Add Menu bar
    //CCLayer * menuBar = MenuBarLayer::create();
    //this->addChild(menuBar);
    
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
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(SendScene::goBackScene));
    menuBackItem->setPosition(ccp(menuBackItem->getContentSize().width/2, visibleSize.height - menuBackItem->getContentSize().height/2));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack);
    
    // Send a message
    CCMenuItemImage* sendItemImg = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(SendScene::goBackScene));
    sendItemImg->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    CCMenu* menuSend = CCMenu::create(sendItemImg, NULL);
    menuSend->setPosition(CCPointZero);
    this->addChild(menuSend);
    
    // Main Logic
    this->main();
    
    return true;
}

void SendScene::main()
{

}

void SendScene::onClick1()
{
    
}

void SendScene::onClick2()
{
    
}

void SendScene::load()
{
   
}


void SendScene::goBackScene()
{
    CCLog("MenuBarLayer::goBackScene() => %s","running");
    // TODO
    CCScene* scene = FarmScene::scene();
    CCTransitionMoveInL* tran = CCTransitionMoveInL::create(0.5, scene);
    CCDirector::sharedDirector()->pushScene(tran);
}

void SendScene::onHttpRequestCompleted(CCNode *sender, void *data)
{
    
}

void SendScene::editBoxEditingDidBegin(CCEditBox* editBox){}
void SendScene::editBoxEditingDidEnd(CCEditBox* editBox){}
void SendScene::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void SendScene::editBoxReturn(CCEditBox* editBox){
    inputText = editBox->getText();
}

