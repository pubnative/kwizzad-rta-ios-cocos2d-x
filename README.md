# kwizzad-rta-ios-cocos2d-x
public example app of rta sdk for iOS with Cocos2d-x

## Requirements
* XCode
* cocoapods

## How to build
* cd to proj.ios_mac
* run the below command to install KwizzadRTA and its dependencies via cocoapods.
```ruby
pod install
```
make sure to add $(inherited) to build settings, where mentionned in the log of pod install command.
* Fix incompatible Dependency
```ruby
sed -i '' 's/^module AATKit/framework module AATKit/' Pods/AATKit/aat/AATKit.framework/Versions/A/Modules/module.modulemap
```
* Now open xcworkspace file  and run the target RTACocos-mobile.
