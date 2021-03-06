#ifndef _ACF_PROCESS_APU_FIRE8_E1E3S1_NATIVE_KERNEL_WRAPPER
#define _ACF_PROCESS_APU_FIRE8_E1E3S1_NATIVE_KERNEL_WRAPPER

#include <FIRE8_E1E3S1.hpp>

//structure encapsulating the information ACF requires for each I/O
typedef struct _acf_io_info {                                      
    int32_t      pBuf;   //CL framework will initialize this with a pointer to global memory (based on associated cl_mem entity)
    int32_t      width;  //width in unit of elements
    int32_t      height; //height in unit of elements
    int32_t      span;   //(2D only) the number of bytes required to jump from one line of bytes in memory to the 'next' line of bytes in memory
    icp::DATATYPE elementDataType; //element data type (icp::DATATYPE_08U, icp::DATATYPE_16S, etc.
    int32_t      elementDimX;     //element X dimension
    int32_t      elementDimY;     //element Y dimension
} acf_io_info;

/******************************************************
pArgs must point to an array with the following format:

acf_io_info MYKERNEL_args[4];

where:
   [0] corresponds to input 'FIRE8_E1E3S1_INPUT_IMAGE'
   [1] corresponds to input 'FIRE8_E1E3S1_INPUT_WEIGHT'
   [2] corresponds to input 'FIRE8_E1E3S1_INPUT_PARAMS'
   [3] corresponds to output 'FIRE8_E1E3S1_OUTPUT_S1'

and 'pArgs = (void*)MYKERNEL_args;'
******************************************************/

static void FIRE8_E1E3S1_nativekernel(void* pArgs)
{
   acf_io_info* lpIo = 0;

   //FIRE8_E1E3S1_INPUT_IMAGE
   ACF_DataDesc FIRE8_E1E3S1_INPUT_IMAGE;
   lpIo = (acf_io_info*)((int32_t)pArgs+0*sizeof(acf_io_info));
   FIRE8_E1E3S1_INPUT_IMAGE.Init2D(0, (void*)lpIo->pBuf, lpIo->nd_size.width, lpIo->nd_size.height, lpIo->nd_span.height, lpIo->elementDataType, lpIo->elementDimX, lpIo->elementDimY);

   //FIRE8_E1E3S1_INPUT_WEIGHT
   ACF_DataDesc FIRE8_E1E3S1_INPUT_WEIGHT;
   lpIo = (acf_io_info*)((int32_t)pArgs+1*sizeof(acf_io_info));
   FIRE8_E1E3S1_INPUT_WEIGHT.Init2D(0, (void*)lpIo->pBuf, lpIo->nd_size.width, lpIo->nd_size.height, lpIo->nd_span.height, lpIo->elementDataType, lpIo->elementDimX, lpIo->elementDimY);

   //FIRE8_E1E3S1_INPUT_PARAMS
   ACF_DataDesc FIRE8_E1E3S1_INPUT_PARAMS;
   lpIo = (acf_io_info*)((int32_t)pArgs+2*sizeof(acf_io_info));
   FIRE8_E1E3S1_INPUT_PARAMS.Init2D(0, (void*)lpIo->pBuf, lpIo->nd_size.width, lpIo->nd_size.height, lpIo->nd_span.height, lpIo->elementDataType, lpIo->elementDimX, lpIo->elementDimY);

   //FIRE8_E1E3S1_OUTPUT_S1
   ACF_DataDesc FIRE8_E1E3S1_OUTPUT_S1;
   lpIo = (acf_io_info*)((int32_t)pArgs+3*sizeof(acf_io_info));
   FIRE8_E1E3S1_OUTPUT_S1.Init2D(0, (void*)lpIo->pBuf, lpIo->nd_size.width, lpIo->nd_size.height, lpIo->nd_span.height, lpIo->elementDataType, lpIo->elementDimX, lpIo->elementDimY);

   FIRE8_E1E3S1 lProcess;
   lProcess.Initialize();
   lProcess.ConnectIO("FIRE8_E1E3S1_INPUT_IMAGE", FIRE8_E1E3S1_INPUT_IMAGE);
   lProcess.ConnectIO("FIRE8_E1E3S1_INPUT_WEIGHT", FIRE8_E1E3S1_INPUT_WEIGHT);
   lProcess.ConnectIO("FIRE8_E1E3S1_INPUT_PARAMS", FIRE8_E1E3S1_INPUT_PARAMS);
   lProcess.ConnectIO("FIRE8_E1E3S1_OUTPUT_S1", FIRE8_E1E3S1_OUTPUT_S1);
   lProcess.Start();
   lProcess.Wait();
}

#endif //_ACF_PROCESS_APU_FIRE8_E1E3S1_NATIVE_KERNEL_WRAPPER
