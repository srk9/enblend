/*
 * Copyright (C) 2004 Andrew Mihal
 *
 * This file is part of Enblend.
 *
 * Enblend is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * Enblend is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Enblend; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __ENBLEND_H__
#define __ENBLEND_H__

#include <tiffio.h>
#include <list>
#include <vector>

typedef struct {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
} MaskPixel;

typedef struct {
    int16 r;
    int16 g;
    int16 b;
    int16 a;
} LPPixel;

// assemble.cc
uint32 *assemble(std::list<char*> &filenames);

// blend.cc
void blend(std::vector<LPPixel*> &whiteLP,
        std::vector<LPPixel*> &blackLP,
        std::vector<LPPixel*> &maskGP);

// mask.cc
MaskPixel *createMask(uint32 *whiteImage, uint32 *blackImage);

// pyramid.cc
std::vector<LPPixel*> *gaussianPyramid(MaskPixel *image, uint32 levels);
std::vector<LPPixel*> *gaussianPyramid(uint32 *image, uint32 levels);
std::vector<LPPixel*> *laplacianPyramid(uint32 *image, uint32 levels);
void collapsePyramid(std::vector<LPPixel*> &p, uint32 *dest, MaskPixel *mask);

// thin.cc
void thinMask(MaskPixel *mask);

#endif /* __ENBLEND_H__ */
