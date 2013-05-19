//
//  ViewController.m
//  iPollux
//
//  Created by Guillaume Legrain on 13/3/13.
//  Copyright (c) 2013 Guillaume Legrain. All rights reserved.
//

#import "ViewController.h"
#include "crypt.h"
#include "decrypt.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextView *clearTextField;
- (IBAction)crypt:(id)sender;
- (IBAction)decrypt:(id)sender;
@property (weak, nonatomic) IBOutlet UITextView *polluTextField;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.clearTextField setReturnKeyType:UIReturnKeyDone];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)crypt:(id)sender {
    
    self.clearText = self.clearTextField.text;
    char *textString = (char *) [self.clearText UTF8String];
    
    NSString *polluxText = [[NSString alloc] initWithFormat:@"%s",pollux_encode(textString,11,14,1,1)];
    NSLog(@"%@\n",polluxText);
    self.polluTextField.text = polluxText;
}

- (IBAction)decrypt:(id)sender {
   self.clearText = self.clearTextField.text;
    char *textString = (char *) [self.clearText UTF8String];
    
    
    NSString *polluxText = [[NSString alloc] initWithFormat:@"%s",morse_decode(textString)];
    NSLog(@"%@\n",polluxText);
    self.polluTextField.text = polluxText;
}

//Method to hide keyboard on line return input 
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text {
    if ( [text isEqualToString:@"\n"] ) {
        [textView resignFirstResponder];
    }
    return YES;
    
}

//- (BOOL)textViewShouldEndEditing:(UITextView *)theTextView {
//     NSLog(@"OK1\n");
//    if (theTextView == self.clearTextField){
//          NSLog(@"OK2\n");
//        [theTextView resignFirstResponder];
//    }
//    return YES;
//}
@end
