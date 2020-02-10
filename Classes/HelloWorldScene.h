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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"

class HelloWorld : public cocos2d::Scene, public sdkbox::SdkboxPlayListener
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


    virtual void onConnectionStatusChanged(int connection_status);
    virtual void onScoreSubmitted( const std::string& leaderboard_name, long score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday );
    virtual void onIncrementalAchievementUnlocked( const std::string& achievement_name );
    virtual void onIncrementalAchievementStep( const std::string& achievement_name, double step );
    virtual void onIncrementalAchievementStepError( const std::string& name, double steps, int error_code, const std::string& error_description );
    virtual void onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked );
    virtual void onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description );
    virtual void onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info );
    virtual void onSetSteps( const std::string& name, double steps );
    virtual void onSetStepsError( const std::string& name, double steps, int error_code, const std::string& error_description );
    virtual void onReveal( const std::string& name);
    virtual void onRevealError( const std::string& name, int error_code, const std::string& error_description );
    virtual void onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score );
    virtual void onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type, int error_code, const std::string& error_description);
    virtual void onPlayerCenteredScores( const std::string& leaderboard_name,
                                        int time_span,
                                        int collection_type,
                                        const std::string& json_with_score_entries ) ;
    virtual void onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                             int time_span,
                                             int collection_type,
                                             int error_code,
                                             const std::string& error_description);
    virtual void onPlayerScores(const std::string& leaderboard_name,
                                int time_span,
                                int collection_type,
                                const std::string& json_with_score_entries ) ;
    virtual void onPlayerScoresError(const std::string& leaderboard_name,
                                     int time_span,
                                     int collection_type,
                                     int error_code,
                                     const std::string& error_description);
    
    virtual void onGameData(const std::string& action, const std::string& name, const std::string& data, const std::string& error);
    virtual void onSaveGameData(bool success, const std::string& error);
    virtual void onLoadGameData(const sdkbox::SavedGameData* savedData, const std::string& error);
    virtual void onGameDataNames(const std::vector<std::string>& names, const std::string& error);

};

#endif // __HELLOWORLD_SCENE_H__
