#ifndef _MainMenuBarLayer_
#define _MainMenuBarLayer_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "DefTags.h"
USING_NS_CC;
USING_NS_CC_EXT;

class MainMenuBarLayer : public CCLayer, public CCEditBoxDelegate
{
public:
    virtual bool init();
    void menuCloseCallback(CCObject* pSender);
    virtual void goBackScene();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    CREATE_FUNC(MainMenuBarLayer);
    
    // EditBox
    virtual void editBoxEditingDidBegin(CCEditBox* editBox);
    virtual void editBoxEditingDidEnd(CCEditBox* editBox);
    virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text);
    virtual void editBoxReturn(CCEditBox* editBox);
    const char* inputText;
};

#endif /* defined(_MainMenuBarLayer_) */
