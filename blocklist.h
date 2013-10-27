#ifndef _BLOCKLIST_H
#define _BLOCKLIST_H

#include <ctime>

class Block {
public:
	Block(int s = 0, double d = 3) {
		strip = s;
		d_block = d;
		c_offset_base = (rand() % 600 + 1);
		c_offset = fabs(sin(c_offset_base));
	}
	int strip;
	double d_block;
	double c_offset;
	double c_offset_base;
};



class BlockList {
	double dist_per_msec;
public:
	long prev_time;
	std::list<Block> blocks;
	BlockList(double _dist_per_msec = 0.008) {
		dist_per_msec = _dist_per_msec;
		prev_time = 0;
	}
	void add(Block b) {
		blocks.push_back(b);
	}
	void shift() {
		long c_time = glutGet(GLUT_ELAPSED_TIME);
		long elapsed_time = c_time - prev_time;
		for(std::list<Block>::iterator i = blocks.begin(); i != blocks.end(); ++i) {
			(*i).d_block -= dist_per_msec * elapsed_time;
			(*i).c_offset = fabs(sin((c_time + (*i).c_offset_base)/600.0));
		}
		for(std::list<Block>::iterator i = blocks.begin(); i != blocks.end(); ++i) {
			if((*i).d_block <= 0.0) {
				blocks.erase(i);
				i = blocks.begin();
			}
		}
		prev_time = c_time;
	}
};

void BlockTypeA(BlockList& blocklist, int distance, int n_gon = 6) {
	blocklist.add(Block(rand() % n_gon, distance));
}
void BlockTypeB(BlockList& blocklist, int distance, int n_gon = 6) {
	blocklist.add(Block(rand() % n_gon, distance + (rand()%10)/5.0));
}
void BlockTypeC(BlockList& blocklist, int distance, int hole, int n_gon = 6) {
	for(int i = 0; i < n_gon; ++i)
		if(i!=hole)
			blocklist.add(Block(i, distance));
}
void BlockTypeS(BlockList& blocklist, int distance, int n_gon = 6) {
	for(int i = 0; i < 20; ++i) {
			blocklist.add(Block(i%n_gon, distance + i*0.75));
	}
}

#endif
