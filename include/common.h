#pragma once
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define NUM_ROWS 2
#define NUM_COL 2

#define ENABLE_LOGGING 0
#define LOG(x) if(ENABLE_LOGGING) { std::cout  << std::endl << x << std::endl;}


enum Color 
{ 
	RED, 
	GREEN, 
	BLUE,
};