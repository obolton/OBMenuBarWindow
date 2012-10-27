## About OBMenuBarWindow

The OBMenuBarWindow class is an NSWindow subclass that adds the ability to attach the window to an icon in the menu bar. It emulates much of the look and feel of NSPopover but retains the appearance and functionality of a regular window, including the title bar and traffic light controls. The user can drag the window to and from the menu bar icon to attach and detach it from the menu bar.

If the user resizes the window while it is attached to the menu bar, it will resize horizontally in a symmetrical manner around the center, to give a natural user experience.

It is possible to hide the “traffic light” controls when the window is attached to the menu bar, if desired.

**Notes:**

* OBMenuBarWindow does not use any private APIs, so it is Mac App Store compatible.
* OBMenuBarWindow uses ARC. If you are using OBMenuBarWindow in a non-ARC project, you will need to set a '-fobjc-arc' compiler flag on the OBMenuBarWindow source files.
* If you want an OBMenuBarWindow to be usable while another application is in full screen mode, create a new entry in your application’s .plist file for 'LSUIElement' and set its value to 'YES'. A side-effect of doing this is that the application’s dock icon will be hidden.
* OBMenuBarWindow does not support textured windows or standard toolbars.
* You can alter the height of the title bar and the dimensions of the arrow by changing the value of 'OBMenuBarWindowTitleBarHeight', 'OBMenuBarWindowArrowHeight' and 'OBMenuBarWindowArrowWidth' in OBMenuBarWindow.m.
* You can observe the 'OBMenuBarWindowDidAttachToMenuBar' and 'OBMenuBarWindowDidDetachFromMenuBar' notifications from the window object to be notified when the user attaches or detaches the window from the menu bar.

## Getting started

* Download OBMenuBarWindow and try out the example project.
* Copy OBMenuBarWindow.h and OBMenuBarWindow.m from the Classes directory and add them to your project.
* Set your window's class to OBMenuBarWindow.
* Set your window's icon using the menuBarIcon property, and set the hasMenuBarIcon property to YES.

## Documentation

Read the [Documentation](http://docs.oliverbolton.com/OBMenuBarWindow/Classes/OBMenuBarWindow.html).

## Credits

OBMenuBarWindow was created by [Oliver Bolton](http://oliverbolton.com/).

## License

OBMenuBarWindow is licensed under the Modified BSD License. See the LICENSE file for more information.