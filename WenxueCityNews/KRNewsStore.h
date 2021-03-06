//
//  KRNewsStore.h
//  WenxueCityNews
//
//  Created by Haihua Xiao on 13-3-13.
//  Copyright (c) 2013年 Haihua Xiao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreData/CoreData.h>

#define FETCH_INTERVAL 300 // 5 minutes
#define BASE_URL_PATTERN @"http://wenxuecity.cloudfoundry.com/news/mobilelist?from=%d&to=%d&max=%d&appKey=H5T7GDF9KJS"
#define BASE_URL @"http://wenxuecity.cloudfoundry.com/"

@class KRNews;

@interface KRNewsStore : NSObject
{
    NSMutableArray *allItems;
    NSMutableDictionary *keyedItems;
    NSManagedObjectContext *context;
    NSManagedObjectModel *model;
    BOOL loading;
    NSTimeInterval dateFetched;    
}

+ (KRNewsStore *)sharedStore;

- (void)removeItem:(KRNews *)news;

- (NSArray *)allItems;

- (void)addItem:(KRNews *)news;

- (NSString *)itemArchivePath;

- (void)saveItems:(int)itemCount;

- (void)loadAllItems;

- (int) unread;

- (int) total;

- (int) maxNewsId;

- (int) minNewsId;

- (BOOL) loading;

- (KRNews *)nextItem:(NSInteger)newsId;

- (KRNews *)prevItem:(NSInteger)newsId;

- (KRNews *)itemAt:(NSInteger)index;

- (void) loadNews: (int)from to:(int)to max:(int)max appendToTop:(BOOL)appendToTop force:(BOOL)force withHandler:(void (^)(NSArray *newsArray, NSError *error))handler;

@end
