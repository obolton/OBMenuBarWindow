## OBMenuBarWindow

`OBMenuBarWindow` is an [NSWindow](https://developer.apple.com/library/mac/#documentation/Cocoa/Reference/ApplicationKit/Classes/NSWindow_Class/Reference/Reference.html) subclass that adds the ability to attach the window to an icon in the menu bar in OS X. It emulates much of the look and feel of [NSPopover](http://developer.apple.com/library/mac/#documentation/AppKit/Reference/NSPopover_Class/Reference/Reference.html) but retains the appearance and functionality of a regular window, including the title bar and traffic light controls. The user can drag the window to and from the menu bar icon to attach and detach it from the menu bar.

![Screenshot 1](http://docs.oliverbolton.com/OBMenuBarWindow/screenshot1.png)
![Screenshot 2](http://docs.oliverbolton.com/OBMenuBarWindow/screenshot2.png)

**Notes:**

* OBMenuBarWindow is compatible with OS X 10.7+.
* It does not use any private APIs, so it is Mac App Store compatible.
* If you want the window to be usable while another application is in full-screen mode, create a new entry in your application’s `Info.plist` file for `LSUIElement` of Boolean type and set its value to `YES`. A side-effect of doing this is that the application’s dock icon will be hidden.
* OBMenuBarWindow does not support textured windows or standard toolbars.
* You can hide the "traffic light" controls when the window is attached to the menu bar, if desired (see **Window properties** below).
* You can control the height of the title bar and the arrow size (see **Window properties** below).
* You can observe the `OBMenuBarWindowDidAttachToMenuBar` and `OBMenuBarWindowDidDetachFromMenuBar` notifications from the window object to be notified when the user attaches or detaches the window from the menu bar.
* If the user resizes the window while it is attached to the menu bar, it will resize horizontally in a symmetrical manner around the center to give a natural user experience.

## Getting started

### Installation with CocoaPods

[CocoaPods](http://cocoapods.org/) is a dependency manager for Objective-C projects.

`pod "OBMenuBarWindow"`

### Manual installation

* Download the source and add `OBMenuBarWindow.h` and `OBMenuBarWindow.m` to your project.

### Using OBMenuBarWindow

* Set your window's class to `OBMenuBarWindow`.
* Set your window's icon using the `menuBarIcon` property.
* Set the `hasMenuBarIcon` property to `YES`.

## Window properties

**Menu bar icon**

- `hasMenuBarIcon` - whether the window has a menu bar icon (`BOOL`, default is `NO`).
- `menuBarIcon` - the menu bar icon image (`NSImage`).
- `highlightedMenuBarIcon` - the highlighted version of the menu bar icon (`NSImage`).
- `statusItem` - the status item associated with the window (`NSStatusItem`).

**Attaching to the menu bar**

- `attachedToMenuBar` - whether the window is attached to the menu bar (`BOOL`, default is `NO`).
- `isDetachable` - whether the window can be detached from the menu bar (`BOOL`, default is `YES`).
- `hideWindowControlsWhenAttached` - whether to hide the window "traffic lights" when it is attached to the menu bar (`BOOL`, default is `YES`).
- `snapDistance` - the threshold distance between the centre of the title bar and the menu bar icon at which to "snap" the window to the menu bar when dragging (`CGFloat`, default is 30 pixels).
- `distanceFromMenuBar` - the distance between the window and the menu bar when the window is attached (`CGFloat`, default is 0 pixels).
- `arrowSize` - the size of the arrow that points to the menu bar icon (`NSSize`, default is `{20, 10}`).

**Title bar**

- `titleBarHeight` - the height of the title bar (`CGFloat`, default is 22 pixels).
- `titleTextField` - the window title text field (`NSTextField`).
- `toolbarView` - the view containing the window's toolbar items (`NSView`).

## Documentation

Read the [Documentation](http://docs.oliverbolton.com/OBMenuBarWindow/Classes/OBMenuBarWindow.html).

## Credits

OBMenuBarWindow was created by Oliver Bolton.

## License

OBMenuBarWindow is licensed under the Modified BSD License. See the `LICENSE` file for more information.
