#pragma once

#include "raylib.h"
#include "raymath.h"

#include<stdlib.h>
#include<cstdlib>
#include <stdio.h>

#include <config.h>

#include <process.h>

#include<string>
#include<array>
#include<vector>
#include<cmath>
#include<memory>

#include<ctime>
#include<chrono>

#include<sstream>
#include<fstream>

#include<iostream>
#include<iomanip>
#include<thread>

#include <nlohmann/json.hpp>

#include"Level/dArr.h"
#include"Level/TextureManager.h"
#include"Level/GameAudio.h"


//other stuff needed to be shared with everthing
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;














