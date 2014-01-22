#ifndef __MYTABLEVIEWCELL_H__
#define __MYTABLEVIEWCELL_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MyTableViewCell : public CCTableViewCell
{
protected:
    CC_SYNTHESIZE_RETAIN(CCLabelTTF*, m_textLabel, TextLabel);
    CC_SYNTHESIZE_RETAIN(CCLabelTTF*, m_detailLabel, DetailLabel);
    CC_SYNTHESIZE_RETAIN(CCSprite*, m_imageSprite, imageSprite);
    virtual void needsLayout();
    
public:
    MyTableViewCell();
    virtual ~MyTableViewCell();
    
    virtual bool init();
    virtual bool initWithLabel(CCLabelTTF* textLabel, CCLabelTTF* detailLabel, CCSprite* imageSprite);
    static MyTableViewCell* create(CCLabelTTF* textLabel, CCLabelTTF* detailLabel, CCSprite* imageSprite);
    static MyTableViewCell* create(const char* text, const char* fontName, float fontSize, const char* detail, float detailFontSize, const char* imagePath=NULL);
    CREATE_FUNC(MyTableViewCell);
    
    static CCSize cellSize();
    
    void setImagePath(const char* path);
    CC_PROPERTY(const char*, m_textString, TextString);
    CC_PROPERTY(const char*, m_detailString, DetailString);
    
    // draw
    virtual void draw();
};

#endif /* __MYTABLEVIEWCELL_H__ */
