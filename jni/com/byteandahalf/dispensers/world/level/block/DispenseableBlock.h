#pragma once
#include "com/mojang/minecraftpe/world/level/block/Block.h"

class DispenseableBlock : public Block
{
	enum DispenseType
	{
		DROP,
		PROJECTILE,
		PLACEBLOCK,
		EQUIP
	};

	TextureUVCoordinateSet side;
	TextureUVCoordinateSet top;

	bool dispenseAtLocation(DispenseableBlock::DispenseType, BlockSource&, const BlockPos&, const ItemInstance&);

public:
	DispenseableBlock(int);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual bool isRedstoneBlock() const;
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool);
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*);
	virtual bool use(Player&, const BlockPos&);
	virtual bool isContainerBlock() const;
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);

protected:
	TextureUVCoordinateSet face;

	virtual DispenseableBlock::DispenseType getDispenseType(const ItemInstance&) = 0;
};
