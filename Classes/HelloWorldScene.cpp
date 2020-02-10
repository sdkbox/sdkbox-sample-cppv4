/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    // auto closeItem = MenuItemImage::create(
    //                                        "CloseNormal.png",
    //                                        "CloseSelected.png",
    //                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    // if (closeItem == nullptr ||
    //     closeItem->getContentSize().width <= 0 ||
    //     closeItem->getContentSize().height <= 0)
    // {
    //     problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    // }
    // else
    // {
    //     float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
    //     float y = origin.y + closeItem->getContentSize().height/2;
    //     closeItem->setPosition(Vec2(x,y));
    // }

    // create menu, it's an autorelease object
    // auto menu = Menu::create(closeItem, NULL);
    // menu->setPosition(Vec2::ZERO);
    // this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    Menu* menu = Menu::create(
        MenuItemFont::create("Connect", [](Ref*) { sdkbox::PluginSdkboxPlay::signin(); }),
        MenuItemFont::create("Disconnect", [](Ref*) { sdkbox::PluginSdkboxPlay::signout(); }),
        NULL
    );

    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    addChild(menu);

    // auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    // if (label == nullptr)
    // {
    //     problemLoading("'fonts/Marker Felt.ttf'");
    // }
    // else
    // {
    //     // position the label on the center of the screen
    //     label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                             origin.y + visibleSize.height - label->getContentSize().height));

    //     // add the label as a child to this layer
    //     this->addChild(label, 1);
    // }

    // // add "HelloWorld" splash screen"
    // auto sprite = Sprite::create("HelloWorld.png");
    // if (sprite == nullptr)
    // {
    //     problemLoading("'HelloWorld.png'");
    // }
    // else
    // {
    //     // position the sprite on the center of the screen
    //     sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //     // add the sprite as a child to this layer
    //     this->addChild(sprite, 0);
    // }

    sdkbox::PluginSdkboxPlay::setListener(this);
    sdkbox::PluginSdkboxPlay::init();

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}


void HelloWorld::onConnectionStatusChanged(int connection_status) {    
}

void HelloWorld::onScoreSubmitted( const std::string& leaderboard_name, long score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday ) {    
}

void HelloWorld::onIncrementalAchievementUnlocked( const std::string& achievement_name ) {    
}

void HelloWorld::onIncrementalAchievementStep( const std::string& achievement_name, double step ) {    
}

void HelloWorld::onIncrementalAchievementStepError( const std::string& name, double steps, int error_code, const std::string& error_description ) {    
}

void HelloWorld::onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked ) {    
}

void HelloWorld::onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description ) {    
}

void HelloWorld::onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info ) {    
}

void HelloWorld::onSetSteps( const std::string& name, double steps ) {    
}

void HelloWorld::onSetStepsError( const std::string& name, double steps, int error_code, const std::string& error_description ) {    
}

void HelloWorld::onReveal( const std::string& name) {    
}

void HelloWorld::onRevealError( const std::string& name, int error_code, const std::string& error_description ) {    
}

void HelloWorld::onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score ) {    
}

void HelloWorld::onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type, int error_code, const std::string& error_description) {    
}

void HelloWorld::onPlayerCenteredScores( const std::string& leaderboard_name,
                                    int time_span,
                                    int collection_type,
                                    const std::string& json_with_score_entries ) {
                                    }

void HelloWorld::onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                            int time_span,
                                            int collection_type,
                                            int error_code,
                                            const std::string& error_description) {                                                
                                            }

void HelloWorld::onPlayerScores(const std::string& leaderboard_name,
                            int time_span,
                            int collection_type,
                            const std::string& json_with_score_entries ) {
                            }

void HelloWorld::onPlayerScoresError(const std::string& leaderboard_name,
                                    int time_span,
                                    int collection_type,
                                    int error_code,
                                    const std::string& error_description) {                                        
                                    }


void HelloWorld::onGameData(const std::string& action, const std::string& name, const std::string& data, const std::string& error) {    
}

void HelloWorld::onSaveGameData(bool success, const std::string& error) {    
}

void HelloWorld::onLoadGameData(const sdkbox::SavedGameData* savedData, const std::string& error) {    
}

void HelloWorld::onGameDataNames(const std::vector<std::string>& names, const std::string& error) {    
}

