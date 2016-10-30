/*
 * entity.h
 *
 *  Created on: Oct 6, 2016
 *      Author: nullifiedcat
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "logging.h"

class IClientEntity;

// TODO globals
typedef unsigned int offset_t;

template<typename T>
inline T GetEntityValue(IClientEntity* ent, unsigned int offset) {
	int null = 0;
	if (ent == 0) return *(reinterpret_cast<T*>(&null));
	//logging::Info("GetEntityValue 0x%08x, 0x%08x", ent, offset);
	return *(reinterpret_cast<T*>((unsigned int)ent + offset));
}

template<typename T>
void SetEntityValue(IClientEntity* ent, unsigned int offset, T value) {
	*(reinterpret_cast<T*>((unsigned int)ent + offset)) = value;
}

void InitEntityOffsets();

class EntityVariables {
public:
	void Init();
	offset_t iTeamNum;
	offset_t iFlags;
	offset_t iHealth;
	offset_t iLifeState;
	offset_t iCond;
	offset_t iCond1;
	offset_t iCond2;
	offset_t iCond3;
	offset_t iClass;
	offset_t vViewOffset;
	offset_t hActiveWeapon;
	offset_t flChargedDamage;
	offset_t iUpgradeLevel;
	offset_t iPipeType;
	offset_t iBuildingHealth;
	offset_t iHitboxSet;
	offset_t vVelocity;
	offset_t bGlowEnabled;
	offset_t iGlowIndex;
};

// TODO globals
extern EntityVariables eoffsets;

#endif /* ENTITY_H_ */
