//
//  SEBController.h
//  Safe Exam Browser
//
//  Created by Daniel R. Schneider on 18.04.11.
//  Copyright (c) 2010-2012 Daniel R. Schneider, ETH Zurich, 
//  Educational Development and Technology (LET), 
//  based on the original idea of Safe Exam Browser 
//  by Stefan Schneider, University of Giessen
//  Project concept: Thomas Piendl, Daniel R. Schneider, 
//  Dirk Bauer, Karsten Burger, Marco Lehre, 
//  Brigitte Schmucki, Oliver Rahs. French localization: Nicolas Dunand
//
//  ``The contents of this file are subject to the Mozilla Public License
//  Version 1.1 (the "License"); you may not use this file except in
//  compliance with the License. You may obtain a copy of the License at
//  http://www.mozilla.org/MPL/
//  
//  Software distributed under the License is distributed on an "AS IS"
//  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
//  License for the specific language governing rights and limitations
//  under the License.
//  
//  The Original Code is Safe Exam Browser for Mac OS X.
//  
//  The Initial Developer of the Original Code is Daniel R. Schneider.
//  Portions created by Daniel R. Schneider are Copyright 
//  (C) 2010-2012 Daniel R. Schneider, ETH Zurich, Educational Development
//  and Technology (LET), based on the original idea of Safe Exam Browser 
//  by Stefan Schneider, University of Giessen. All Rights Reserved.
//  
//  Contributor(s): ______________________________________.
//

// Preferences General Pane
// Settings for passwords to enter Preferences and quit SEB
// Buttons to quit and restart SEB, show About panel and help

#import <Cocoa/Cocoa.h>
#import "MBPreferencesController.h"
#import <CommonCrypto/CommonDigest.h>
#import "MyGlobals.h"


@interface PrefsGeneralViewController : NSViewController <MBPreferencesModule, NSWindowDelegate> {

	IBOutlet NSTextField *startURL;
	NSMutableString *adminPassword;
	NSMutableString *confirmAdminPassword;
    NSMutableString *quitPassword;
    NSMutableString *confirmQuitPassword;
	IBOutlet NSButton *prefsQuitSEB;
	IBOutlet NSButton *pasteSavedStringFromPasteboardButton;
    
	IBOutlet NSObjectController *controller;
	MyGlobals *myGlobals;
    NSError *error; 
}

- (NSString *)identifier;
- (NSImage *)image;

- (void) loadPrefs:(id)sender;
- (void) savePrefs:(id)sender;

- (IBAction) savePrefsToAppBundle:(id)sender;
- (IBAction) removePrefsFromAppBundle:(id)sender;

- (IBAction) pasteSavedStringFromPasteboard:(id)sender;

- (IBAction) restartSEB:(id)sender;
- (IBAction) quitSEB:(id)sender;
- (void) closePreferencesWindow:(id)sender;
- (IBAction) aboutSEB:(id)sender;
- (IBAction) showHelp:(id)sender;

- (NSData*) generateSHAHash:(NSString*)inputString;

@end