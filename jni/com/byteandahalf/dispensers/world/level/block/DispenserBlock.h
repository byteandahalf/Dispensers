#pragma once

#include "DispenseableBlock.h"

class DispenserBlock : public DispenseableBlock
{
	DispenserBlock(int);

	virtual DispenseableBlock::DispenseType getDispenseType(const ItemInstance&);
};
