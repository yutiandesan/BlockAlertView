# BlockAlertView

Add a block for UIAlertView.

For example:
UIAlertView * alertView = [[UIAlertView alloc]initWithTitle:@"Title" message:@"This is message!" delegate:nil cancelButtonTitle:@"Cancel" otherButtonTitles:@"Yes", nil];

[alertView show];

[alertView alertBlock:^(UIAlertView *alertView, NSUInteger buttonIndex) {

   NSLog(@"======%u",buttonIndex);
   
}];
