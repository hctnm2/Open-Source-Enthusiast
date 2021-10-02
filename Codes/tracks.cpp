#include<iostream>
using namespace std;

int main()
{
    //calculate cy head and sector from tracksPerSurface, sectorsPerSurface, noOfSurfaces and sector size
    int tracksSurface=8;
    int sectorsPerTrack=32;
    int surfaces=16;
    int blocksPerTrack=sectorsPerTrack*surfaces;
    int sectorSize=512;
    int totalBlocks=blocksPerTrack*tracksSurface;
    int sectors=surfaces*tracksSurface*sectorsPerTrack;
    int totalSize=totalBlocks*sectorSize;

    int block=2216;
    int cy=block/blocksPerTrack;
    int head=(block-cy*blocksPerTrack)/sectorsPerTrack;
    int sector=(block-(cy*surfaces+head)*sectorsPerTrack)+1;


    std::cout << "cy="<<cy << std::endl;
    std::cout << "head="<<head << std::endl;
    std::cout << "sector"<<sector << std::endl;
    
    //calculate the block number from cy, head and sector
    
    int cygiven=cy;
    int headgiven=head;
    int sectorgiven=sector;
    
    int blocktobefound=(cygiven*surfaces+head)*sectorsPerTrack+(sectorgiven-1);
    std::cout << "block="<<blocktobefound << std::endl;


}