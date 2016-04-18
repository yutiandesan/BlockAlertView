//
//  UIAlertView_BlockAlertView.h
//  BlockAlertView
//
//  Created by bosheng on 16/4/18.
//  Copyright © 2016年 liuhuan. All rights reserved.
//

#if TARGET_IPHONE_SIMULATOR
#import <objc/objc-runtime.h>
#else
#import <objc/runtime.h>
#import <objc/message.h>
#endif

#import <UIKit/UIKit.h>

typedef void (^ blockAlertView)(UIAlertView * alertView,NSUInteger buttonIndex);

@interface UIAlertView ()<UIAlertViewDelegate>

@property (nonatomic,copy)blockAlertView aBlock;

- (void)alertBlock:(void(^)(UIAlertView *alertView,NSUInteger buttonIndex))aBlock;

@end

@implementation UIAlertView (BlockAlertView)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"
- (void)alertBlock:(void(^)(UIAlertView *alertView,NSUInteger buttonIndex))aBlock
{
    objc_setAssociatedObject(self, @selector(aBlock), aBlock, OBJC_ASSOCIATION_COPY_NONATOMIC);
    self.delegate = self;
}
#pragma clang diagnostic pop

- (void)setABlock:(blockAlertView)aBlock
{
    objc_setAssociatedObject(self, @selector(aBlock), aBlock, OBJC_ASSOCIATION_COPY_NONATOMIC);
    self.delegate = self;
}

- (blockAlertView)aBlock
{
    return objc_getAssociatedObject(self, @selector(aBlock));
}

#pragma mark - UIAlertViewDelegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (self.aBlock) {
        self.aBlock(alertView,buttonIndex);
    }
}

@end