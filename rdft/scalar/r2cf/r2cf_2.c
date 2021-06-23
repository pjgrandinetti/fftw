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
/* Generated on Thu Dec 10 07:05:49 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4 -pipeline-latency 4 -n 2 -name r2cf_2 -include r2cf.h */

/*
 * This function contains 2 FP additions, 0 FP multiplications,
 * (or, 2 additions, 0 multiplications, 0 fused multiply/add),
 * 3 stack variables, 0 constants, and 4 memory accesses
 */
#include "r2cf.h"

static void r2cf_2(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(8, rs), MAKE_VOLATILE_STRIDE(8, csr), MAKE_VOLATILE_STRIDE(8, csi)) {
	       E T1, T2;
	       T1 = R0[0];
	       T2 = R1[0];
	       Cr[WS(csr, 1)] = T1 - T2;
	       Cr[0] = T1 + T2;
	  }
     }
}

static const kr2c_desc desc = { 2, "r2cf_2", { 2, 0, 0, 0 }, &GENUS };

void X(codelet_r2cf_2) (planner *p) { X(kr2c_register) (p, r2cf_2, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 2 -name r2cf_2 -include r2cf.h */

/*
 * This function contains 2 FP additions, 0 FP multiplications,
 * (or, 2 additions, 0 multiplications, 0 fused multiply/add),
 * 3 stack variables, 0 constants, and 4 memory accesses
 */
#include "r2cf.h"

static void r2cf_2(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(8, rs), MAKE_VOLATILE_STRIDE(8, csr), MAKE_VOLATILE_STRIDE(8, csi)) {
	       E T1, T2;
	       T1 = R0[0];
	       T2 = R1[0];
	       Cr[WS(csr, 1)] = T1 - T2;
	       Cr[0] = T1 + T2;
	  }
     }
}

static const kr2c_desc desc = { 2, "r2cf_2", { 2, 0, 0, 0 }, &GENUS };

void X(codelet_r2cf_2) (planner *p) { X(kr2c_register) (p, r2cf_2, &desc);
}

#endif
