#include "com/mojang/minecraftpe/world/material/Material.h"
#include "com/mojang/minecraftpe/world/level/BlockSource.h"
#include "com/mojang/minecraftpe/world/level/BlockPos.h"
#include "com/mojang/minecraftpe/world/entity/Player.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

#include "DispenseableBlock.h"

DispenseableBlock::DispenseableBlock(int blockId):
	Block(name, blockId, Material::getMaterial(MaterialType::STONE)) {

	side = getTextureUVCoordinateSet("furnace", 2);
	top = getTextureUVCoordinateSet("furnace", 3);
}

const TextureUVCoordinateSet& DispenseableBlock::getTexture(signed char, int) {
	return (side == 1 || side == 0)? top : (side == 2)? face : side;
}

bool DispenseableBlock::isRedstoneBlock() const {
	return true;
}

bool DispenseableBlock::isContainerBlock() const {
	return false;
}

void DispenseableBlock::onRedstoneUpdate(BlockSource& region, const BlockPos& pos, int strength, bool active) {
	if(active)
	{
		ItemInstance testStone = ItemInstance(1, 1, 0);
		dispenseAtLocation(getDispenseType(testStone), region, pos, testStone);
	}
}

void DispenseableBlock::destroy(BlockSource& region, const BlockPos& pos, int data, Entity* breaker) {

}

bool DispenseableBlock::use(Player& player, const BlockPos& pos) {
	return false;
}

int DispenseableBlock::getPlacementDataValue(Mob& placer, const BlockPos& pos, signed char side, const Vec3&, int) {
	return 0;
}

bool DispenseableBlock::dispenseAtLocation(DispenseableBlock::DispenseType type, BlockSource& region, const BlockPos& pos, const ItemInstance& itemStack) {

}