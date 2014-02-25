#include "SendScene.h"

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
    CCLayer * menuBar = MenuBarLayer::create();
    this->addChild(menuBar,6000);
    
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

void SendScene::onHttpRequestCompleted(CCNode *sender, void *data)
{
    
}

void SendScene::editBoxEditingDidBegin(CCEditBox* editBox){}
void SendScene::editBoxEditingDidEnd(CCEditBox* editBox){}
void SendScene::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void SendScene::editBoxReturn(CCEditBox* editBox){
    inputText = editBox->getText();
}

