//
//  SUUnarchiver.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/16/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#ifndef SUUNARCHIVER_H
#define SUUNARCHIVER_H

typedef void (^SUUnarchiverCompletionBlock)(BOOL success);

@class SUHost;

@interface SUUnarchiver : NSObject {
	id delegate;
	NSString *archivePath;
	SUHost *updateHost;
}

@property (nonatomic, copy) SUUnarchiverCompletionBlock completionBlock;
@property (nonatomic) dispatch_queue_t completionCallbackQueue;

+ (SUUnarchiver *)unarchiverForPath:(NSString *)path updatingHost:(SUHost *)host;
- (void)setDelegate:delegate;

- (void)start;

@end

@interface NSObject (SUUnarchiverDelegate)
- (void)unarchiver:(SUUnarchiver *)unarchiver extractedLength:(unsigned long)length;
- (void)unarchiverDidFinish:(SUUnarchiver *)unarchiver;
- (void)unarchiverDidFail:(SUUnarchiver *)unarchiver;
@end

#endif
