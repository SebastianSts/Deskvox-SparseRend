// Virvo - Virtual Reality Volume Rendering
// Contact: Stefan Zellmann, zellmans@uni-koeln.de
//
// This file is part of Virvo.
//
// Virvo is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

#ifndef _VV_RENDERTARGET_H_
#define _VV_RENDERTARGET_H_

#include "vvexport.h"
#include "vvopengl.h"

enum BufferPrecision
{
  VV_BYTE = 0,   ///< 8 bit
  VV_SHORT,      ///< 16 bit
  VV_FLOAT       ///< 32 bit
};

enum RenderTargetType
{
  VV_OFFSCREEN_BUFFER = 0,
  VV_PBUFFER,
  VV_RENDER_TARGET
};

class VIRVOEXPORT vvRenderTarget
{
public:
  vvRenderTarget();
  virtual ~vvRenderTarget();

  virtual void initForRender();
  virtual void writeBack(int w = -1, int h = -1);
  virtual void resize(int w, int h);
  virtual void clearBuffer();

  inline RenderTargetType getType() const { return _type; }
protected:
  RenderTargetType _type;
};

#endif // _VV_RENDERTARGET_H_