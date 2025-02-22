/*
 *      Copyright (C) 2005-2009 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#pragma once

#if defined(HAS_INTEL_SMD)

#include "IntelSMDVideo.h"
#include "DVDVideoCodec.h"

class CDVDVideoCodecSMD : public CDVDVideoCodec
{
public:
  CDVDVideoCodecSMD();
  virtual ~CDVDVideoCodecSMD();

  // Required overrides
  virtual bool Open(CDVDStreamInfo &hints, CDVDCodecOptions &options);
  virtual void Dispose(void);
  virtual int  Decode(uint8_t *pData, int iSize, double pts, double dts);
  virtual void Reset(void);
  virtual bool GetPicture(DVDVideoPicture *pDvdVideoPicture);
  virtual bool ClearPicture(DVDVideoPicture *pDvdVideoPicture);
  virtual void SetDropState(bool bDrop) {}
  virtual void SetSpeed(int iSpeed);
  virtual const char* GetName(void) { return (const char*)m_pFormatName; }

protected:
  CIntelSMDVideo*       m_Device;
  const char*           m_pFormatName;
};

#endif
