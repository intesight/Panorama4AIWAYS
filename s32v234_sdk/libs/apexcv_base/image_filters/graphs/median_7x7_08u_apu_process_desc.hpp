/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2013-2018 Freescale Semiconductor
* Copyright 2018 NXP 
* All Rights Reserved
*
******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************/
  
/*!*********************************************************************************
*  @file median_7x7_08u_proc_desc.hpp
*  @brief Process description for median 7x7 filter (unsigned 8 bit)
***********************************************************************************/
 
#ifndef MEDIAN7X708UAPUPROCESSDESC_HPP
#define MEDIAN7X708UAPUPROCESSDESC_HPP

#include <acf_process_desc_apu.hpp>
#include "median_7x7_08u_graph.hpp"

class median_7x7_08u_apu_process_desc : public ACF_Process_Desc_APU
{
public:
   void Create()
   {
      Initialize(mGraph, "MEDIAN_7X7_08U");
   }
   
   median_7x7_08u_graph mGraph;
};

#endif /* MEDIAN7X708UAPUPROCESSDESC_HPP */
