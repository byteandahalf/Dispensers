#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>

#include "world/level/block/DispenserBlock.h"

void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	Block::mBlocks[23] = (new DispenserBlock(23))->init();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	return JNI_VERSION_1_2;
}
