//
//  JsonGenerator.cpp
//  MessagePlus
//
//  Created by ted on 1/1/14.
//
//

#include "JsonGenerator.h"

// JSON Generator
void JsonGenerator::generate(int numberOfPair, char json[], std::pair<const char*, const char*> pair[])
{
    int max = numberOfPair;
    
    strcat(json, "{");
    for (int cnt = 0; cnt < max; cnt++)
    {
        strcat(json, "\"");
        strcat(json, pair[cnt].first);
        strcat(json, "\":\"");
        strcat(json, pair[cnt].second);
        strcat(json, "\"");
        if(cnt != max-1){
            strcat(json, ",");
        }
    }
    strcat(json, "}");
}