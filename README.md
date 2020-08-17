# react-native-demo-custom

## Getting started

This is a demo in Facebook Develop Circle Hanoi event.
Speaker: Anh Tuan Nguyen (anhtuank7c)
Date: March 03, 2018
Content: How to write your own custom native module for React Native
Example and presentation: https://github.com/anhtuank7c/fbdevcirclehanoi2

### Mostly automatic installation

`$ react-native install react-native-demo-custom`

### Manual installation

#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-demo-custom` and add `RNCustom.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNCustom.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`

* Add `import vn.agiletech.democustommodule.RNCustomPackage;` to the imports at the top of the file
* Add `new RNCustomPackage()` to the list returned by the `getPackages()` method

2. Append the following lines to `android/settings.gradle`:
   ```
   include ':react-native-demo-custom'
   project(':react-native-demo-custom').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-demo-custom/android')
   ```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
   ```
     compile project(':react-native-demo-custom')
   ```

## Usage

```javascript
import { NativeEventEmitter } from 'react-native';
import RNCustom from 'react-native-demo-custom';

// passing simple callback function
RNCustom.hello('Agiletech', data => console.log('hello', data));

//passing complex data and callback function
RNCustom.personInfo(
  'Anh Tuan',
  'Nguyen',
  29,
  300.012,
  true,
  [1, 'two', 'three'],
  {
    key: 'Key',
    value: 'Value',
    latitude: 21.001382,
    longitude: 105.806933
  },
  data => console.log('personInfo', data)
);

// Promise function
RNCustom.pingPong(true)
  .then(data => console.log('pingPong resolved', data))
  .catch(error => console.log('pingPong rejected error', error));


componentDidMount() {
  const customModuleEmitter = new NativeEventEmitter(RNCustom);
  // Register event
	customModuleEmitter.addListener('addEvent', this.handleEventFire);
}

// do something when native fire JS method
handleEventFire = event => console.log('eventFired', event)
```
