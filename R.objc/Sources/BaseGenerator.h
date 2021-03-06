// Copyright 2016 Sysdata Digital
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>
#import "ResourceFinder.h"
#import "Placeholders.h"
#import "CommonUtils.h"
#import "GeneratedStructures.h"

#define END_CONTEXT @"@end\n\n"

@protocol GeneratorProtocol <NSObject>

- (NSString*) className;
- (NSString*) propertyName;
- (BOOL)generateResourceFileWithError:(NSError**)error;
- (NSString*)refactorizeFile:(NSString*)filename withContent:(NSString*)content withError:(NSError**)error;

@end

@interface BaseGenerator : NSObject <GeneratorProtocol>

@property (nonatomic, readonly) ResourceFinder *finder;
@property (nonatomic, strong) RClass *clazz;
@property (nonatomic, strong) NSMutableArray<RClass*>* otherClasses;


- (instancetype)initWithResourceFinder:(ResourceFinder*)finder;

- (NSString*)resourceFileHeaderPath;
- (NSString*)resourceFileImplementationPath;
- (NSString*)outputFileHeaderPath;
- (NSString*)outputFileImplementationPath;

- (BOOL)writeStringInRFilesWithError:(NSError *__autoreleasing *)error;
@end
