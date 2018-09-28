#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		LoadMap (map_file.child("map"));
		LoadTileset (map_file.child("map"));
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	LoadTileset(map);
	

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

bool j1Map::LoadMap(const pugi::xml_node& node)
{
	map_info newmap;
	newmap.tilewidth = node.attribute("tilewidth").as_uint();
	LOG("Tilewidth: %d", newmap.tilewidth);
	newmap.tileheight = node.attribute("tileheigth").as_uint();
	LOG("Tileheight: %d", newmap.tileheight);
	newmap.height = node.attribute("height").as_uint();
	LOG("Height: %d", newmap.width);
	newmap.width = node.attribute("widith").as_uint();
	LOG("Width: %d", newmap.width);
	p2SString orientation_string = node.attribute("orentation").as_string();
	if (orientation_string == "orthogonal")
	{
		newmap.orientation = map_orientation::orthogonal;
		LOG("orientation: %s", orientation_string);
	}
	p2SString renderorder_string = node.attribute("renderorder").as_string();
	if (renderorder_string == "right-down")
	{
		newmap.order = render_order::right_down;
		LOG("Render order: %s", renderorder_string);
	}
	return true;
}

bool j1Map::LoadTileset(const pugi::xml_node& node) {
	for (pugi::xml_node tileset = node.child("tileset"); tileset; tileset = tileset.next_sibling("tileset")) {
		tile_set newtileset;
		newtileset.tileimage = App->tex->Load(tileset.child("image").attribute("source").as_string());
		newtileset.gid1 = tileset.attribute("firstgid").as_int();
		newtileset.name = tileset.attribute("name").as_string();
		newtileset.tilewidth = tileset.attribute("tilewidth").as_int();
		newtileset.tileheight = tileset.attribute("tileheight").as_int();
		newtileset.spacing = tileset.attribute("spacing").as_int();
		newtileset.margin = tileset.attribute("margin").as_int();
		tile_list.push_back(newtileset);
	}
	return true;
}
