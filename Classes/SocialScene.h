#ifndef _SOCIALSCENE_SCENE_H_
#define _SOCIALSCENE_SCENE_H_

#include "cocos2d.h"
#include "all_in_one.h"

class SocialScene : public cocos2d::CCLayerColor, public CCEditBoxDelegate
{
protected:
    
private:
    
public:
    virtual bool init();
    static CCScene * scene();
    CREATE_FUNC(SocialScene);
    virtual void main();
    
    // HTTP
    virtual void load();
    virtual void onHttpRequestCompleted(CCNode *sender, void *data);
    
    // button
    virtual void onClick1();
    virtual void onClick2();
    
    // EditBox
    virtual void editBoxEditingDidBegin(CCEditBox* editBox);
    virtual void editBoxEditingDidEnd(CCEditBox* editBox);
    virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text);
    virtual void editBoxReturn(CCEditBox* editBox);
    const char* inputText;


    
};

#endif // _SOCIALSCENE_SCENE_H_