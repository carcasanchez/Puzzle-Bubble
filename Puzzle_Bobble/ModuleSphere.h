#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Point.h"
#include "ModuleCollision.h"
#include "Vector.h"

#define MAX_ACTIVE_SPHERES 1000
#define NUMBER_OF_SPHERES 8

struct SDL_Texture;
struct ColliderRect;
enum COLLIDER_TYPE;

enum Color { BLUE, GREEN, GRAY, BLACK, RED, ORANGE, YELLOW, VIOLET };

struct Sphere
{
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint pos_board;
	fPoint speed;
	Uint32 born = 0;
	bool checked = false;

	bool fx_played = false;
	Collider* collider = nullptr;

	Color sphere_color;

	Sphere();
	Sphere(const Sphere& p);
	bool Update();
	void CheckBobble();
	int board_index;
};

class ModuleSphere : public Module
{
public:
	uint last_sphere = 0;
	bool next_sphere = true;
	Vector <Sphere*> allahu_list;

	ModuleSphere();
	~ModuleSphere();

	bool Start();
	update_status Update();
	bool CleanUp();

	void AddSphere(const Sphere& particle, int x, int y, COLLIDER_TYPE col_type= COLLIDER_SPHERE,  Uint32 delay = 0);
	void SetSphere(const Sphere& particle, int x, int y, int b_index, COLLIDER_TYPE col_type = COLLIDER_SPHERE, Uint32 delay = 0);



	SDL_Texture* graphics = nullptr;
	Sphere* active[MAX_ACTIVE_SPHERES];
	
	

public:

	Sphere spheres[NUMBER_OF_SPHERES];
	void OnCollision(Collider* c1, Collider* c2);
	bool LoseCondition = false;
};

#endif // __MODULEPARTICLES_H__