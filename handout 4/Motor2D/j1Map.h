#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct tile_set
{
	uint tilewidth = 0;
	uint tileheight = 0;
	uint spacing = 0;
	uint margin = 0;
	char* archivedirection = nullptr;
};

// TODO 1: Create a struct needed to hold the information to Map node

enum class render_order
{
	right_down,
	left_down,
	right_up,
	left_up,
	none
};

enum class map_orientation
{
	orthogonal,
	isometric,
	none
};

struct map_info
{
	map_orientation orientation = map_orientation::none;
	render_order order = render_order::none;
	uint tilewidth = 0;
	uint tileheight = 0;
	uint spacing = 0;
	uint margin = 0;

};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:
	

public:

	// TODO 1: Add your struct for map info as public for now

	map_info map1;
	tile_set info_tile;
	
private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__