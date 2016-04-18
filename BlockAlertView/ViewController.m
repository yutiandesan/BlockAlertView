//
//  ViewController.m
//  BlockAlertView
//
//  Created by bosheng on 16/4/18.
//  Copyright © 2016年 liuhuan. All rights reserved.
//

#import "ViewController.h"
#import "UIAlertView+/UIAlertView_BlockAlertView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIAlertView * alertView = [[UIAlertView alloc]initWithTitle:@"Title" message:@"This is message!" delegate:nil cancelButtonTitle:@"Cancel" otherButtonTitles:@"Yes", nil];
    [alertView show];
    [alertView alertBlock:^(UIAlertView *alertView, NSUInteger buttonIndex) {
        NSLog(@"======%u",buttonIndex);
    }];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
