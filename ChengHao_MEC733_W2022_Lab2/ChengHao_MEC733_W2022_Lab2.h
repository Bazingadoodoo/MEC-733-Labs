#ifdef __ASSEMBLER__

  /* Assembler-only stuff */

#else

  /* C-stuff, define your assembly functions here */
    extern "C" void port_D_init(void);  
  
    extern "C" uint8_t port_D6_read(void); 
    extern "C" uint8_t port_D7_read(void);
    
    extern "C" void port_D2_high(void); 
    extern "C" void port_D2_low(void); 
    extern "C" void port_D3_high(void); 
    extern "C" void port_D3_low(void); 

#endif
