//
//  Setter.cpp
//  MessagePlus
//
//  Created by ted on 1/8/14.
//
//

#include "Setter.h"

void Setter::setBackground(cocos2d::CCLayerColor * context)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCSprite* background = CCSprite::create("normalGrass.png");
    background->setPosition(CCPoint(visibleSize.width/2, visibleSize.height/2));
    float scaleWidth = visibleSize.width/background->getContentSize().width;
    float scaleHeight = visibleSize.height/background->getContentSize().height;
    background->setScaleY(scaleHeight);
    background->setScaleX(scaleWidth);
    context->addChild(background, 0);
}