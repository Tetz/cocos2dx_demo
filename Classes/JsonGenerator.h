//
//  JsonGenerator.h
//  MessagePlus
//
//  Created by ted on 1/1/14.
//
//

#ifndef _JsonGenerator_
#define _JsonGenerator_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class JsonGenerator : public cocos2d::CCLayerColor
{
public:
    // JSON Generator
    virtual void generate(int, char*, std::pair<const char*, const char*>[]);
    
    // Destructor
    void DisposeObject()
    {
        delete this;
    }

};


#endif /* defined(_JsonGenerator_) */
