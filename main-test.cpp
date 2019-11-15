//
//  main.cpp
//  polygon-testing
//
//  Created by Ivan Yakovenko on 16/10/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <iostream>
#include "tests.h"


using namespace std;



int main(int argc, char * argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
