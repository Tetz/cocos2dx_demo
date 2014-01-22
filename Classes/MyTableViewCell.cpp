#include "MyTableViewCell.h"
#include "cocos-ext.h"

using namespace std;
USING_NS_CC_EXT;
USING_NS_CC;

const float kMyTableViewCellHeight = 130.f;

MyTableViewCell::MyTableViewCell() : m_textLabel(NULL), m_detailLabel(NULL), m_imageSprite(NULL)
{
    
}

MyTableViewCell::~MyTableViewCell()
{
    removeChild(m_textLabel);
    removeChild(m_detailLabel);
    removeChild(m_imageSprite);
    CC_SAFE_RELEASE(m_textLabel);
    CC_SAFE_RELEASE(m_detailLabel);
    CC_SAFE_RELEASE(m_imageSprite);
}

bool MyTableViewCell::init()
{
    // TODO
    setPosition(0,0);
    // Label
    CCSprite * image = CCSprite::create();
    CCLabelTTF * label = CCLabelTTF::create("", "Helvetica", 70);
    CCLabelTTF * detail = CCLabelTTF::create("", "Helvetica", 50);
    label->setColor(ccc3(70,70,70));
    detail->setColor(ccc3(70,70,70));
    return this->initWithLabel(label, detail, image);
}

bool MyTableViewCell::initWithLabel(CCLabelTTF* textLabel, CCLabelTTF* detailLabel, CCSprite* imageSprite)
{
    if (!CCTableViewCell::init())
    {
        return false;
    }
    this->setimageSprite(imageSprite);
    this->setTextLabel(textLabel);
    this->setDetailLabel(detailLabel);
    this->addChild(imageSprite);
    this->addChild(textLabel);
    this->addChild(detailLabel);
    needsLayout();
    return true;
}

MyTableViewCell* MyTableViewCell::create(CCLabelTTF* textLabel, CCLabelTTF* detailLabel, CCSprite* imageSprite)
{
    MyTableViewCell* pRet = new MyTableViewCell();
    if (pRet && pRet->initWithLabel(textLabel, detailLabel, imageSprite))
    {
        pRet->autorelease();
    }else{
        CC_SAFE_RELEASE(pRet);
    }
    return pRet;
}

MyTableViewCell* MyTableViewCell::create(const char* text, const char* fontName, float fontSize, const char* detailText, float detailFontSize, const char* imagePath)
{
    CCLabelTTF* label = CCLabelTTF::create(text, fontName, fontSize);
    CCLabelTTF* detail = CCLabelTTF::create(detailText, fontName, detailFontSize);
    CCSprite* image;
    if (imagePath)
    {
        image = CCSprite::create(imagePath);
    }
    else
    {
        image = CCSprite::create();
    }
    return create(label, detail, image);
}

CCSize MyTableViewCell::cellSize()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    return CCSizeMake(visibleSize.width, kMyTableViewCellHeight);
}

void MyTableViewCell::needsLayout()
{
    float x = 0.f, y = 0.f;
    CCSize size = MyTableViewCell::cellSize();
    
    // Image
    CCSize imageSize = m_imageSprite->getContentSize();
    y = (size.height-imageSize.height)/2;
    m_imageSprite->setPosition(ccp(size.width/20 * 1, y));
    m_imageSprite->setAnchorPoint(CCPointZero);
    x += imageSize.width;
    
    // Text
    CCSize textSize = m_textLabel->getContentSize();
    y = (size.height-textSize.height)/2;
    m_textLabel->setAnchorPoint(CCPointZero);
    m_textLabel->setPosition(ccp(size.width/20 * 3, y));
    
    x += MAX(size.width/2, x+textSize.width);
    CCSize detailSize = m_detailLabel->getContentSize();
    y = (size.height-detailSize.height)/2;
    m_detailLabel->setAnchorPoint(CCPointZero);
    m_detailLabel->setPosition(ccp(size.width/20 * 6, y));
    
}

void MyTableViewCell::setTextString(const char* var)
{
    m_textLabel->setString(var);
    needsLayout();
}

const char* MyTableViewCell::getTextString()
{
    return m_textLabel->getString();
}

void MyTableViewCell::setDetailString(const char* var)
{
    m_detailLabel->setString(var);
    needsLayout();
}

const char* MyTableViewCell::getDetailString()
{
    return m_detailLabel->getString();
}

void MyTableViewCell::setImagePath(const char* path)
{
    CCTexture2D* tex = CCTextureCache::sharedTextureCache()->addImage(path);
    m_imageSprite->setTexture(tex);
    CCSize contentSize = tex->getContentSize();
    m_imageSprite->setTextureRect(CCRectMake(0, 0, contentSize.width, contentSize.height));
    needsLayout();
}

void MyTableViewCell::draw()
{
//    CCPoint pos = getPosition();
//    CCLog("in MyTableViewCell::draw x = %f", pos.x);
//    CCLog("in MyTableViewCell::draw y = %f", pos.y);
//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//    CCSize size = CCSizeMake(visibleSize.width, kMyTableViewCellHeight);
//    float fixdraw = 0;
//    CCPoint vertices[4]={
//        ccp(pos.x, pos.y+1 - fixdraw),
//        ccp(pos.x+size.width, pos.y+1 - fixdraw),
//        ccp(pos.x+size.width, pos.y+size.height-1 - fixdraw),
//        ccp(pos.x, pos.y+size.height-1 - fixdraw),
//    };
//    ccDrawColor4B(127, 140, 141, 255);
//    ccDrawPoly(vertices, 4, true);
}