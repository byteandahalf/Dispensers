#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"

#include "DispenserBlock.h"

DispenserBlock::DispenserBlock(int blockId):
	DispenseableBlock("dispenser", blockId) {

	face = getTextureUVCoordinateSet("dispenser_face", 0);
}

DispenseableBlock::DispenseType DispenserBlock::getDispenseType(const ItemInstance& itemStack) {
	switch(itemStack.item)
	{
	case Item::mArrow: case Item::mSnowBall: case Item::mEgg: case Item::mExperiencePotionItem:
		return DispenseableBlock::DispenseType::PROJECTILE;

	// TODO: Armor
	
	case Item::mBucket:
	{
		if(itemStack.aux == 0)
			return DispenseableBlock::DispenseType::USEITEM;

		return DispenseableBlock::DispenseType::PLACEBLOCK;
	}

	case Item::mFlintAndSteel:
		return DispenseableBlock::DispenseType::USEITEM;

	case Item::mBoat: case Item::mMinecart: case Item::mMobPlacer:
		return DispenseableBlock::DispenseType::PLACEENTITY;
	}

	switch(itemStack.block)
	{
	case Block::mTNT:
		return DispenseableBlock::DispenseType::PLACEENTITY;
	}

	return DispenseableBlock::DispenseType::DROP;
}