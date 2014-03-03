#include "FriendsListScene.h"
#include "all_in_one.h"
#include "FSAlertLayer.h"


CCScene * FriendsListScene::scene()
{
    CCScene * scene = CCScene::create();
    FriendsListScene * layer = FriendsListScene::create();
    scene->addChild(layer);
    // Add swipe layer
    CCLayer * swipelayer = SwipeLayer2::create();
    scene->addChild(swipelayer);
    
    return scene;
}

bool FriendsListScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(246,250,251,255)) )
    {
    }
    
    // Set background
    //Setter::setBackground_list(this);
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCSpriteBatchNode* node = CCSpriteBatchNode::create("bg.jpg");
    CCSize bgsize = node->getContentSize();
    this->addChild(node);
    int bgWidth = 390;
    int bgHeight = 390;
    int repeatX = visibleSize.width/bgWidth + 1;
    int repeatY = visibleSize.height/bgHeight + 1;
    CCSprite* spr[repeatX][repeatY];
    // Repeat a image
    for(int y=0; y<=repeatY; y++){
        for(int x=0; x<=repeatX; x++){
            spr[x][y] = CCSprite::create("bg.jpg");
            spr[x][y]->setPosition(ccp(bgWidth * x, bgHeight * y));
            node->addChild(spr[x][y]);
        }
    }
    
    // Background Image for menu bar
    CCScale9Sprite* scale9Sprite = CCScale9Sprite::create("frame_v.png");
    scale9Sprite->setContentSize(ccp(visibleSize.width,visibleSize.height/10));
    scale9Sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height - scale9Sprite->getContentSize().height/2));
    this->addChild(scale9Sprite,500);
    
    // Go back to privious scene
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(SendScene::goBackScene));
    menuBackItem->setPosition(ccp(menuBackItem->getContentSize().width/2, visibleSize.height - menuBackItem->getContentSize().height/2));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack,501);
    
    // Send a message
    CCMenuItemImage* sendItemImg = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(SendScene::goBackScene));
    sendItemImg->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    CCMenu* menuSend = CCMenu::create(sendItemImg, NULL);
    menuSend->setPosition(CCPointZero);
    this->addChild(menuSend,501);
    
    // number of cells
    numberOfCells = 0;

    this->main();
    
    return true;
}

void FriendsListScene::main()
{
    CCLog("FriendsListScene::main ======> %s", "");
    this->load();
}

void FriendsListScene::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    int idx = cell->getIdx();
    currentCellIndex = idx;
    CCLOG("cell touched at idx: %i", idx);
    if (idx >= 0)
    {
        CCNotificationCenter::sharedNotificationCenter()->postNotification("cell0", NULL);
    }
    const char * text = name[idx].c_str();
    CCString* message = CCString::create("");
    message->initWithFormat("Remove?  %s",text);
    
    // call from Scene, Layer, etc
    FSAlertLayer *alertLayer = FSAlertLayer::create(message->getCString(), this, callfuncN_selector(FriendsListScene::menuOKCallback), callfuncN_selector(FriendsListScene::menuNGCallback));
    this->addChild(alertLayer, 100001);
    
 
}

CCSize FriendsListScene::cellSizeForTable(CCTableView* table)
{
    return MyTableViewCell::cellSize();
}

CCTableViewCell* FriendsListScene::tableCellAtIndex(CCTableView* table, unsigned int idx)
{

    MyTableViewCell* cell = (MyTableViewCell*)table->dequeueCell();
    if(!cell)
    {
        cell = MyTableViewCell::create();
    }
    
    // Content
    CCString* text = CCString::createWithFormat("%d", idx + 1);
    const char * content_name = name[idx].c_str();
    CCString* detail = CCString::createWithFormat("%s", content_name);
    cell->setTextString(text->getCString());
    cell->setDetailString(detail->getCString());
   
    string strMonster0 = "img_b.png";
    CCString* path = CCString::create(strMonster0);
    cell->setImagePath(path->getCString());
    
    return cell;
    return 0;
}


unsigned int FriendsListScene::numberOfCellsInTableView(CCTableView* table)
{
    return numberOfCells;
}

void FriendsListScene::menuOKCallback()
{
    CCLog("FriendsListScene::removeFriend ======> %s", "");
    // Set parameters
    string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
    
    // Set Key and Value
    int numberOfPair = 10;
    pair <const char *, const char *> * pairs;
    pairs = new pair <const char *, const char *> [numberOfPair];
    int num = 0;
    const char* friend_id = id[currentCellIndex].c_str();
    pairs[num++] = make_pair("uuid", uuid);
    pairs[num++] = make_pair("friend_id",friend_id);
    pairs[num++] = make_pair("food","meat");
    pairs[num++] = make_pair("a","test1_value");
    pairs[num++] = make_pair("b","test2_value");
    pairs[num++] = make_pair("c","test3_value");
    pairs[num++] = make_pair("d","test4_value");
    pairs[num++] = make_pair("e","test5_value");
    pairs[num++] = make_pair("f","test6_value");
    
    // Array Initialization
    int count_char = 0;
    
    // Calculate Memory Size
    for (int cnt = 0; cnt < num; cnt++)
    {
        count_char += strlen(pairs[cnt].first);
        count_char += strlen(pairs[cnt].second);
    }
    int jsonDataSize = count_char + 6*numberOfPair + 2 + 100;
    
    // Allocate memory
    char * jsonData;
    jsonData = new char [jsonDataSize];
    
    // NULL-terminated character sequence
    *jsonData = '\0';
    
    // Set jsonData
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pairs);
    jsonGenerator->DisposeObject();
    
    // Create Json Object
    const char * postData = jsonData;
    CCLog("Debug jsonGenerator : %s", postData);
    
    // HTTP Client
    vector<string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    CCHttpRequest* request = new CCHttpRequest();
    request->setUrl("http://49.212.139.75:9000/removeFriend");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(FriendsListScene::onHttpRequestEmpty));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pairs;
    delete[] jsonData;
    
    // TODO reload scene
    CCDirector::sharedDirector()->replaceScene( FriendsListScene::scene());
}

void FriendsListScene::menuNGCallback()
{
    
}

void FriendsListScene::load()
{
    
    CCLog("FriendsListScene::load ======> %s", "");
    // Set parameters
    string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
    
    // Set Key and Value
    int numberOfPair = 10;
    pair <const char *, const char *> * pairs;
    pairs = new pair <const char *, const char *> [numberOfPair];
    int num = 0;
    pairs[num++] = make_pair("uuid", uuid);
    pairs[num++] = make_pair("message","Hello, I am pikaho");
    pairs[num++] = make_pair("food","meat");
    pairs[num++] = make_pair("a","test1_value");
    pairs[num++] = make_pair("b","test2_value");
    pairs[num++] = make_pair("c","test3_value");
    pairs[num++] = make_pair("d","test4_value");
    pairs[num++] = make_pair("e","test5_value");
    pairs[num++] = make_pair("f","test6_value");
    
    // Array Initialization
    int count_char = 0;
    
    // Calculate Memory Size
    for (int cnt = 0; cnt < num; cnt++)
    {
        count_char += strlen(pairs[cnt].first);
        count_char += strlen(pairs[cnt].second);
    }
    int jsonDataSize = count_char + 6*numberOfPair + 2 + 100;
    
    // Allocate memory
    char * jsonData;
    jsonData = new char [jsonDataSize];
    
    // NULL-terminated character sequence
    *jsonData = '\0';
    
    // Set jsonData
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pairs);
    jsonGenerator->DisposeObject();
    
    // Create Json Object
    const char * postData = jsonData;
    CCLog("Debug jsonGenerator : %s", postData);
    
    // HTTP Client
    vector<string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    CCHttpRequest* request = new CCHttpRequest();
    request->setUrl("http://49.212.139.75:9000/loadFriendsListScene");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(FriendsListScene::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pairs;
    delete[] jsonData;
    
}

void FriendsListScene::onHttpRequestEmpty(CCNode *sender, void *data){
    
}

void FriendsListScene::onHttpRequestCompleted(CCNode *sender, void *data)
{
    
    CCLog("FriendsListScene::onHttpRequestCompleted ======> %s", "");
    CCHttpResponse *response = (CCHttpResponse*)data;
    
    if (!response)
    {
        return;
    }
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s completed", response->getHttpRequest()->getTag());
    }
    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("response code: %d", statusCode);
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // store data
    vector<char> * buffer = response->getResponseData();
    char * concatenated = (char *) malloc(buffer->size() + 1);
    string s2(buffer->begin(), buffer->end());
    strcpy(concatenated, s2.c_str());
    CCLog("=====> JSON =====> : %s",concatenated);
    
    // JSON Parser
    string picoError;
    picojson::value picoValue;
    picojson::parse(picoValue,concatenated,concatenated+strlen(concatenated),&picoError);
    string friends_count;
    if(picoError.empty()) {
        picojson::object& o = picoValue.get<picojson::object>();
        friends_count = o["friends_count"].get<string>();
        string& info = o["info"].get<string>();
        picojson::array& picoArray = o["friends"].get<picojson::array>();
        int picoArraySize = picoArray.size();
        id = new string[picoArraySize];
        name = new string[picoArraySize];
        monster_id = new string[picoArraySize];
        int cnt = 0;
        for(picojson::array::iterator i = picoArray.begin(); i != picoArray.end(); i++){
            picojson::object& friendObject = i->get<picojson::object>();
            id[cnt] = friendObject["id"].get<string>();
            name[cnt] = friendObject["name"].get<string>();
            monster_id[cnt] = friendObject["monster_id"].get<string>();
            CCLog("pico id : %s", id[cnt].c_str());
            CCLog("pico name : %s", name[cnt].c_str());
            CCLog("pico monster_id : %s", monster_id[cnt].c_str());
            cnt++;
        }
       
        // Set number of cells in the TableView
        numberOfCells = cnt;
    }
    
    // Exception
    if(numberOfCells < 0){ numberOfCells = 0; };
    
    //CCTableView
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCTableView * tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height/10 *9));
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setPosition(ccp(origin.x, origin.y));
    tableView->setDelegate(this);
    addChild(tableView,1);
    tableView->reloadData();
   
}