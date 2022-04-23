#pragma once
#include "Terrain_loading.h"

class Terreno{
				public:
	            static Terrain* loadTerrain(const char* filename, float height);
				static void cleanup();
				static void drawScene();
				static void ini();
};

