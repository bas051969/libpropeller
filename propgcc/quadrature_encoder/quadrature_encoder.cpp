//
// automatically generated by spin2cpp v1.05 on Mon Jul 29 16:31:25 2013
// spin2cpp quadrature_encoder.spin 
//

#include <propeller.h>
#include "quadrature_encoder.h"

#ifdef __GNUC__
#define INLINE__ static inline
#define PostEffect__(X, Y) __extension__({ int32_t tmp__ = (X); (X) = (Y); tmp__; })
#else
#define INLINE__ static
static int32_t tmp__;
#define PostEffect__(X, Y) (tmp__ = (X), (X) = (Y), tmp__)
#endif


extern char _load_start_quadrature_encoder_cog[];


uint8_t quadrature_encoder::dat[] = {
  0x20, 0x60, 0x7c, 0x61, 0x01, 0x24, 0xfc, 0x70, 0x3a, 0x70, 0xfc, 0xa0, 0x38, 0x0a, 0xbc, 0x54, 
  0x31, 0x64, 0xbc, 0xa0, 0x00, 0x00, 0xfc, 0xa0, 0x01, 0x70, 0xfc, 0x80, 0x38, 0x0a, 0xbc, 0x54, 
  0x05, 0x64, 0xfc, 0xe4, 0xf2, 0x69, 0xbc, 0xa0, 0x30, 0x68, 0xbc, 0x28, 0x3a, 0x70, 0xfc, 0xa0, 
  0x38, 0x4a, 0xbc, 0x54, 0x38, 0x4c, 0xbc, 0x54, 0xf0, 0x73, 0xbc, 0xa0, 0x34, 0x66, 0xbc, 0xa0, 
  0x34, 0x6a, 0xbc, 0xa0, 0x01, 0x6a, 0xfc, 0x2c, 0xf3, 0x69, 0xbc, 0xa0, 0x30, 0x68, 0xbc, 0x28, 
  0x34, 0x66, 0xbc, 0x6c, 0x34, 0x6a, 0xbc, 0x6c, 0x2e, 0x6a, 0xbc, 0x60, 0x2d, 0x6a, 0xbc, 0x68, 
  0x33, 0x6c, 0xbc, 0xa0, 0x2d, 0x6c, 0xbc, 0x60, 0x2e, 0x66, 0xbc, 0x60, 0x01, 0x66, 0xfc, 0x28, 
  0x33, 0x6c, 0xbc, 0x6c, 0x36, 0x66, 0xbc, 0xa0, 0x01, 0x66, 0xfc, 0x2c, 0x36, 0x66, 0xbc, 0x68, 
  0x35, 0x66, 0xbc, 0x60, 0x31, 0x64, 0xbc, 0xa0, 0x02, 0x66, 0xfc, 0x20, 0x33, 0x6e, 0xbc, 0xa0, 
  0x1e, 0x6e, 0xfc, 0x38, 0x37, 0x00, 0xbc, 0x80, 0x39, 0x00, 0x3c, 0x08, 0x01, 0x70, 0xfc, 0x80, 
  0x38, 0x4a, 0xbc, 0x54, 0x38, 0x4c, 0xbc, 0x54, 0x04, 0x72, 0xfc, 0x80, 0x22, 0x64, 0xfc, 0xe4, 
  0x0b, 0x00, 0x7c, 0x5c, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


int32_t quadrature_encoder::Start(int32_t Startpin, int32_t Numenc, int32_t Numdelta, int32_t Posaddr)
{
   volatile void * asm_reference = NULL;
    __asm__ volatile ( "mov %[asm_reference], #QuadratureEncoder_Entry \n\t"
            : [asm_reference] "+r" (asm_reference));
 
    
    
  int32_t Pass = 0;

  
  Totdelta = Numdelta;
  Pos = Posaddr;
  
  NumberOfEncoders = Numenc;
  Pin = Startpin;
  
  Stop();
 
  Cog = cognew(_load_start_quadrature_encoder_cog, &Pos) + 1;
  
  
  /*
  ((int32_t *)&dat[192])[0] = Startpin;
  ((int32_t *)&dat[196])[0] = Numenc;
  Totdelta = Numdelta;
  Pos = Posaddr;
  Stop();
  { int32_t _fill__0000; int32_t *_ptr__0002 = (int32_t *)Pos; int32_t _val__0001 = 0; for (_fill__0000 = ((*(int32_t *)&dat[196]) + Totdelta); _fill__0000 > 0; --_fill__0000) {  *_ptr__0002++ = _val__0001; } };
  Pass = -((Cog = (cognew((int32_t)(&(*(int32_t *)&dat[0])), Pos) + 1)) > 0);
  */
  
  return Cog;
}

int32_t quadrature_encoder::Stop(void)
{
  if (Cog > 0) {
    cogstop((Cog - 1));
  }
  return 0;
}



/*
 // This function is untested!
int32_t quadrature_encoder::Readdelta(int32_t Encid)
{
  int32_t Deltapos = 0;
  Deltapos = ((0 + ((Encid < Totdelta) * (-((int32_t *)Pos)[((*(int32_t *)&dat[196]) + Encid)]))) + (((int32_t *)Pos)[((*(int32_t *)&dat[196]) + Encid)] = ((int32_t *)Pos)[Encid]));
  return Deltapos;
}
 */

