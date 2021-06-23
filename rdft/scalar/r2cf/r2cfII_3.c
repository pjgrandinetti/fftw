/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu Dec 10 07:06:02 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4 -pipeline-latency 4 -n 3 -name r2cfII_3 -dft-II -include r2cfII.h */

/*
 * This function contains 4 FP additions, 2 FP multiplications,
 * (or, 3 additions, 1 multiplications, 1 fused multiply/add),
 * 7 stack variables, 2 constants, and 6 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_3(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(12, rs), MAKE_VOLATILE_STRIDE(12, csr), MAKE_VOLATILE_STRIDE(12, csi)) {
	       E T3, T1, T2, T4;
	       T3 = R0[0];
	       T1 = R1[0];
	       T2 = R0[WS(rs, 1)];
	       T4 = T2 - T1;
	       Ci[0] = -(KP866025403 * (T1 + T2));
	       Cr[0] = FNMS(KP500000000, T4, T3);
	       Cr[WS(csr, 1)] = T3 + T4;
	  }
     }
}

static const kr2c_desc desc = { 3, "r2cfII_3", { 3, 1, 1, 0 }, &GENUS };

void X(codelet_r2cfII_3) (planner *p) { X(kr2c_register) (p, r2cfII_3, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 3 -name r2cfII_3 -dft-II -include r2cfII.h */

/*
 * This function contains 4 FP additions, 2 FP multiplications,
 * (or, 3 additions, 1 multiplications, 1 fused multiply/add),
 * 7 stack variables, 2 constants, and 6 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_3(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(12, rs), MAKE_VOLATILE_STRIDE(12, csr), MAKE_VOLATILE_STRIDE(12, csi)) {
	       E T1, T2, T3, T4;
	       T1 = R0[0];
	       T2 = R1[0];
	       T3 = R0[WS(rs, 1)];
	       T4 = T2 - T3;
	       Cr[WS(csr, 1)] = T1 - T4;
	       Ci[0] = -(KP866025403 * (T2 + T3));
	       Cr[0] = FMA(KP500000000, T4, T1);
	  }
     }
}

static const kr2c_desc desc = { 3, "r2cfII_3", { 3, 1, 1, 0 }, &GENUS };

void X(codelet_r2cfII_3) (planner *p) { X(kr2c_register) (p, r2cfII_3, &desc);
}

#endif
