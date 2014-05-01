#ifndef __VBE_H
#define __VBE_H
#include <x86.h>
//! structs for use.
struct VBEInfoBlock {
   BYTE VbeSignature[4];             	// == "VESA"
   WORD VbeVersion;                 // == 0x0300 for VBE 3.0
   WORD OemStringPtr[2];            // isa vbeFarPtr
   BYTE Capabilities[4];
   WORD VideoModePtr[2];         	// isa vbeFarPtr
   WORD TotalMemory;             	// as # of 64KB blocks
};
struct VBEModeInfoBlock
{
// Mandatory information for all VBE revisions
   WORD ModeAttributes;
   BYTE  WinAAttributes;
   BYTE  WinBAttributes;
   WORD WinGranularity;
   WORD WinSize;
   WORD WinASegment;
   WORD WinBSegment;
   DWORD WinFuncPtr;
   WORD BytesPerScanLine;
// Mandatory information for VBE 1.2 and above
   WORD XResolution;
   WORD YResolution;
   BYTE  XCharSize;
   BYTE  YCharSize;
   BYTE  NumberOfPlanes;
   BYTE  BitsPerPixel;
   BYTE  NumberOfBanks;
   BYTE  MemoryModel;
   BYTE  BankSize;
   BYTE  NumberOfImagePages;
   BYTE  Reserved_page;
// Direct Color fields (required for direct/6 and YUV/7 memory models)
   BYTE  RedMaskSize;
   BYTE  RedFieldPosition;
   BYTE  GreenMaskSize;
   BYTE  GreenFieldPosition;
   BYTE  BlueMaskSize;
   BYTE  BlueFieldPosition;
   BYTE  RsvdMaskSize;
   BYTE  RsvdFieldPosition;
   BYTE  DirectColorModeInfo;
// Mandatory information for VBE 2.0 and above
   DWORD PhysBasePtr;
   DWORD OffScreenMemOffset;
   WORD OffScreenMemSize;
// Mandatory information for VBE 3.0 and above
   WORD LinBytesPerScanLine;
   BYTE  BnkNumberOfPages;
   BYTE  LinNumberOfPages;
   BYTE  LinRedMaskSize;
   BYTE  LinRedFieldPosition;
   BYTE  LinGreenMaskSize;
   BYTE  LinGreenFieldPosition;
   BYTE  LinBlueMaskSize;
   BYTE  LinBlueFieldPosition;
   BYTE  LinRsvdMaskSize;
   BYTE  LinRsvdFieldPosition;
   DWORD MaxPixelClock;
   BYTE  Reserved[189];
};
typedef struct VBEInfoBlock VBEInfoBlock_t;
typedef struct VBEModeInfoBlock VBEModeInfoBlock_t;
#include <vbe/vbe.c>
#endif