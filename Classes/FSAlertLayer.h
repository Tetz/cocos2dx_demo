#ifndef _FSAlertLayer_
#define _FSAlertLayer_

#include "cocos2d.h"
USING_NS_CC;

#define FSAlertLayerTagMenu     101
#define FSAlertLayerTagOK       102
#define FSAlertLayerTagNG       103
#define FSAlertLayerTagFrame    110


class FSAlertLayer : public CCLayerColor
{
public:
    static FSAlertLayer* create(const char* message, CCObject* target, SEL_CallFuncN okSelector, SEL_CallFuncN ngSelector);
    static FSAlertLayer* create(const char* message, CCObject* target, SEL_CallFuncN okSelector);
    
    virtual bool init();
    void setStyle(const char* message, CCObject* target, SEL_CallFuncN okSelector, SEL_CallFuncN ngSelector);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    void menuAlertOK(CCObject* pSender);
    void menuAlertClose(CCObject* pSender);
    
    CREATE_FUNC(FSAlertLayer);
    
private:
    CCObject* target;
    SEL_CallFuncN okSelector;
    SEL_CallFuncN ngSelector;
};

#endif /* defined(_FSAlertLayer_) */