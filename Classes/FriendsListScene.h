#ifndef _FRIENDSLIST_SCENE_H_
#define _FRIENDSLIST_SCENE_H_

#include "all_in_one.h"
#include "allScene.h"
#include "MyTableViewCell.h"

class FriendsListScene : public CCLayerColor, public CCTableViewDataSource, public CCTableViewDelegate
{
protected:
    
private:
    int numberOfCells;
public:
    virtual bool init();
    static CCScene * scene();
    CREATE_FUNC(FriendsListScene);
    virtual void main();
    // TableView
    virtual void scrollViewDidScroll(CCScrollView * view){}
    virtual void scrollViewDidZoom(CCScrollView * view){}
    virtual void tableCellTouched(CCTableView * table, CCTableViewCell * cell);
    virtual CCSize cellSizeForTable(CCTableView * table);
    virtual CCTableViewCell * tableCellAtIndex(CCTableView * table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView * table);
    
    // HTTP
    virtual void load();
    virtual void onHttpRequestCompleted(CCNode * sender, void * data);
    
};

#endif // _FRIENDSLIST_SCENE_H_