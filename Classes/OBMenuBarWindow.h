//
//  OBMenuBarWindow.h
//
//  Copyright (c) 2012, Oliver Bolton (http://oliverbolton.com/)
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//      * Redistributions of source code must retain the above copyright
//        notice, this list of conditions and the following disclaimer.
//      * Redistributions in binary form must reproduce the above copyright
//        notice, this list of conditions and the following disclaimer in the
//        documentation and/or other materials provided with the distribution.
//      * Neither the name of the <organization> nor the
//        names of its contributors may be used to endorse or promote products
//        derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL OLIVER BOLTON BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
//  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
//  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <AppKit/AppKit.h>

// Notifications
extern NSString * const OBMenuBarWindowDidAttachToMenuBar;
extern NSString * const OBMenuBarWindowDidDetachFromMenuBar;

// Constants
extern const CGFloat OBMenuBarWindowTitleBarHeight;
extern const CGFloat OBMenuBarWindowArrowHeight;
extern const CGFloat OBMenuBarWindowArrowWidth;

@class OBMenuBarWindowIconView;

/** The `OBMenuBarWindow` class is an `NSWindow` subclass that adds the ability
 to attach the window to an icon in the menu bar. It emulates much of the look
 and feel of `NSPopover` but retains the appearance and functionality of a
 regular window, including the title bar and traffic light controls. The user
 can drag the window to and from the menu bar icon to attach and detach it from
 the menu bar.
 
 If the user resizes the window while it is attached to the menu bar, it will
 resize horizontally in a symmetrical manner around the center to give a natural
 user experience.
 
 It is possible to hide the "traffic light" controls when the window is attached
 to the menu bar, if desired.
 
 **Notes:**
 
 - OBMenuBarWindow does not use any private APIs, so it is Mac App Store
   compatible.
 - OBMenuBarWindow uses ARC. If you are using OBMenuBarWindow in a non-ARC
   project, you will need to set a `-fobjc-arc` compiler flag on the
   OBMenuBarWindow source files.
 - If you want an OBMenuBarWindow to be usable while another application is in
   full screen mode, create a new entry in your application's `.plist` file for
   `LSUIElement` and set its value to `YES`. A side-effect of doing this is that
   the application's dock icon will be hidden.
 - OBMenuBarWindow does not support textured windows or standard toolbars.
 - You can alter the height of the title bar and the dimensions of the arrow by
   changing the value of `OBMenuBarWindowTitleBarHeight`,
   `OBMenuBarWindowArrowHeight` and `OBMenuBarWindowArrowWidth` in
   `OBMenuBarWindow.m`.
 - You can observe the `OBMenuBarWindowDidAttachToMenuBar` and
   `OBMenuBarWindowDidDetachFromMenuBar` notifications from the window object to
   be notified when the user attaches or detaches the window from the menu bar.
 
 */
 
@interface OBMenuBarWindow : NSWindow
{
    BOOL isDragging;
    BOOL resizeRight;
    BOOL hideControls;
    NSPoint dragStartLocation;
    NSPoint resizeStartLocation;
    NSRect dragStartFrame;
    NSRect resizeStartFrame;
    NSTextField *titleTextField;
    NSImage *noiseImage;
    NSStatusItem *statusItem;
    OBMenuBarWindowIconView *statusItemView;
}

/** Whether the window has an associated icon in the menu bar (default is `NO`).
 If this is `YES`, set the `menuBarIcon` property and optionally the
 `highlightedMenuBar` property.*/
@property (nonatomic, assign) BOOL hasMenuBarIcon;

/** Whether the window is attached to its icon in the menu bar (default is
 `NO`). This property will only have an effect if the `hasMenuBarIcon` property
 is set to `YES`. */
@property (nonatomic, assign) BOOL attachedToMenuBar;

/** Whether to hide the "traffic light" window controls when the window is
 attached to the menu bar (default is `YES`). */
@property (nonatomic, assign) BOOL hideWindowControlsWhenAttached;

/** Whether window can be detached from the menu bar or not (default is YES) */
@property (nonatomic, assign) BOOL isDetachable;

/** The threshold distance between the centre of the title bar and the menu bar
 icon at which to "snap" the window to the menu bar when dragging (default is
 30.0 pixels). */
@property (assign) CGFloat snapDistance;

/** The icon to show in the menu bar. The image should have a maximum height of
 22 pixels (or 44 pixels for retina displays). */
@property (nonatomic, strong) NSImage *menuBarIcon;

/** The highlighted version of the icon to show in the menu bar. The dimensions
 of the image should match the non-highlighted image. */
@property (nonatomic, strong) NSImage *highlightedMenuBarIcon;

/** The status item associated with the window. */
@property (readonly) NSStatusItem *statusItem;

/** The view containing the window's toolbar items. You can access this view to
 add additional controls to the titlebar. */
@property (readonly) NSView *toolbarView;

/** The window's title text field. */
@property (readonly) NSTextField *titleTextField;

@end

/** The `OBStatusItemView` class handles drawing and interacting with the menu
 bar icon of an `OBMenuBarWindow`. */
@interface OBMenuBarWindowIconView : NSView

/** The window attached to the menu bar item. */
@property (assign) OBMenuBarWindow *menuBarWindow;

/** Whether the menu bar icon is highlighted. */
@property (nonatomic, assign) BOOL highlighted;

@end
