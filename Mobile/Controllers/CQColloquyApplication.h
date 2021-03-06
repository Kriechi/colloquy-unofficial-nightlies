@protocol CQBrowserViewControllerDelegate;

extern NSString *CQColloquyApplicationDidRecieveDeviceTokenNotification;

@interface CQColloquyApplication : UIApplication <UIApplicationDelegate, UISplitViewControllerDelegate, UIAlertViewDelegate> {
	@protected
	UIWindow *_mainWindow;
	UIViewController *_mainViewController;
	UIPopoverController *_colloquiesPopoverController;
	UIBarButtonItem *_colloquiesBarButtonItem;
	UIToolbar *_toolbar;
	NSDate *_launchDate;
	NSDate *_resumeDate;
	NSString *_deviceToken;
	NSUInteger _networkIndicatorStack;
	UIActionSheet *_visibleActionSheet;
	NSNumber *_oldSwipeOrientationValue;
	BOOL _userDefaultsChanged;
	UIAlertController *_alertController;
}

+ (CQColloquyApplication *) sharedApplication;

- (void) showHelp:(id) sender;
- (void) showWelcome:(id) sender;
- (void) showConnections:(id) sender;
- (void) showColloquies:(id) sender;
- (void) showColloquies:(id) sender hidingTopViewController:(BOOL) hidingTopViewController;

- (void) dismissPopoversAnimated:(BOOL) animated;

- (BOOL) isSpecialApplicationURL:(NSURL *) url;
- (NSString *) applicationNameForURL:(NSURL *) url;

- (void) showActionSheet:(UIActionSheet *) sheet;
- (void) showActionSheet:(UIActionSheet *) sheet fromPoint:(CGPoint) point;
- (void) showActionSheet:(UIActionSheet *) sheet forSender:(id) sender animated:(BOOL) animated;

@property (nonatomic, readonly) UIViewController *mainViewController;
@property (nonatomic, readonly) UIViewController *modalViewController;

- (void) presentModalViewController:(UIViewController *) modalViewController animated:(BOOL) animated;
- (void) presentModalViewController:(UIViewController *) modalViewController animated:(BOOL) animated singly:(BOOL) singly;
- (void) dismissModalViewControllerAnimated:(BOOL) animated;

@property (readonly) BOOL areNotificationBadgesAllowed;
@property (readonly) BOOL areNotificationSoundsAllowed;
@property (readonly) BOOL areNotificationAlertsAllowed;

- (void) registerForPushNotifications;

@property (nonatomic, readonly) NSDate *launchDate;
@property (nonatomic, strong) NSDate *resumeDate;

- (void) submitRunTime;

@property (nonatomic, readonly) NSSet *handledURLSchemes;
@property (nonatomic, readonly) NSString *deviceToken;
@property (nonatomic, readonly) NSArray *highlightWords;
@property (nonatomic, readonly) UIColor *tintColor;

@property (readonly, strong) UISplitViewController *splitViewController;
@end
