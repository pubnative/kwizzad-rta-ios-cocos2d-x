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
USING_NS_UI;

cocos2d::ui::Button* HelloWorld::showRTAButton = NULL;
bool HelloWorld::isAdAvailable = false;

Scene *HelloWorld::createScene() {
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    this->initRTA();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    auto label = Label::createWithTTF("   Kwizzad RTA\nCocos2dx example", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr) {
        problemLoading("'fonts/Marker Felt.ttf'");
    } else {
        label->setPosition(Vec2(origin.x + visibleSize.width / 4,
                                origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr) {
        problemLoading("'HelloWorld.png'");
    } else {
        sprite->setPosition(
                Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(sprite, 0);
    }
    
    //add show rta button
    auto loadRTAButton = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
    loadRTAButton = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
    loadRTAButton->setTitleText("Load RTA");
    loadRTAButton->setTitleFontName("fonts/Marker Felt.ttf");
    loadRTAButton->setTitleFontSize(20.0f);
    loadRTAButton->setScale(0.5f);
    loadRTAButton->setPosition(Vec2(origin.x + 3 * visibleSize.width / 4,
                                      origin.y + visibleSize.height - loadRTAButton->getContentSize().height / 2));
    loadRTAButton->addTouchEventListener( CC_CALLBACK_2(HelloWorld::loadRtaClick, this) );
    this->addChild(loadRTAButton);

    //add show rta button
    showRTAButton = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
    showRTAButton->setTitleText("Show RTA");
    showRTAButton->setTitleFontName("fonts/Marker Felt.ttf");
    showRTAButton->setTitleFontSize(20.0f);
    showRTAButton->setScale(0.5f);
    showRTAButton->setPosition(Vec2(origin.x + 3 * visibleSize.width / 4,
                                      origin.y + visibleSize.height - 2 * showRTAButton->getContentSize().height / 2));
    showRTAButton->addTouchEventListener( CC_CALLBACK_2(HelloWorld::showRtaClick, this) );
    setShowRtaEnabled(isAdAvailable);
    this->addChild(showRTAButton);
    
    //add show debug button
    auto showDebugButton = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
    showDebugButton->setTitleText("Show Debug");
    showDebugButton->setTitleFontName("fonts/Marker Felt.ttf");
    showDebugButton->setTitleFontSize(20.0f);
    showDebugButton->setScale(0.5f);
    showDebugButton->setPosition(Vec2(origin.x + 3 * visibleSize.width / 4,
                                    origin.y + visibleSize.height - 3 * showDebugButton->getContentSize().height / 2));
    showDebugButton->addTouchEventListener( CC_CALLBACK_2(HelloWorld::showDebugClick, this) );

    this->addChild(showDebugButton);

    //add show debug button
    auto showConsentButton = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
    showConsentButton->setTitleText("Show Consent");
    showConsentButton->setTitleFontName("fonts/Marker Felt.ttf");
    showConsentButton->setTitleFontSize(20.0f);
    showConsentButton->setScale(0.5f);
    showConsentButton->setPosition(Vec2(origin.x + 2 * visibleSize.width / 4,
                                    origin.y + visibleSize.height - 3 * showConsentButton->getContentSize().height / 2));
    showConsentButton->addTouchEventListener( CC_CALLBACK_2(HelloWorld::showConsentClick, this) );

    this->addChild(showConsentButton);
    
    return true;
}

void HelloWorld::initRTA()
{
    initKwizzadRTA("rta_ios");
}

void HelloWorld::loadRtaClick(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType) {
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        loadwizzadRTA("test");
    }
}

void HelloWorld::showRtaClick(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType) {
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        showKwizzadRTA();
    }
}

void HelloWorld::showDebugClick(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType) {
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        showDebugScreen();
    }
}

void HelloWorld::showConsentClick(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType) {
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        showConsentScreen();
    }
}

void HelloWorld::menuCloseCallback(Ref *pSender) {
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void HelloWorld::setShowRtaEnabled(bool enabled) {
    isAdAvailable = enabled;
    if (showRTAButton != NULL) {
        HelloWorld::showRTAButton->setEnabled(enabled);
        HelloWorld::showRTAButton->setBright(enabled);
    }
}

