#ifndef _FRIENDSLIST_SCENE_H_
#define _FRIENDSLIST_SCENE_H_

#include "all_in_one.h"
#include "allScene.h"
#include "MyTableViewCell.h"

class FriendsListScene : public CCLayerColor, public CCTableViewDataSource, public CCTableViewDelegate
{
protected:
    
private:
    // Container of Cells
    int numberOfCells;
    int currentCellIndex;
    string* id;
    string* name;
    string* monster_id;
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
    virtual void onHttpRequestEmpty(CCNode * sender, void * data);
    
    // Dialog
    virtual void menuOKCallback();
    virtual void menuNGCallback();
    
    
    
};

#endif // _FRIENDSLIST_SCENE_H_